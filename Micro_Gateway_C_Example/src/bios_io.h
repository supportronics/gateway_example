#ifndef _BIOS_IO_H_
#define _BIOS_IO_H_



#include "bios_base.h"
#include "bios_adc.h"


#define BIOS_NULL_P     (reg_p)0xFFFF   
#define HIGH_TRUE       0               
#define LOW_TRUE        1               

#define PD_IN           0               
#define PD_OUT          1               

#define PU_UP           0               
#define PU_DOWN         1               

#define PE_ON           1               
#define PE_OFF          0               

#define PI_RISE         1               
#define PI_FALL         0               

#define PI_ON           1               
#define PI_OFF          0               

#define DONT_CARE       23              
#define NONE            23              

#define ERR_OFF         0x0             
#define ERR_MIN         0x1             
#define ERR_MAX  	    0x2             
#define ERR_MIN_MAX     0x3             

#define CHANNEL_TEMP    200             



enum 
{
    PORT_A = 0,                         
    PORT_B,                             
    PORT_C,                             
    PORT_D,                             
    PORT_E,                             
    PORT_K,                             
    PORT_T,                             
    PORT_S,                             
    PORT_M,                             
    PORT_P,                             
    PORT_H,                             
    PORT_J,                             
    PORT_AD0,                           
    PORT_AD1,                           
    PORT_AD2,                           
    PORT_AD3,                           
    PORT_R,                             
    PORT_L,                             
    PORT_F,                             
    BIOS_NR_OF_PORTS                    
};

enum 
{
    PORT_INT_P = PORT_P,                
    PORT_INT_H = PORT_H,                
    PORT_INT_J = PORT_J,                
    BIOS_NR_OF_INT_PORTS = 3            
};






typedef uint8* const reg_p ;            



extern const uint8 bios_bitmask[8u];    




#define bios_portJ_interrupt_ack bios_port_interrupt_ack (PORT_J)   
#define bios_portH_interrupt_ack bios_port_interrupt_ack (PORT_H)   
#define bios_portP_interrupt_ack bios_port_interrupt_ack (PORT_P)   

void bios_port_interrupt_ack (uint8_t port);





void bios_enable_adc_channel(uint8_t channel);


void bios_analog_select_channel(uint8_t channel);



void bios_config_adc(void);


uint16_t bios_get_current_adc_value(uint8_t channel); 


uint16_t bios_read_adc_value(uint8_t adc_channel);



uint16_t bios_analog_get_channel_single(uint8_t i);


void bios_analog_enable_temp_sensor(uint8_t ref_enable);


#endif
