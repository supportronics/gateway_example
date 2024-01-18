#ifndef _OS_IO_TABLES_DATA_H_
#define _OS_IO_TABLES_DATA_H_




#include "os_io_tables.h"
#include "os_timer.h"
#include "graph_includes.h"

#include "os_module_specific.h"

#define MAGIC_NUMBER_WDI    	 222  
#define MAGIC_NUMBER_IO    		 223  
#define MAGIC_NUMBER_TEMP  		 224  
#define MAGIC_NUMBER_INIT  		 225  
#define MAGIC_NUMBER_RS485_DE  	 226  


typedef struct
{
    uint8_t    PORT_INPUT_PIN_MAX;
    uint8_t    PORT_PIN_MAX;
    uint8_t    ANALOG_PIN_MAX;
    uint8_t    PWM_PIN_MAX;
    uint8_t    WDI_DEFINED;
    uint8_t    WDI_INDEX;
    uint8_t*   WDI_PORT;
    uint8_t    WDI_BIT_MASK;
    uint8_t    PORT_BIOS_NR;
}os_io_typ;

extern os_io_typ os_io;                 
extern uint16_t os_analog_io_vals[];    

extern uint8_t can_cycle_time_transmit;


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
                                    uint16_t* curr_2);

#ifdef MOT_CTRL_1X_FULLBRIDGE_AKTIV

    extern void modulhardwarecode_mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq,
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
                                                                uint16_t* curr_2);
#endif


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
                                    uint16_t* curr_4);

#ifdef MOT_CTRL_4X_FULLBRIDGE_AKTIV

    extern void modulhardwarecode_mot_ctrl_4x_fullbridge_block(uint8_t enable,
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
                                                                uint16_t* curr_4);
#endif



void os_io_tables_data_init(void);

void os_modul_specific_init(void);

void os_modul_specific_routines(void);

int16_t os_modul_specific_names(uint16_t name);

void bios_timer_pwm_read_calc_first(uint8_t channel);

void motorcontroller_60A_block( uint16_t pwm_freq,
                                uint16_t duty_1,
                                uint16_t duty_2,
                                uint32_t ramp_up_time,
                                uint32_t ramp_down_time,
                                uint8_t rotation,
                                uint8_t start_1,
                                uint8_t start_2,
                                uint8_t enable,
                                uint8_t* status_1,
                                uint8_t* status_2,
                                uint16_t* curr_1,
                                uint16_t* curr_2);

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
                                  uint16_t* curr_4);

void lin_bound_to_sci_service_routine(void);

extern void lin_rx_frame_handling(uint8_t module, uint8_t data);
extern void lin_tx_frame_handling(uint8_t module);
extern void lin_ms_timer_handling(void);
extern void int_rx_sci_first(uint8_t module, uint8_t data);
extern void int_tx_sci_first(uint8_t module);
void lin_initialization(void);
extern void (*lin_ms_timer_handling_interrupt)(void);


void int_rx_sci_first(uint8_t module, uint8_t data);
void int_tx_sci_first(uint8_t module);


#endif


