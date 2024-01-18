#ifndef _OS_TIMER_H_
#define _OS_TIMER_H_



#include "bios_timer.h"
#include "PE_Types.h"
#include "os.h"

extern uint32 os_time_tick_1ms;  
extern uint32 os_time_tick_10ms;
extern uint32 os_time_tick_100ms;
extern uint32 os_time_tick_1000ms;


#define OS_1ms    1         
#define OS_10ms   2         
#define OS_100ms  3         
#define OS_1000ms 4         
#define OS_1s     4         



typedef struct {
  uint16 dither_promille;
  uint16 dither_counts;
  uint16 dither_counts_old;
  uint16 dither_counter;
  uint8  dither_change_cnt;
  uint16 pwm_promille_backup;
  uint16 pwm_frequency_old;
  int8   dither_stat;    
  uint16 analog_average;    
  uint16 duty_cycle;
  uint8  channel_active;
  uint16 pwm_period;
  uint8  kal_data_deaktivate;
  uint8  os_analog_index;
}os_pwm_vals_def;


typedef struct {
  uint32 y_avg_long;
  uint16 y_avg;
  uint32 kp_long;
  uint16 kp;
  uint16 y;
  uint16 w_rampe;
  uint8  error;
  uint16 error_timer;
  uint8  start_timer_set;
  uint16 start_timer;
  uint8  time_diff;
  uint8  startbed;
  uint8  active;    
}os_pwm_control_vals_def;


#define PWM_DUTY_READ_MAX   8    
typedef struct 
{
    uint8  active;
    uint16 init_freq;
    uint16 init_res;    
    uint16 duty;
    uint16 frequency;    
}os_pwm_duty_read_def;

extern os_pwm_duty_read_def os_pwm_duty_read[];




void os_timestamp(uint32* time, uint8 precision);


void os_timestamp_far(uint32* MRS_FAR time, uint8 precision);



uint32  os_set_timestamp(uint8 precision);



uint8 os_time_past(uint32 time, uint32 value, uint8 precision);


uint32 os_get_time_past(uint32 time, uint8 precision);


void os_wait(uint32 value);


void os_timer_tick(uint8 tick);


void os_init_pwm(void);



void os_init_pwm_duty_read(void);



void os_pwm_duty_cycle(uint8 i, uint16 pwm_promille, uint16 pwm_frequency, uint16 pwm_dither_promille, uint16 pwm_dither_frequency);



void os_timer1_dither_calculation(void);


void os_pwm_control(uint8 i, uint16 w, uint16 pwm_frequency, uint16 pwm_dither_promille, uint16 pwm_dither_frequency, uint16 rampe, uint16 kp_min, uint16 kp_max, uint16 time_diff, uint16 *kp_calc, uint8 *error);


void os_pwm_read_update(void);
uint8_t os_int_time_past(uint32_t time, uint32_t value, uint8_t precision);


uint32_t os_int_set_timestamp(uint8_t precision);


void os_int_timestamp(uint32_t* time, uint8_t precision);


void os_pwm_adc_filter_value(uint8 i, uint16 period_time); 


void os_init_frequency_read(uint8_t channel_def);


void os_frequency_read(uint8_t channel_def, uint32_t* measure_period_timestamp, uint16_t* measured_frequency);




#endif






