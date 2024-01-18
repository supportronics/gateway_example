#ifndef _BIOS_TIMER_H_
#define _BIOS_TIMER_H_


#include "bios_base.h"
#include "bios_cpu.h"
#include "bios_io.h"


#define BUS_CLOCK                   50000000     
#define NR_16BIT                    65535        
#define NR_15BIT                    32767        
#define NR_12BIT                    4096         

#define NR_8BIT                     255          


#define PRESC_NEXT_HIGHER           0            
#define PRESC_NEXT_LOWER            1            

#define PWM_READ_RISING             0            
#define PWM_READ_FALLING            1            
#define PWM_READ_RISING_FALLING     2            



typedef struct 
{
    uint8  active;          
    uint8  edge;            
    uint16 resolution;      
    uint8  presc;           
    uint16 falling_roh;     
    uint16 falling;         
    uint8  falling_ovf;     
    uint16 rising_roh;      
    uint8  ovf;             
    uint16 duty;            
    uint16 frequency;       
    uint32 ti_stamp;        
}bios_tpm_pwm_read_def;

typedef struct 
{
uint8_t active;             
uint16_t counter;           
} bios_ect_freq_read_def; 


extern bios_tpm_pwm_read_def bios_pwm_read[];
extern bios_ect_freq_read_def bios_ect_freq_read[];






void bios_init_timer(void);



void bios_timer1_interrupt_ack(void);

void bios_timer2_interrupt_ack(void);

void bios_timer3_interrupt_ack(void);

void bios_timer4_interrupt_ack(void);




void bios_timer_pwm_channels_init(uint8_t channel, uint8_t pulse_type, uint8_t active);



void bios_timer_pwm_set_frequency(uint8_t i, uint16_t frequency);


void bios_timer_pwm_set_duty_cycle(uint8 channel, uint16 pwm_promille);


void bios_pwm_read_init(uint8_t ch, uint16_t pwm_freq, uint16_t resolution);



uint8_t bios_get_prescaler_value(uint8_t presc_val, uint8_t mode);

void bios_ect_channels_init(uint8_t ch, uint8_t edge);


void bios_ect_chn_interrupt_ack(uint8_t ch);


void bios_ect_ovf_interrupt_ack(void);


void bios_timer_pwm_read_calc(uint8_t ch);

void bios_pwm_get_values(uint8_t ch, uint16_t *duty, uint16_t *frequency);


void bios_ect_init(uint8_t ch, uint8_t edge);

void bios_rti_init(uint8_t reg_val);

#endif

