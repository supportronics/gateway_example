#ifndef _OS_CAN_H_
#define _OS_CAN_H_




#include "bios_can.h"

#include "user_code.h"  


#include <string.h>

#pragma DATA_SEG DEFAULT_RAM_EXT


#define OS_CAN0_ENABLE_MSG_QUEUES    1
#define OS_CAN1_ENABLE_MSG_QUEUES    1
#define OS_CAN2_ENABLE_MSG_QUEUES    1
#ifdef XEP100_ACTIVE
  #define OS_CAN3_ENABLE_MSG_QUEUES  1
#endif
#define OS_CAN4_ENABLE_MSG_QUEUES    1




#ifdef FOUR_16_BIT_FILTER_ENABLE

    #define OS_CAN0_ENABLE_MSG_QUEUE_A_B    0               
    #define OS_CAN1_ENABLE_MSG_QUEUE_A_B    0               
    #define OS_CAN2_ENABLE_MSG_QUEUE_A_B    0               
    #ifdef XEP100_ACTIVE
    #define OS_CAN3_ENABLE_MSG_QUEUE_A_B    0               
    #endif
    #define OS_CAN4_ENABLE_MSG_QUEUE_A_B    0               


    #define OS_CAN0_ENABLE_MSG_QUEUE_A_B_C_D    1
    #define OS_CAN1_ENABLE_MSG_QUEUE_A_B_C_D    1
    #define OS_CAN2_ENABLE_MSG_QUEUE_A_B_C_D    1
    #ifdef XEP100_ACTIVE
    #define OS_CAN3_ENABLE_MSG_QUEUE_A_B_C_D    1
    #endif
    #define OS_CAN4_ENABLE_MSG_QUEUE_A_B_C_D    1

#else

    #define OS_CAN0_ENABLE_MSG_QUEUE_A_B    1               
    #define OS_CAN1_ENABLE_MSG_QUEUE_A_B    1               
    #define OS_CAN2_ENABLE_MSG_QUEUE_A_B    1
    #ifdef XEP100_ACTIVE
    #define OS_CAN3_ENABLE_MSG_QUEUE_A_B    1  
    #endif
    #define OS_CAN4_ENABLE_MSG_QUEUE_A_B    1


    #define OS_CAN0_ENABLE_MSG_QUEUE_A_B_C_D    0
    #define OS_CAN1_ENABLE_MSG_QUEUE_A_B_C_D    0
    #define OS_CAN2_ENABLE_MSG_QUEUE_A_B_C_D    0
    #ifdef XEP100_ACTIVE
    #define OS_CAN3_ENABLE_MSG_QUEUE_A_B_C_D    0
    #endif
    #define OS_CAN4_ENABLE_MSG_QUEUE_A_B_C_D    0

#endif


#if OS_CAN0_ENABLE_MSG_QUEUE_A_B_C_D
  #define OS_CAN0_MSG_QUEUE_C_SIZE        5
  #define OS_CAN0_MSG_QUEUE_D_SIZE        5
#endif

#if OS_CAN1_ENABLE_MSG_QUEUE_A_B_C_D
  #define OS_CAN1_MSG_QUEUE_C_SIZE        5
  #define OS_CAN1_MSG_QUEUE_D_SIZE        5
#endif

#if OS_CAN2_ENABLE_MSG_QUEUE_A_B_C_D
  #define OS_CAN2_MSG_QUEUE_C_SIZE        5
  #define OS_CAN2_MSG_QUEUE_D_SIZE        5
#endif

#ifdef XEP100_ACTIVE
  #if OS_CAN3_ENABLE_MSG_QUEUE_A_B_C_D
    #define OS_CAN3_MSG_QUEUE_C_SIZE        5
    #define OS_CAN3_MSG_QUEUE_D_SIZE        5
  #endif
#endif

#if OS_CAN4_ENABLE_MSG_QUEUE_A_B_C_D
  #define OS_CAN4_MSG_QUEUE_C_SIZE        5
  #define OS_CAN4_MSG_QUEUE_D_SIZE        5
#endif




#if BIOS_CAN_MODUL_DEFAULT == 0
  #define os_can_default_func(func_name) os_can0_##func_name
#endif
#if BIOS_CAN_MODUL_DEFAULT == 1
  #define os_can_default_func(func_name) os_can1_##func_name
#endif
#if BIOS_CAN_MODUL_DEFAULT == 2
  #define os_can_default_func(func_name) os_can2_##func_name
#endif

#ifdef XEP100_ACTIVE
  #if BIOS_CAN_MODUL_DEFAULT == 3
    #define os_can_default_func(func_name) os_can3_##func_name
  #endif
#endif

#if BIOS_CAN_MODUL_DEFAULT == 4
  #define os_can_default_func(func_name) os_can4_##func_name
#endif


typedef enum
{
	CAN_BAUD_USER_1000  =  1,
	CAN_BAUD_USER_800      	,
	CAN_BAUD_USER_500       ,
	CAN_BAUD_USER_250       ,
	CAN_BAUD_USER_125       ,
	CAN_BAUD_USER_50        ,
  CAN_BAUD_USER_20        ,
  CAN_BAUD_USER_10     	  ,
	CAN_BAUD_USER_100       ,
	CAN_BAUD_USER_83_3      ,
  CAN_BAUD_USER_33_3      ,
  CAN_BAUD_USER_MAX_LEN   ,
} enum_USER_CAN_BAUDRADE;



#define os_can_get_msg_A   os_can_default_func(get_msg_A)
#define os_can0_get_msg_A(msg) os_can_module_get_msg_A(0, msg, 0)
#define os_can1_get_msg_A(msg) os_can_module_get_msg_A(1, msg, 0)
#define os_can2_get_msg_A(msg) os_can_module_get_msg_A(2, msg, 0)
#ifdef XEP100_ACTIVE
  #define os_can3_get_msg_A(msg) os_can_module_get_msg_A(3, msg, 0)
#endif
#define os_can4_get_msg_A(msg) os_can_module_get_msg_A(4, msg, 0)


uint8 os_can_module_get_msg_A(uint8 module, bios_can_msg_typ* msg, uint8 beg_pointer);




#define os_can_get_msg_B   os_can_default_func(get_msg_B)
#define os_can0_get_msg_B(msg) os_can_module_get_msg_B(0, msg, 0)
#define os_can1_get_msg_B(msg) os_can_module_get_msg_B(1, msg, 0)
#define os_can2_get_msg_B(msg) os_can_module_get_msg_B(2, msg, 0)
#ifdef XEP100_ACTIVE
  #define os_can3_get_msg_B(msg) os_can_module_get_msg_B(3, msg, 0)
#endif
#define os_can4_get_msg_B(msg) os_can_module_get_msg_B(4, msg, 0)
uint8 os_can_module_get_msg_B(uint8 module, bios_can_msg_typ* msg, uint8 beg_pointer);




#define os_can_get_msg_C   os_can_default_func(get_msg_C)
#define os_can0_get_msg_C(msg) os_can_module_get_msg_C(0, msg, 0)
#define os_can1_get_msg_C(msg) os_can_module_get_msg_C(1, msg, 0)
#define os_can2_get_msg_C(msg) os_can_module_get_msg_C(2, msg, 0)
#ifdef XEP100_ACTIVE
  #define os_can3_get_msg_C(msg) os_can_module_get_msg_C(3, msg, 0)
#endif
#define os_can4_get_msg_C(msg) os_can_module_get_msg_C(4, msg, 0)
uint8 os_can_module_get_msg_C(uint8 module, bios_can_msg_typ* msg, uint8 beg_pointer);




#define os_can_get_msg_D   os_can_default_func(get_msg_D)
#define os_can0_get_msg_D(msg) os_can_module_get_msg_D(0, msg, 0)
#define os_can1_get_msg_D(msg) os_can_module_get_msg_D(1, msg, 0)
#define os_can2_get_msg_D(msg) os_can_module_get_msg_D(2, msg, 0)
#ifdef XEP100_ACTIVE
  #define os_can3_get_msg_D(msg) os_can_module_get_msg_D(3, msg, 0)
#endif
#define os_can4_get_msg_D(msg) os_can_module_get_msg_D(4, msg, 0)

uint8 os_can_module_get_msg_D(uint8 module, bios_can_msg_typ* msg, uint8 beg_pointer);




#define os_can_rx   os_can_default_func(rx)
#define os_can0_rx() os_can_module_rx(0)
#define os_can1_rx() os_can_module_rx(1)
#define os_can2_rx() os_can_module_rx(2)
#ifdef XEP100_ACTIVE
  #define os_can3_rx() os_can_module_rx(3)
#endif
#define os_can4_rx() os_can_module_rx(4)

void os_can_module_rx(uint8 module);


void os_can_copy_msg(bios_can_msg_typ* src, bios_can_msg_typ* DB_RAM_FAR dst);



uint8 os_can_send_msg(uint8_t hw_id, uint32_t Id, uint8_t IdType,  uint8_t Dlc, uint8_t Byte0 , uint8_t Byte1 , uint8_t Byte2 , uint8_t Byte3 , uint8_t Byte4 , uint8_t Byte5 , uint8_t Byte6 , uint8_t Byte7 );
#define os_can_send_message(hw_id, Id, IdType,  Dlc, Byte0 , Byte1 , Byte2 , Byte3 , Byte4 , Byte5 , Byte6 , Byte7) os_can_send_msg(hw_id, Id, IdType,  Dlc, Byte0 , Byte1 , Byte2 , Byte3 , Byte4 , Byte5 , Byte6 , Byte7) 



uint8 os_can_check_error(uint8 can_nr);



void os_can_set_baudrate (uint8_t bus_id, uint8_t can_baudrate);


extern uint8 MRS_FAR dyn_OS_CAN0_MSG_QUEUE_A_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN0_MSG_QUEUE_B_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN1_MSG_QUEUE_A_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN1_MSG_QUEUE_B_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN2_MSG_QUEUE_A_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN2_MSG_QUEUE_B_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN3_MSG_QUEUE_A_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN3_MSG_QUEUE_B_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN4_MSG_QUEUE_A_SIZE;
extern uint8 MRS_FAR dyn_OS_CAN4_MSG_QUEUE_B_SIZE;

#pragma DATA_SEG DEFAULT


#endif
