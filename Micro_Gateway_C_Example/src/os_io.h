#ifndef _OS_IO_H_
#define _OS_IO_H_



#include "bios_io.h"
#include "os_io_tables_data.h"
#include "bios_adc.h"
#include "bios_timer.h"


#define PORT_INT_FREQ_COUNTER 1
#define PORT_INT_INCR_ENCODER 2
#define PORT_INT_USER_DEF     3

#define EDGE_FALLING  0  
#define EDGE_RISING   1  

typedef struct 
{
  uint8  channel_active;    
  uint16 counter;           
  uint16 calc_time;         
  uint32 time;              
  uint16 freq_calc;         
  uint16 min;
  uint16 max;
  uint8  overflow;  
  uint8  channel_a;
  uint8  channel_b;
  uint8  state;
}os_port_int_def;


#define os_pin_write_secure(label, value)  { os_pin_write(label, value); os_digout(label, value);}



typedef struct 
{
    uint8 cnt;              
    uint8 busy;             
    uint8 multiplex_active; 
    uint8 multiplex;
    uint8 multiplex_max;
    uint8 cnt_adc;          
    uint8 type_active;
    uint8 temp_ch;
    uint16 temp_ref;
}os_adc_vals_def;



extern os_adc_vals_def os_adc_vals;
extern uint8 os_pwm_analog_cal_deactivate;



void os_init_adc(void);


uint16 os_algin(uint8 i);



uint16 os_algin_mv(uint8 i);




uint8 os_algin_err(uint8 i);



void os_analog_io_tick(void);


void os_analog_int(uint8 index);


void os_analog_int_start(void);



void os_pin_set_direction(uint16 i,uint8 val);


void os_pin_set_pull_direction(uint16 i, uint8 val);

void os_pin_set_pull_enable(uint16 i,uint8 val);


void os_pin_set_interrupt_edge(uint16 i,uint8 val);


void os_pin_set_interrupt_enable(uint16 i,uint8 val);




uint8 os_pin_read(uint16 i);


void os_pin_write(uint16 i,uint8 val);


void os_port_write(uint16 i,uint8 val);

void os_port_set_direction(uint16 i,uint8 val);

void os_port_set_pull_direction(uint16 i,uint8 val);


void os_port_set_pull_enable(uint16 i,uint8 val);


void os_port_set_interrupt_edge(uint16 i,uint8 val);


void os_port_set_interrupt_enable(uint16 i,uint8 val);


uint8 os_digin(uint16 i);



void os_digout(uint16 i, uint8 value);




void os_update_digin(void);



void os_update_digout(void);





void os_init_ports(void);


uint16 os_frequency_calc(uint8 channel_def);


uint16 os_frequency_calc_get(uint8 channel_def); 



void os_port_int_increment(void);



uint16 os_frequency_val(uint8 channel_def);



uint16 os_incremental_encoder(uint8 channel_def1, uint8 channel_def2, uint16 min, uint16 max);


void os_incremental_encoder_start_value(uint8 channel_def1, uint16 value);





void os_pwm_analog_io_average(void);


int8_t os_temperature_read(void);


uint32_t os_algin_sum_samples(uint8_t i);



#endif
