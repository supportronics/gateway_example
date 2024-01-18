/*--------------------------------------------------------------------------*/
/** \file     os_io_tables.c
*   \brief    Functions of operating system for initialization
*             and access to ports and pins of processor
*
*   \date     18/01/2024    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------*/


#include "os_io_tables.h" 
#include "bios_io.h" 



/** \ingroup io
*   \brief           Definition of port pins
* --------------------------------------------------------------------------*
*                    All the used pins with their initialization values are
*                    inserted in this table. The write- and read-functions
*                    #os_digin() and #os_digout() use the pin name as parameter.
*                    Output pins have to be inserted below the line
*                    #OS_PORT_INPUT_PIN_MAX
*                    Inputs and outputs could be debounced as high-low as well as
*                    low-high edges. One cycle is one call of #os_update_digin()
*                    or #os_update_digout().
*
*                    IMPORTANT: After inserting new lines the enum in os_io_tables.h
*                    has to be updated!
* --------------------------------------------------------------------------*/
const os_port_pin_def os_port_pin[] = {
//                                                                                                             Debounce cycles:
//  Pin-Name              Port                  Bit                   Direction             Pull-Dir              Pull-Enable           Interrupt Edge        Interrupt-Enable      Value                 Lo-Hi                 Hi-Lo                 Multiplex             Inverted              
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                              (0-7)                 (PD_IN,               (PU_UP                (PE_ON                (PI_RISE              (PI_ON                (0,1)                 (0-255)               (0-255)               (0,1)                 (0,1)                 
//                                                                    PD_OUT),              PU_DOWN)              PE_OFF)               PI_FALL)              PI_OFF)                                                                                                                                                   
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{   DI_AI_1               ,PORT_AD0             ,0                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Pin 8 AI_1
{   DI_KL15               ,PORT_T               ,3                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Pin 4 KL15
{   DI_CAN1_ERR_N         ,PORT_B               ,0                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Internal Error pin CAN1 TJA1041, 1=OK, 0=ERR
{   DI_CAN2_ERR_N         ,PORT_B               ,4                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Internal Error pin CAN2 TJA1041, 1=OK, 0=ERR
{   OS_PORT_INPUT_PIN_MAX ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN1_STB_N         ,PORT_B               ,3                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN2_STB_N         ,PORT_B               ,7                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN1_EN            ,PORT_B               ,1                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN2_EN            ,PORT_B               ,5                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN1_WAKE          ,PORT_B               ,2                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    },
{   DO_CAN2_WAKE          ,PORT_B               ,6                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    },
{   DO_LIN_EN             ,PORT_P               ,5                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    }, // Pin 2 EN of TJA1021 for LIN1
{   DO_LIN_WAKE           ,PORT_P               ,7                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // Pin 3 WAKE of TJA1021 for LIN1
{   DO_POWER              ,PORT_T               ,1                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // Awake self-holding of module
{   OS_PORT_PIN_MAX       ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    },
};




/** \ingroup io
*   \brief           Definition of analog inputs and outputs
* --------------------------------------------------------------------------*
*                    This is the list of analog inputs and outputs.
*                    You could enter a value range from Min to Max to generate
*                    an error if the value is not within the range.
*                    The errors could be masked by error filters
*                    ( #ERR_OFF, #ERR_MIN, #ERR_MAX, #ERR_MIN_MAX )
* --------------------------------------------------------------------------*/
const os_analog_pin_def os_analog_pin[] = {
//  Pin-Name              ADC-Channel           Direction             Value                 Min                   Max                   Error-Filter          Entprell-Takte        ADC-Max mV            Multiplex             Multiplex Type        Parameter 1           Samples               
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                              (PD_IN                (0-                   (0-                   (0-                   (ERR_OFF              (0-255)               (0-65535)             (0,1)                 (0-255)               (0-255)               (0-255)               
//                                              PD_OUT)               32767)                32767)                32767)                ERR_MIN                                                                                                                             0 Standard            
//                                                                                                                                      ERR_MAX,                                                                                                                            1-255 ms oversample   
//                                                                                                                                      ERR_MIN_MAX                                                                                                                                               
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{   AI_1                  ,0                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 33670               ,0                    ,0                    ,0                    ,0                    }, // Pin 8 AI1
{   AI_KL15               ,2                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 33000               ,0                    ,0                    ,0                    ,0                    }, // Pin 4 AI_KL15
{   OS_ANALOG_PIN_MAX     ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    , 0                   ,0                    ,0                    ,0                    ,0                    },
};



/** \ingroup io
*   \brief           Definition of PWM outputs
* --------------------------------------------------------------------------*
*                    This table lists the properties of the PWM outputs.
* --------------------------------------------------------------------------*/
const os_pwm_pin_def os_pwm_pin[OS_PWM_PIN_MAX+1];


// 4MHz or 8MHz oscillator => Adapt PLL multiplicator
const uint8_t bios_osc_clk = OSC_CLK_8MHZ;


// Device type number: This could activate module specific initialization code
const uint8_t modul_geraetetyp_nr = 0;

