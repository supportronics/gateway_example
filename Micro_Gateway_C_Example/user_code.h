#ifndef _USER_CODE_H_
#define _USER_CODE_H_
   
/*----------------------------------------------------------------------------*/
/**
*   \file         user_code.h
*   \brief        Usercode function header. 
*/
/*----------------------------------------------------------------------------*/
/** 
*   \addtogroup   doc_user_code User Code 
*   \{
*   \brief        This group contains the main function for mrs lib users. See usercode() function.
*   \details      Here the main setup is done and library is prepared for usage.
*               This document offers a detailed explanation of the the MRS Developers Studio user functions.
*               The user_code.c file contains two different kinds of functions. The first category contains the 
*               usercode() function which is called each loop in the main-loop function. Put your main application 
*				code into this function. If you need to do time critical operations, use the functions
*               of the second category.  
*               The second category are callback-functions which are called by events / interrupt service routines. If you
*               have to react on time critical events like sending CAN messages you have to use the corresponding functions
*               in the "Events" section in the user_code.c file. Take care not to put too much code into the 
*               callback-functions.
*               
*               This document should offer an overview of the functions which can be used by the user. Each function
*               has a documentation which offers the necessary knowledge to use it. You can find the documented 
*               functions under the "Modules" or "Files" entry in the left or top menu. They are organized on a file basis in the 
*               "File List" entry or alphabetically sorted in the "Globals" entry. In the "Modules" category they are organized in
*               logical groups, like CAN, LIN or IO functions.
*
*               This documentation does not offer general information about general MRS Developers Studio usage, like how 
*               to define data-points or how to use the graphical programming. You can find this information in the manual
*               which is located in the MRS Developers Studio GUI under "Help" then "Manual".
*
*/
/*----------------------------------------------------------------------------*/

#include "bios_can.h"
#include "os_can.h"



// --------------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------------

#define GRAPH_DISABLE

// --------------------------------------------------------------------------------
/// Use the define STAND_ALONE_VERSION to activate Codewarrior debugging:
/// Only for DEBUG with IndartOne or PEMicro-Multilink:
// --------------------------------------------------------------------------------
// #define STAND_ALONE_VERSION     // Debug => Runs without bootloader
// --------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Enable or disable RS232/485 serial communication interface (THIS IS NEEDED):
//#define SCI_USER_ACTIVE

//#define SCI_USER_TX_INT_HANDLE_ACTIVE
#define USER_BUFFER_SIZE 100

// Activate if needed RS485 type (for switching driver output enable "DE" - pin)
//#define SCI_USER_RS485

// Parity: 0=disabled, 1=even parity, 2=odd parity
#define SCI_USER_PARITY   0

// Data bits: 0=8 data bits, 1=9 data bits
#define SCI_USER_DATA_BITS_9  0

//Don't change that line:
#define SCI_NR  BIOS_SCI4
//--------------------------------------------------------------------------------
// For RS232 communication of SCI0 (e.g. mGateway) set the baudrate
// Choose Baudrate from the list:
#define SCI_USER_BAUDRATE BIOS_SCI_19200_BAUD
// Possible baudrates:
// BIOS_SCI_4800_BAUD
// BIOS_SCI_9600_BAUD
// BIOS_SCI_19200_BAUD
// BIOS_SCI_28800_BAUD
// BIOS_SCI_38400_BAUD
// BIOS_SCI_115200_BAUD

// Set a user-defined baudrate of SCIxBD:   (Calculation: Baud_Nr = BUS_FREQ_HZ/(16*Baud); BUS_FREQ_HZ=50*10^6, Baud= z.B. 19200)
//#define SCI_USER_DEFINED_BAUDRATE 163   //(Example: (50000000 / (16*19200)) = 163

// Copy these 3 lines to usercode_init() to enable the parity bit (SCI0 is RS232 on mGateway):
//SCI0CR1_M = 1;    // 0 = 8 data bits, 1 = 9 data bits
//SCI0CR1_PE = 1;   // 0 = No parity, 1 = Parity enabled (the last data bit is the parity bit)
//SCI0CR1_PT = 0;   // 0 = Even parity, 1 = Odd parity


//#define M2600_ACTIVATE_RS232_RX_INTERRUPT     //Activate SCI2 (e.g. RS232 of M2600)
//--------------------------------------------------------------------------------

// Read PWM duty cycle:

// Activate PWM duty cycle read
//#define PWM_DUTYCYCLE_READ_ACTIVE

// Specify expected PWM frequency in Hz
#define PWM_DUTYCYCLE_READ_FREQ   1000

// Specify desired duty cycle resolution in digits, measured value will be between 0 and res
#define PWM_DUTYCYCLE_READ_RES    100

// Specify Timer channel:
// M2600: 0=DI_26, 1=DI_25, 2=DI_24, 3=DI_23, 4=DI_22, 5=DI_21
#define PWM_DUTYCYCLE_READ_CH     0

// It's also possible to use the enhanced capture timer on your own
//#define ECT_ACTIVE

//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// Set the user-defined timer, see user_defined_int_timer() in user_code.c
//#define PID2_USER_DEFINED_CYCLE 1000    //microseconds, maximum value: 1311�s [ < (65535/50) ]

//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// Set the size of uint16 eeprom_userdaten[]
#define USERDATENSATZ_SIZE 56

// Set the size of uint32 user_variable[]
#define USER_VARIABLE_SIZE 10

// - optional if values are without effect -

// Set the size of uint16 eeprom_hsddaten[]
//#define HSDDATENSATZ_SIZE_MASTER 48

// Set the size of uint16 user_variable[]
//#define USER_VARIABLE_SIZE_MASTER 20
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// Set the size of CAN0 receive buffer A and B
#define OS_CAN0_MSG_QUEUE_A_SIZE 15
#define OS_CAN0_MSG_QUEUE_B_SIZE 15

// Set the size of CAN1 receive buffer A and B
#define OS_CAN1_MSG_QUEUE_A_SIZE 15
#define OS_CAN1_MSG_QUEUE_B_SIZE 15

// Set the size of CAN2 receive buffer A and B
#define OS_CAN2_MSG_QUEUE_A_SIZE 15
#define OS_CAN2_MSG_QUEUE_B_SIZE 15

// Set the size of CAN3 receive buffer A and B
#define OS_CAN3_MSG_QUEUE_A_SIZE 15
#define OS_CAN3_MSG_QUEUE_B_SIZE 15

// Set the size of CAN4 receive buffer A and B
#define OS_CAN4_MSG_QUEUE_A_SIZE 15
#define OS_CAN4_MSG_QUEUE_B_SIZE 15
//--------------------------------------------------------------------------------



// --------------------------------------------------------------------------------
// Function definition
// --------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/** 
* \brief    Initialize user components.  
* \details  This function is called once after startup. ADC-Values are available, but remember that 
*           Sampling can take up to 20 ms.
*           Here you should read your EEPROM values and initialize your functions.
*           
*           
* \return   void      
*/
void usercode_init(void);
/*----------------------------------------------------------------------------*/
/** 
* \brief    Cyclic main call for User.   
* \details  Write your own C-Code in here. Depending on the graph_cycle_time, 
*           this function is called more or less often (default is 20 ms). 
*           
* \return   void      
*/
void usercode(void);

/*----------------------------------------------------------------------------*/
/** 
* \brief    Receive a message from CAN bus.   
* \details  Each received can message is placed into a receive buffer.
*           The main loop walks through this buffer and handles all the messages. This can be
*           either internally as part of the MRS protocol or a direct call of this function.
*           Remember: Only when CAN filter is open ( Set by DeveloperStudio or at  ) you get this message.
*           
* \param    hw_id [in] uint8    ID on which bus the message was from. Values are eg. #CAN_BUS_0.
* \param    msg   [in] bios_can_msg_typ* The message that was received. Use -> operator for access:
*      
* \return   void      
*/
void user_can_message_receive(uint8 hw_id, bios_can_msg_typ* msg);


/*----------------------------------------------------------------------------*/
/** 
* \brief   Serial Line receive interrupt. 
* \details This function is called, when a byte is received over serial line directly in interrupt. 
*          It is located in user_code.c directly below main usercode() function. 
*           
* \param    module [in] uint8_t The Module ID where message was received from (eg. BIOS_SCI0)
* \param    data   [in] uint8 The byte that was received
* \return   void 
*
*   Example Code:
*   \code{.c}
*   user_int_rx_sci(uint8_t module, uint8 data)   
*   {
*      if( module == BIOS_SCI0 )
*      {
*         fifo_put(data);
*      }
*   }
*   \endcode
*/
void user_int_rx_sci(uint8_t module, uint8 data);

/*----------------------------------------------------------------------------*/
/** 
* \brief    Serial line transmit interrupt.    
* \details  This function is called, when a byte transfer on serial line has finnished.
*           
*           
* \param    module [in] uint8_t  The Module that finnished the transfer.
* \return   void      
*/
void user_int_tx_sci(uint8_t module);

/*----------------------------------------------------------------------------*/
/** 
* \brief    This is a cyclic call, that is handled every ms.  
* \details  Please put not too much code into it, or timings will fail.
*           
*           
* \return   void      
*/
void user_int_timer_1ms(void);

/*----------------------------------------------------------------------------*/
/** 
* \brief    User-defined Timer PID2 interrupt Callback.   
* \details  This function is called, when user timer expires. This depends on its setup from
*           PID2_USER_DEFINED_CYCLE in this file.
*           
*           
* \return   void      
*/
void user_defined_int_timer(void);



/*----------------------------------------------------------------------------*/
/** 
* \brief    Enhanced Capture timer interrupt callback. 
* \details  This function is called, when an interrupt from enhanced capture timer happened.
*           This means eg. a PWM-in signal has changed its level. 
*           
*           
* \param    ch   [in] uint8_t    The timer channel that created this interrupt.
* \return   void      
*/
void user_int_ect(uint8_t ch);





#include "bios.h"
#include "os_timer.h"
#include "os_io.h"
#include "CAN_HCS12_BL.h"
#include "can_db.h"
#include "os_io_tables.h"
#include "lin_stack.h"
#include "os_sci.h"
#include "os_flash.h"
/** \}*/
#endif
