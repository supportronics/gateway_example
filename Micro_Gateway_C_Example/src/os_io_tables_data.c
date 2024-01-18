







#include "os_io_tables_data.h"
#include "bios_base.h"
#include "user_code.h"
#include "os_sci.h"


const uint16_t os_pwm_duty_read_timeout = 1500;

os_port_int_def os_port_int_val[BIOS_NR_OF_INT_PORTS * 8];

uint8_t os_io_vals[OS_PORT_PIN_MAX / 8 + 1];
uint8_t os_io_prev_vals[OS_PORT_PIN_MAX / 8 + 1];
uint8_t os_io_vals_disable[OS_PORT_PIN_MAX / 8 + 1];

uint8_t os_pin_entprell_cnt[OS_PORT_PIN_MAX + 1];

uint8_t os_analog_io_vals_err[OS_ANALOG_PIN_MAX + 1];
uint8_t os_analog_io_vals_entprell_cnt[OS_ANALOG_PIN_MAX + 1];
uint8_t os_analog_io_vals_disable[OS_ANALOG_PIN_MAX + 1];
uint16_t os_analog_io_vals[OS_ANALOG_PIN_MAX + 1];                      
uint16_t os_analog_io_vals_kal[OS_ANALOG_PIN_MAX + 1];                  

uint8_t os_pwm_analog_cal_deactivate;

os_pwm_vals_def os_pwm_vals[OS_PWM_PIN_MAX + 1];
os_pwm_control_vals_def os_pwm_control_vals[OS_PWM_PIN_MAX + 1];

uint8_t os_analog_io_sum_cnt[OS_ANALOG_PIN_MAX + 1];
uint8_t os_analog_io_sum_cnt_max[OS_ANALOG_PIN_MAX + 1];
uint8_t os_analog_io_pwm_index[OS_ANALOG_PIN_MAX + 1];
uint8_t os_analog_io_pwm_start_index;
uint32_t os_analog_io_sum[OS_ANALOG_PIN_MAX + 1];
uint32_t os_analog_io_sum_buffer[OS_ANALOG_PIN_MAX+1];

extern uint8_t adc_auto_disable;
extern os_pwm_duty_read_def os_pwm_duty_read[];

os_pwm_duty_read_def os_pwm_duty_read[PWM_DUTY_READ_MAX]; 

uint8_t spi_module_no;


#ifdef HSDDATENSATZ_SIZE_MASTER
    #undef  HSDDATENSATZ_SIZE
    #define HSDDATENSATZ_SIZE HSDDATENSATZ_SIZE_MASTER
#elif defined HSDDATENSATZ_SIZE_DYNAMIC
    #undef  HSDDATENSATZ_SIZE
    #define HSDDATENSATZ_SIZE HSDDATENSATZ_SIZE_DYNAMIC
#endif

#ifdef USER_VARIABLE_SIZE_MASTER
    #undef  USER_VARIABLE_SIZE
    #define USER_VARIABLE_SIZE USER_VARIABLE_SIZE_MASTER
#elif defined USER_VARIABLE_SIZE_DYNAMIC
    #undef  USER_VARIABLE_SIZE
    #define USER_VARIABLE_SIZE USER_VARIABLE_SIZE_DYNAMIC
#endif


uint32_t user_variable[USER_VARIABLE_SIZE];
uint16_t eeprom_hsddaten[HSDDATENSATZ_SIZE];
uint16_t eeprom_hsddaten_type;
uint16_t eeprom_userdaten[USERDATENSATZ_SIZE];  

uint8_t dyn_USERDATENSATZ_SIZE;
uint8_t dyn_USER_VARIABLE_SIZE;
uint8_t dyn_HSDDATENSATZ_SIZE;

uint8_t dyn_M2600_ACTIVATE_RS232_RX_INTERRUPT;

uint16_t dyn_PID2_USER_DEFINED_CYCLE;

type_sci_tx_buffer ext_dyn_sci_tx_buffer;

os_io_typ os_io;


void os_io_tables_data_init(void)
{
    uint8_t row_counter = 0;
    uint8_t i = 0;

    os_io.PORT_INPUT_PIN_MAX    = OS_PORT_INPUT_PIN_MAX;
    os_io.PORT_PIN_MAX          = OS_PORT_PIN_MAX;
    os_io.ANALOG_PIN_MAX        = OS_ANALOG_PIN_MAX;
    os_io.PWM_PIN_MAX           = OS_PWM_PIN_MAX;
    os_io.PORT_BIOS_NR          = BIOS_NR_OF_PORTS;

    dyn_USERDATENSATZ_SIZE = USERDATENSATZ_SIZE;
    dyn_USER_VARIABLE_SIZE = USER_VARIABLE_SIZE;
    dyn_HSDDATENSATZ_SIZE  = HSDDATENSATZ_SIZE;

    while( os_port_pin[row_counter].name <= os_io.PORT_PIN_MAX )
    {
        if( os_port_pin[row_counter++].value == MAGIC_NUMBER_WDI )
        {
            break;
        }
        else
        {
        }
    }

    row_counter--;
    if( row_counter < os_io.PORT_PIN_MAX )
    {
        os_io.WDI_DEFINED = 1;
        os_io.WDI_INDEX = (uint8_t)os_port_pin[row_counter].name;
        os_io.WDI_PORT = 0;
        os_io.WDI_BIT_MASK = 0;
    }
    else
    {
        os_io.WDI_DEFINED = 0;
        os_io.WDI_INDEX = 0;
        os_io.WDI_PORT = &PORTK;
        os_io.WDI_BIT_MASK = 0x20;
    }


    #ifdef ADC_AUTO_DISABLE

        adc_auto_disable = 1;

    #else

        adc_auto_disable = 0;

    #endif


    for( row_counter = 0; row_counter < PWM_DUTY_READ_MAX; row_counter++ )
    {
        os_pwm_duty_read[row_counter].active = 0;
    }

    #ifdef PWM_DUTYCYCLE_READ_ACTIVE

        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].active = 1;
        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].init_freq = PWM_DUTYCYCLE_READ_FREQ;
        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].init_res = PWM_DUTYCYCLE_READ_RES;

    #endif

    #ifdef M2600_ACTIVATE_RS232_RX_INTERRUPT

        dyn_M2600_ACTIVATE_RS232_RX_INTERRUPT = 1;

    #else

        dyn_M2600_ACTIVATE_RS232_RX_INTERRUPT = 0;

    #endif

#ifdef SCI_USER_ACTIVE
   ext_dyn_sci_tx_buffer.size = USER_BUFFER_SIZE;
   ext_dyn_sci_tx_buffer.sci_nr = SCI_NR;
   ext_dyn_sci_tx_buffer.parity = SCI_USER_PARITY;
   ext_dyn_sci_tx_buffer.data_bits_9 = SCI_USER_DATA_BITS_9;
   ext_dyn_sci_tx_buffer.baudrate_user_defined = 0;
   ext_dyn_sci_tx_buffer.baudrate = SCI_USER_BAUDRATE;

   #ifdef SCI_USER_DEFINED_BAUDRATE
       #if SCI_USER_DEFINED_BAUDRATE > 0
           ext_dyn_sci_tx_buffer.baudrate_user_defined = SCI_USER_DEFINED_BAUDRATE;
       #endif
   #endif


   #ifdef SCI_USER_FULL_DUPLEX
       ext_dyn_sci_tx_buffer.full_duplex = 1;
   #else
       ext_dyn_sci_tx_buffer.full_duplex = 0;
   #endif



   #ifdef SCI_NO_DELAY_AFTER_SEND
       ext_dyn_sci_tx_buffer.delay_after_send = DELAY_KENNER;
   #endif

 #endif


 #ifdef SCI_USER_RS485

   for (i=os_io.PORT_INPUT_PIN_MAX+1;i<os_io.PORT_PIN_MAX;i++)
   {
       if (os_port_pin[i].value == MAGIC_NUMBER_RS485_DE)
       {
           ext_dyn_sci_tx_buffer.rs485_de_pin = i;

           break;
       }
   }

 #endif
    #ifdef PID2_USER_DEFINED_CYCLE

        dyn_PID2_USER_DEFINED_CYCLE = PID2_USER_DEFINED_CYCLE;

    #else

        dyn_PID2_USER_DEFINED_CYCLE = 0;

    #endif

    return;
}


void os_modul_specific_init(void)
{
    lin_initialization();

    #if MACRO_MODUL_GERAETETYP_NR == TYPE_MGATEWAY

        #ifndef SCI_USER_BAUDRATE

            #define SCI_USER_BAUDRATE 0

        #endif

        #ifndef SCI_USER_DEFINED_BAUDRATE

            #define SCI_USER_DEFINED_BAUDRATE 0

        #endif

        bios_sci_module_init(0, SCI_USER_BAUDRATE, SCI_USER_DEFINED_BAUDRATE, BIOS_SCI_8N1);

        spi_module_no = MGATEWAY_SPI_NR;
        bios_spi_module_init(spi_module_no, BIOS_SPI_5M_BAUD, BIOS_SPI_MODE_0);

        os_specific_mgateway_init();

    #endif
}


void os_modul_specific_routines(void)
{

}



int16_t os_modul_specific_names(uint16_t name)
{
    switch (name)
    {
        #if MACRO_MODUL_GERAETETYP_NR == TYPE_M2600

            default:                        return 0;   

        #elif MACRO_MODUL_GERAETETYP_NR == TYPE_MGATEWAY

            case SPECIFIC_DO_GPIO0_0:       return DO_GPIO0_0;
            case SPECIFIC_DO_CAN2_TXD:      return DO_CAN2_TXD;
            case SPECIFIC_A_GPIO0_0:        return A_GPIO0_0;
            case SPECIFIC_DI_RS232_TXD3:    return DI_RS232_TXD3;
            case SPECIFIC_DI_SPI1_CS0:       return DI_SPI1_CS0;
            default:                        return -1;

        #else
            default:                        return -1;
        #endif
    }
}



void bios_timer_pwm_read_calc_first(uint8_t channel)
{
    #ifdef PWM_DUTYCYCLE_READ_ACTIVE

        if (bios_pwm_read[channel].active)
        {
            bios_timer_pwm_read_calc(channel);
        }
        else
        {
        }

    #endif

    #ifdef ECT_ACTIVE
    if(bios_ect_freq_read[channel].active)
    {
      bios_ect_freq_read[channel].counter++;    
    } 
    else
    {
    }  

      switch( channel )                       
      {
        uint16_t counter_value;
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
    #endif 

    user_int_ect(channel); 
}

void mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq,
                                    uint16_t duty_1,
                                    uint16_t duty_2,
                                    uint32_t ramp_up_time,
                                    uint32_t ramp_down_time,
                                    uint8_t rotation,
                                    uint8_t start_1,
                                    uint8_t start_2,
                                    uint16_t mode,
                                    uint8_t* status_1,
                                    uint8_t* status_2,
                                    uint16_t* curr_1,
                                    uint16_t* curr_2)
{
    #ifdef MOT_CTRL_1X_FULLBRIDGE_AKTIV

        modulhardwarecode_mot_ctrl_1x_fullbridge_block(pwm_freq,
                                                        duty_1,
                                                        duty_2,
                                                        ramp_up_time,
                                                        ramp_down_time,
                                                        rotation,
                                                        start_1,
                                                        start_2,
                                                        mode,
                                                        status_1,
                                                        status_2,
                                                        curr_1,
                                                        curr_2);
    #else
    (void) pwm_freq;
    (void) duty_1;
    (void) duty_2;
    (void) ramp_up_time;
    (void) ramp_down_time;
    (void) rotation;
    (void) start_1;
    (void) start_2;
    (void) mode;
    (void) status_1;
    (void) status_2;
    (void) curr_1;
    (void) curr_2;
    #endif
}

void mot_ctrl_4x_fullbridge_block(uint8_t enable,
                                    uint16_t pwm_freq,
                                    uint16_t duty_1,
                                    uint16_t duty_2,
                                    uint16_t duty_3,
                                    uint16_t duty_4,
                                    uint32_t up_time_1,
                                    uint32_t up_time_2,
                                    uint32_t up_time_3,
                                    uint32_t up_time_4,
                                    uint32_t dwn_time_1,
                                    uint32_t dwn_time_2,
                                    uint32_t dwn_time_3,
                                    uint32_t dwn_time_4,
                                    uint8_t dir_1,
                                    uint8_t dir_2,
                                    uint8_t dir_3,
                                    uint8_t dir_4,
                                    uint8_t start_1,
                                    uint8_t start_2,
                                    uint8_t start_3,
                                    uint8_t start_4,
                                    uint8_t* status_1,
                                    uint8_t* status_2,
                                    uint8_t* status_3,
                                    uint8_t* status_4,
                                    uint16_t* curr_1,
                                    uint16_t* curr_2,
                                    uint16_t* curr_3,
                                    uint16_t* curr_4)
{
    #ifdef MOT_CTRL_4X_FULLBRIDGE_AKTIV

        modulhardwarecode_mot_ctrl_4x_fullbridge_block(enable,
                                                        pwm_freq,
                                                        duty_1,
                                                        duty_2,
                                                        duty_3,
                                                        duty_4,
                                                        up_time_1,
                                                        up_time_2,
                                                        up_time_3,
                                                        up_time_4,
                                                        dwn_time_1,
                                                        dwn_time_2,
                                                        dwn_time_3,
                                                        dwn_time_4,
                                                        dir_1,
                                                        dir_2,
                                                        dir_3,
                                                        dir_4,
                                                        start_1,
                                                        start_2,
                                                        start_3,
                                                        start_4,
                                                        status_1,
                                                        status_2,
                                                        status_3,
                                                        status_4,
                                                        curr_1,
                                                        curr_2,
                                                        curr_3,
                                                        curr_4);
    #else
    (void) enable;
    (void) pwm_freq;
    (void) duty_1;
    (void) duty_2;
    (void) duty_3;
    (void) duty_4;
    (void) up_time_1;
    (void) up_time_2;
    (void) up_time_3;
    (void) up_time_4;
    (void) dwn_time_1;
    (void) dwn_time_2;
    (void) dwn_time_3;
    (void) dwn_time_4;
    (void) dir_1;
    (void) dir_2;
    (void) dir_3;
    (void) dir_4;
    (void) start_1;
    (void) start_2;
    (void) start_3;
    (void) start_4;
    (void) status_1;
    (void) status_2;
    (void) status_3;
    (void) status_4;
    (void) curr_1;
    (void) curr_2;
    (void) curr_3;
    (void) curr_4;                                                    

    #endif
}


void lin_bound_to_sci_service_routine(void)
{
   lin_rx_frame_handling_interrupt = &lin_rx_frame_handling;
   lin_tx_frame_handling_interrupt = &lin_tx_frame_handling;
   lin_ms_timer_handling_interrupt = &lin_ms_timer_handling;
}

void lin_initialization(void)
{
#ifndef LIN_STACK_EMPTY
        lin_bound_to_sci_service_routine();

        lin_init();
#endif
}

void int_rx_sci_first(uint8_t module, uint8_t data)
{

    #ifdef SCI_USER_ACTIVE

        user_int_rx_sci(module, data);

   #else

        (void)module;
        (void)data;

   #endif
}

void int_tx_sci_first(uint8_t module)
{

    #ifdef SCI_USER_ACTIVE                               

        #ifndef SCI_USER_TX_INT_HANDLE_ACTIVE
           if(module == ext_dyn_sci_tx_buffer.sci_nr)
           *(bios_sci_reg[ext_dyn_sci_tx_buffer.sci_nr].SCICR2) &= ~BIOS_SCI_CR2_TIE_MASK;
            sci_int_buffer_send();

        #else

            user_int_tx_sci(module);

        #endif
    #else

        (void)module;

    #endif
}




