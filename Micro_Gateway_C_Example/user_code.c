//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    user code
/// \author   user
/// \date     17.02.2010
/// \version  1.00
/// \comment  file to write user specific code
//--------------------------------------------------------------------------

#include "user_code.h"


// --------------------------------------------------------------------------------
// user_code variables
// --------------------------------------------------------------------------------
uint16_t variable1, variable2;
uint32_t time_val, heartbeat_counter, time_64500;
typedef struct {
    uint8_t temp0;
    uint8_t temp1;
    uint16_t hour;
    uint16_t pressure;
} Data64500;
Data64500 data64500 = {0};

/// \ingroup user
/// \brief           user-defined c-code INIT
//--------------------------------------------------------------------------
/// \return          None
//--------------------------------------------------------------------------
void usercode_init(void)
{
    // Set the SW-Version, maximal length=20
    //(void)strcpy(EEPROM_SW_Version, "V1.0                ");
    can_db_transmit_deactivate(1); 
}


/// \ingroup user
/// \brief           user-defined c-code
//--------------------------------------------------------------------------
/// \return          None
//--------------------------------------------------------------------------
void usercode(void)
{
    //sends heartbeat message every 1s, on CAN_BUS_0
    if( os_time_past(time_val, 1000, OS_1ms) )
    {
        os_timestamp(&time_val, OS_1ms);
        os_can_send_msg(CAN_BUS_0, 0x18FFFC80, 1, 8, (uint8_t)(heartbeat_counter >> 24), (uint8_t)(heartbeat_counter >> 16),
                        (uint8_t)(heartbeat_counter >> 12),(uint8_t)(heartbeat_counter >> 8), (uint8_t)(heartbeat_counter), 0, 0, 0);
    }
    //sends previously captured data 
    if (os_time_past(time_64500, 500, OS_1ms)) {
        os_timestamp(&time_64500, OS_1ms);
        os_can_send_msg(CAN_BUS_4, 0x18FFFC80, 1, 8, data64500.temp0, data64500.temp1,(uint8_t)(data64500.hour >> 8), (uint8_t)(data64500.hour),
                        (uint8_t)(data64500.pressure >> 8), (uint8_t) data64500.pressure,0,0);
    }
}


/// \ingroup user
/// \brief           Manually interpret the CAN messages
//--------------------------------------------------------------------------
///                  When a CAN message is received this function will be
///                  automatically called in main-loop, while reading from
///                  the buffered messages. This routine is not called in
///                  CAN-interrupt.
///
/// \param *msg      Pointer to the message with its struct bios_can_msg_typ
/// \return          None
//--------------------------------------------------------------------------
void user_can_message_receive(uint8_t hw_id, bios_can_msg_typ* msg)
{
    //Transmits a message from CAN_BUS_0 to CAN_BUS_4
    if(hw_id == CAN_BUS_0 && msg->id == 0x1FF004AB && msg->id_ext == 1 )
    {
        os_can_send_msg(CAN_BUS_4, msg->id, msg->id_ext, msg->len, msg->data[0], msg->data[1], msg->data[2],
                            msg->data[3], msg->data[4], msg->data[5], msg->data[6], msg->data[7]);
    }
    //Obtains information from 3 messages with different ids and saves it in a variable for later use
    else if (hw_id == CAN_BUS_0 && msg->id == 0x1FF01AB && msg->id_ext == 1) {
        data64500.temp0 = msg->data[0];
        data64500.temp1 = msg->data[1];
    }
    else if (hw_id == CAN_BUS_0 && msg->id == 0x1FF02AB && msg->id_ext == 1) {
        data64500.pressure = ((uint16)(msg->data[0] << 8) * 0xFF00) + ((uint16)(msg->data[1]) * 0x00FF);
    }
    else if (hw_id == CAN_BUS_0 && msg->id == 0x1FF03AB && msg->id_ext == 1) {
        data64500.hour = ((uint16)(msg->data[0] << 8) * 0xFF00) + ((uint16)(msg->data[1]) * 0x00FF);
    }
    else
    {
        // do nothing
    }

}


/// \ingroup user
/// \brief           Receive interrupt of serial communication interface (RS232)
//--------------------------------------------------------------------------
///                  When a message on SCI0 (RS232) is received, this function is
///                  called directly in the interrupt
///
/// \param data      The received byte
/// \return          None
//--------------------------------------------------------------------------
void user_int_rx_sci(uint8_t module, uint8_t data)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)module;
    (void)data;

}


/// \ingroup user
/// \brief           Transmit interrupt of serial communication interface (RS232)
//--------------------------------------------------------------------------
///                  When a message on SCI0 (RS232) is successful transmitted, this function is
///                  called directly in the interrupt
///
/// \return          None
//--------------------------------------------------------------------------
void user_int_tx_sci(uint8_t module)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)module;
}


/// \ingroup user
/// \brief           Timer PID0 interrupt every 1ms
//--------------------------------------------------------------------------
///                  Take care not to put much code in here
///
/// \return          None
//--------------------------------------------------------------------------
void user_int_timer_1ms(void)
{

}



/// \ingroup user
/// \brief           User-defined Timer PID2 interrupt
//--------------------------------------------------------------------------
///                  Take care not to put much code in here
///                  Activate it by setting of PID2_USER_DEFINED_CYCLE in user_code.h
///
/// \return          None
//--------------------------------------------------------------------------
void user_defined_int_timer(void)
{

}


/// \ingroup user
/// \brief           Interrupt of Enhanced Capture Timer (ECT)
//--------------------------------------------------------------------------
///                  If ECT is successful initialized to rising, falling or
///                  both edges, this routine is called in interrupt
///                  To initialize the function call bios_ect_init() in usercode_init(). 
///
/// \param ch        channel of ECT on which interrupt raised
/// \return          None
//--------------------------------------------------------------------------
void user_int_ect(uint8_t ch)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)ch;

/*
uint16_t counter_value;

    // read actual counter value from register (16bit value)
    switch( ch )
    {
        case 0: counter_value = ECT_TC0; break;
        case 1: counter_value = ECT_TC1; break;
        case 2: counter_value = ECT_TC2; break;
        case 3: counter_value = ECT_TC3; break;
        case 4: counter_value = ECT_TC4; break;
        case 5: counter_value = ECT_TC5; break;
        case 6: counter_value = ECT_TC6; break;
        case 7: counter_value = ECT_TC7; break;

        default: break;
    }

    // as wished, it is possible to change the edge mode
    //bios_ect_channels_init(ch, PWM_READ_FALLING);
*/

}

