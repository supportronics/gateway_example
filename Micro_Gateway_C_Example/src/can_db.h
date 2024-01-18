#ifndef _CAN_DB_H_
#define _CAN_DB_H_


#include "bios.h"
#include "can_db_tables.h"
#include "can_db_tables_data.h"
#include "os.h"

#define ADDR_NORM 0     
#define ADDR_EXT  1     

#define HW_CAN0   0     
#define HW_CAN1   1     
#define HW_CAN2   2     
#define HW_CAN3   3     
#define HW_CAN4   4     

#define DF_INTEL    0   
#define DF_MOTOROLA 1   





void can_db_init(void);



void can_queue_in_process(void);


uint32 can_db_get_value(uint32 id);


uint32 can_db_get_value_on_change(uint32 id, uint8* changed);



void can_db_set_value(uint32 id, uint32 wert_int);

void can_db_set_transmit_flag(uint32 id ) ;

uint8* DB_RAM_FAR can_db_get_block_ptr(uint32 id);


uint8 can_db_block_received(uint32 id, uint8 reset);

uint8 can_db_test_dp_value(uint32 id);


uint8 can_db_gateway(uint8 bus_id, bios_can_msg_typ* msg);

void can_input_block_to_db(uint8 bus_id, bios_can_msg_typ* msg);


uint8_t can_db_input_from_bus(uint8_t hw_module_id);


uint8 can_db_output_to_bus(void);


void can_db_transmit_deactivate(uint8 state);


void  can_db_bus_transmit_stop(uint8_t state, uint8_t bus_id);


void can_create_mask_simple(uint8 bus_id, uint32* mask, uint32* filter, uint8* mask_division);


void dyn_can_create_mask(uint8 bus_id, uint32* mask, uint32* filter, uint8 *mask_division, uint32 *addr_id,  uint32 *addr_mask, uint8 block_max);


void bubblesort(uint32 *array1, uint32 *array2, uint16 length);




void can_create_mask(uint8 bus_id, uint32* mask, uint32* filter, uint8 *mask_division) ;



void can_block_interpret(uint8 akt_CAN_NR, bios_can_msg_typ* msg);


#endif


