#ifndef _LIN_STACK_PRIVATE_PROTOTYPES_H_
#define _LIN_STACK_PRIVATE_PROTOTYPES_H_





#include "bios.h"
#include "lin_db_tables.h"
#include "lin_diagnose.h"
#include <string.h>

void private_lin_id_crc_calculate_and_save(void);


void private_lin_enable_transmission_service(uint8_t lin_module, uint8_t frame_index);


void private_lin_tx_frame_send_start(uint8_t lin_frame_index);


void private_lin_int_tx_frame_send_start(uint8_t lin_frame_index);


void private_lin_transmit_frame_initiation(uint8_t lin_frame_index, uint8_t call_src);


void private_lin_module_save_rx_msg(uint8_t lin_module, struct_lin_rx_msg_type rx_msg);


uint8_t private_lin_module_get_saved_rx_msg(uint8_t lin_module, struct_lin_rx_msg_type* msg);


void private_lin_module_rx_idle_and_enable_break(uint8_t lin_module, uint8_t lin_hw_module);





#endif





