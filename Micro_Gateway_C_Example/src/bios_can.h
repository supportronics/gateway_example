#ifndef _BIOS_CAN_H_
#define _BIOS_CAN_H_





#include "bios_base.h"




#define XEP100_ACTIVE                               
#define BIOS_CAN_MODULES_MAX            4u          
#define BIOS_CAN_MODUL_DEFAULT          0u          
#define BIOS_CAN_BAUDRATE_NAME_LEN      10u         
#define BIOS_CAN_MSG_DATA_MAX_LEN       8u          






#define BIOS_CAN_ENABLE_RX_INTERRUPT    1u






#define BIOS_CAN_EXT_BAUDRATE           0u          
#define BIOS_CAN_1MBIT                  1u          
#define BIOS_CAN_800KBIT                2u          
#define BIOS_CAN_500KBIT                3u          
#define BIOS_CAN_250KBIT                4u          
#define BIOS_CAN_125KBIT                5u          
#define BIOS_CAN_100KBIT                9u          
#define BIOS_CAN_83_33KBIT              10u         
#define BIOS_CAN_50KBIT                 6u          
#define BIOS_CAN_33_33KBIT              11u         
#define BIOS_CAN_20KBIT                 7u          
#define BIOS_CAN_10KBIT                 8u          

#define BIOS_CAN_ERR_RX_OK              0u          
#define BIOS_CAN_ERR_RX_WARN            1u          
#define BIOS_CAN_ERR_RX_ERROR           2u          
#define BIOS_CAN_ERR_BUS_OFF            3u          

#define BIOS_CAN_ERR_TX_SUCCESS         0u          
#define BIOS_CAN_ERR_TX_FAIL            1u          

#define BIOS_CAN_ERR_TX_QUEUE_FAIL      0u          
#define BIOS_CAN_ERR_TX_QUEUE_SUCCESS   1u          
#define BIOS_CAN_ERR_TX_QUEUE_FULL      2u          
#define BIOS_CAN_ERR_TX_QUEUE_EMPTY     3u          
#define BIOS_CAN_ERR_TX_QUEUE_INT_ACT   4u          

#define OS_CAN_ENABLE_MSG_QUEUE_A_B     1u          
#define OS_CAN_MSG_QUEUE_A_SIZE         2u          
#define OS_CAN_MSG_QUEUE_B_SIZE         2u          

#define BIOS_CAN_ID_NORM_A_AND_B        0u          
#define BIOS_CAN_ID_NORM_A_EXT_B        1u          
#define BIOS_CAN_ID_EXT_A_AND_B         2u          
#define BIOS_CAN_ID_ALL_CLOSED          3u          
#define BIOS_CAN_ID_ALL_OPEN            4u          

#define BIOS_CAN0_TX_MSG_QUEUE_SIZE     (uint8_t)15 
#define BIOS_CAN1_TX_MSG_QUEUE_SIZE     (uint8_t)15 
#define BIOS_CAN2_TX_MSG_QUEUE_SIZE     (uint8_t)15 

#ifdef XEP100_ACTIVE                                
    #define BIOS_CAN3_TX_MSG_QUEUE_SIZE (uint8_t)15 
#endif
#define BIOS_CAN4_TX_MSG_QUEUE_SIZE     (uint8_t)15 





typedef struct
{
    uint32_t id;                                    
    uint16_t id_ext    :1;                          
    uint16_t remote_tx :1;                          
    uint8_t data[8];                                
    uint8_t len;                                    
#ifdef BIOS_CAN_TIMESTAMP
    uint32_t timestamp;                             
#endif
} bios_can_msg_typ;


typedef struct
{
  uint8_t p;                                        
  uint8_t t_seg1;                                   
  uint8_t t_seg2;                                   
  uint8_t sj;                                       
  uint8_t clk_src;                                  
} bios_baudraten_def;


typedef struct
{
    uint8_t name[BIOS_CAN_BAUDRATE_NAME_LEN+1];     
    uint8_t sj;                                     
    uint8_t pre;                                    
    uint8_t t_seg1;                                 
    uint8_t t_seg2;                                 
    uint8_t clk_src;                                
} bios_can_baudrate_typ;





#if BIOS_CAN_MODUL_DEFAULT == 0
  #define bios_can_default_func(func_name) bios_can0_##func_name            
#endif
#if BIOS_CAN_MODUL_DEFAULT == 1
  #define bios_can_default_func(func_name) bios_can1_##func_name            
#endif
#if BIOS_CAN_MODUL_DEFAULT == 2
  #define bios_can_default_func(func_name) bios_can2_##func_name            
#endif
#ifdef XEP100_ACTIVE
  #if BIOS_CAN_MODUL_DEFAULT == 3
    #define bios_can_default_func(func_name) bios_can3_##func_name          
  #endif
#endif
#if BIOS_CAN_MODUL_DEFAULT == 4
  #define bios_can_default_func(func_name) bios_can4_##func_name            
#endif


void bios_can_set_ext_baudrate(bios_can_baudrate_typ* baudrate);




#define bios_can_filter_A_hit   bios_can_default_func(filter_A_hit)         
#define bios_can0_filter_A_hit() bios_can_module_filter_A_hit(0)            
#define bios_can1_filter_A_hit() bios_can_module_filter_A_hit(1)            
#define bios_can2_filter_A_hit() bios_can_module_filter_A_hit(2)            
#ifdef XEP100_ACTIVE
  #define bios_can3_filter_A_hit() bios_can_module_filter_A_hit(3)          
#endif
#define bios_can4_filter_A_hit() bios_can_module_filter_A_hit(4)            



uint8_t bios_can_module_filter_A_hit(uint8_t module);



#define bios_can_filter_B_hit   bios_can_default_func(filter_B_hit)         
#define bios_can0_filter_B_hit() bios_can_module_filter_B_hit(0)            
#define bios_can1_filter_B_hit() bios_can_module_filter_B_hit(1)            
#define bios_can2_filter_B_hit() bios_can_module_filter_B_hit(2)            
#ifdef XEP100_ACTIVE
  #define bios_can3_filter_B_hit() bios_can_module_filter_B_hit(3)          
#endif
#define bios_can4_filter_B_hit() bios_can_module_filter_B_hit(4)            


uint8_t bios_can_module_filter_B_hit(uint8_t module);


#define bios_can_filter_C_hit   bios_can_default_func(filter_C_hit)         
#define bios_can0_filter_C_hit() bios_can_module_filter_C_hit(0)            
#define bios_can1_filter_C_hit() bios_can_module_filter_C_hit(1)            
#define bios_can2_filter_C_hit() bios_can_module_filter_C_hit(2)            
#ifdef XEP100_ACTIVE
  #define bios_can3_filter_C_hit() bios_can_module_filter_C_hit(3)          
#endif
#define bios_can4_filter_C_hit() bios_can_module_filter_C_hit(4)            


uint8_t bios_can_module_filter_C_hit(uint8_t module);


#define bios_can_filter_D_hit   bios_can_default_func(filter_D_hit)         
#define bios_can0_filter_D_hit() bios_can_module_filter_D_hit(0)            
#define bios_can1_filter_D_hit() bios_can_module_filter_D_hit(1)            
#define bios_can2_filter_D_hit() bios_can_module_filter_D_hit(2)            
#ifdef XEP100_ACTIVE
  #define bios_can3_filter_D_hit() bios_can_module_filter_D_hit(3)          
#endif
#define bios_can4_filter_D_hit() bios_can_module_filter_D_hit(4)            

uint8_t bios_can_module_filter_D_hit(uint8_t module);


#define bios_init_can   bios_can_init                                       
#define bios_can_init   bios_can_default_func(init)                         

#define bios_can0_init(bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext) bios_can_module_init(0, bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext,0)

#define bios_can1_init(bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext) bios_can_module_init(1, bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext,0)

#define bios_can2_init(bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext) bios_can_module_init(2, bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext,0)

#ifdef XEP100_ACTIVE
  #define bios_can3_init(bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext) bios_can_module_init(3, bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext,0)
#endif

#define bios_can4_init(bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext) bios_can_module_init(4, bitrate, mask_A, mask_B, mask_C, mask_D, filter_A, filter_B, filter_C, filter_D, id_usage, baudrate_ext,0)



void bios_can_module_init(uint8_t module, uint8_t bitrate, uint32_t* mask, uint32_t* filter, uint8_t id_usage, const bios_can_baudrate_typ* baudrate_ext, uint8_t listen_only);


void bios_can_module_listen(uint8_t bus_nr, uint8_t listen_only);



#define bios_can_disable   bios_can_default_func(disable)                   
#define bios_can0_disable() bios_can_module_disable(0)                      
#define bios_can1_disable() bios_can_module_disable(1)                      
#define bios_can2_disable() bios_can_module_disable(2)                      
#ifdef XEP100_ACTIVE
  #define bios_can3_disable() bios_can_module_disable(3)                    
#endif
#define bios_can4_disable() bios_can_module_disable(4)                      


void bios_can_module_disable(uint8_t module);


#define bios_can_enter_reset   bios_can_default_func(enter_reset)           
#define bios_can0_enter_reset() bios_can_module_enter_reset(0)              
#define bios_can1_enter_reset() bios_can_module_enter_reset(1)              
#define bios_can2_enter_reset() bios_can_module_enter_reset(2)              
#ifdef XEP100_ACTIVE
  #define bios_can3_enter_reset() bios_can_module_enter_reset(3)            
#endif
#define bios_can4_enter_reset() bios_can_module_enter_reset(4)              

#define bios_can_module_enter_reset(module) \
{                                           \
    if (CAN##module##CTL0_INITRQ != 1)      \
    {                                       \
        CAN##module##CTL0_INITRQ = 1;       \
    }                                       \
    while (CAN##module##CTL1_INITAK != 1);  \
}


#define bios_can_enter_operation   bios_can_default_func(enter_operation)   
#define bios_can0_enter_operation() bios_can_module_enter_operation(0)      
#define bios_can1_enter_operation() bios_can_module_enter_operation(1)      
#define bios_can2_enter_operation() bios_can_module_enter_operation(2)      
#ifdef XEP100_ACTIVE
  #define bios_can3_enter_operation() bios_can_module_enter_operation(3)    
#endif
#define bios_can4_enter_operation() bios_can_module_enter_operation(4)      

#define bios_can_module_enter_operation(module) \
    {                                       \
       CAN##module##CTL0_SLPRQ = 0;         \
    while (CAN##module##CTL1_SLPAK != 0);   \
    while (CAN##module##CTL0_SYNCH != 1);   \
    }



#define bios_can_send_msg   bios_can_default_func(send_msg)                 
#define bios_can0_send_msg(msg) bios_can_module_send_msg(0, msg)            
#define bios_can1_send_msg(msg) bios_can_module_send_msg(1, msg)            
#define bios_can2_send_msg(msg) bios_can_module_send_msg(2, msg)            
#ifdef XEP100_ACTIVE
  #define bios_can3_send_msg(msg) bios_can_module_send_msg(3, msg)          
#endif
#define bios_can4_send_msg(msg) bios_can_module_send_msg(4, msg)            

uint8_t bios_can_module_send_msg(uint8_t module, bios_can_msg_typ * DB_RAM_FAR msg);



#ifdef CAN_TX_SW_BUFFER_ENABLE
    uint8_t bios_can_module_send_msg_tx_sw_buffer(uint8_t module, bios_can_msg_typ* DB_RAM_FAR msg);
#endif



#define bios_can_msg_received   bios_can_default_func(msg_received)         
#define bios_can0_msg_received() bios_can_module_msg_received(0)            
#define bios_can1_msg_received() bios_can_module_msg_received(1)            
#define bios_can2_msg_received() bios_can_module_msg_received(2)            
#ifdef XEP100_ACTIVE
  #define bios_can3_msg_received() bios_can_module_msg_received(3)          
#endif
#define bios_can4_msg_received() bios_can_module_msg_received(4)            

uint8_t bios_can_module_msg_received(uint8_t module);



#define bios_can_get_msg   bios_can_default_func(get_msg)                   
#define bios_can0_get_msg(msg) bios_can_module_get_msg(0, msg)              
#define bios_can1_get_msg(msg) bios_can_module_get_msg(1, msg)              
#define bios_can2_get_msg(msg) bios_can_module_get_msg(2, msg)              
#ifdef XEP100_ACTIVE
  #define bios_can3_get_msg(msg) bios_can_module_get_msg(3, msg)            
#endif
#define bios_can4_get_msg(msg) bios_can_module_get_msg(4, msg)              


uint8_t bios_can_module_get_msg(uint8_t module, bios_can_msg_typ *MRS_FAR msg);


#define bios_can_get_msg_id   bios_can_default_func(get_msg_id)             
#define bios_can0_get_msg_id() bios_can_module_get_msg_id(0)                
#define bios_can1_get_msg_id() bios_can_module_get_msg_id(1)                
#define bios_can2_get_msg_id() bios_can_module_get_msg_id(2)                
#ifdef XEP100_ACTIVE
  #define bios_can3_get_msg_id() bios_can_module_get_msg_id(3)              
#endif
#define bios_can4_get_msg_id() bios_can_module_get_msg_id(4)                

uint32_t bios_can_module_get_msg_id(uint8_t module);



#define bios_can_check_error   bios_can_default_func(check_error)           
#define bios_can0_check_error() bios_can_module_check_error(0)              
#define bios_can1_check_error() bios_can_module_check_error(1)              
#define bios_can2_check_error() bios_can_module_check_error(2)              
#ifdef XEP100_ACTIVE
  #define bios_can3_check_error() bios_can_module_check_error(3)            
#endif
#define bios_can4_check_error() bios_can_module_check_error(4)              

uint8_t bios_can_module_check_error(uint8_t module);



#define bios_can_interrupt_ack   bios_can_default_func(interrupt_ack)       
#define bios_can0_interrupt_ack() bios_can_module_interrupt_ack(0)          
#define bios_can1_interrupt_ack() bios_can_module_interrupt_ack(1)          
#define bios_can2_interrupt_ack() bios_can_module_interrupt_ack(2)          
#ifdef XEP100_ACTIVE
  #define bios_can3_interrupt_ack() bios_can_module_interrupt_ack(3)        
#endif
#define bios_can4_interrupt_ack() bios_can_module_interrupt_ack(4)          

void bios_can_module_interrupt_ack(uint8_t module);



#ifdef CAN_TX_SW_BUFFER_ENABLE

void bios_can_module_tx_interrupt_ack(uint8_t module);

uint8_t bios_can_module_set_send_msg_to_queue(uint8_t module, bios_can_msg_typ* msg);

uint8_t bios_can_module_set_msg_to_hw_tx_buffer(uint8_t module, bios_can_msg_typ* msg);

uint8_t bios_can_module_set_send_msg_to_queue(uint8_t module, bios_can_msg_typ* msg);    

uint8_t bios_can_module_start_to_clear_tx_queue(uint8_t module); 

uint8_t bios_can_module_clear_tx_queue_on_int(uint8_t module);

uint8_t bios_can_parameter_to_number(uint8_t p, uint8_t t_seg1, uint8_t t_seg2, uint8_t sj, uint8_t clk_src);




    #pragma DATA_SEG DEFAULT_RAM_EXT

    extern bios_can_msg_typ MRS_FAR bios_can0_tx_msg_queue[];       
    extern uint8_t MRS_FAR bios_can0_tx_msg_queue_beg;              
    extern uint8_t MRS_FAR bios_can0_tx_msg_queue_end;              
    extern uint8_t bios_can0_tx_msg_queue_interrupt_clear_flag;     

    extern bios_can_msg_typ MRS_FAR bios_can1_tx_msg_queue[];       
    extern uint8_t MRS_FAR bios_can1_tx_msg_queue_beg;              
    extern uint8_t MRS_FAR bios_can1_tx_msg_queue_end;              
    extern uint8_t bios_can1_tx_msg_queue_interrupt_clear_flag;     

    extern bios_can_msg_typ MRS_FAR bios_can2_tx_msg_queue[];       
    extern uint8_t MRS_FAR bios_can2_tx_msg_queue_beg;              
    extern uint8_t MRS_FAR bios_can2_tx_msg_queue_end;              
    extern uint8_t bios_can2_tx_msg_queue_interrupt_clear_flag;     

    #ifdef XEP100_ACTIVE
        extern bios_can_msg_typ MRS_FAR bios_can3_tx_msg_queue[];   
        extern uint8_t MRS_FAR bios_can3_tx_msg_queue_beg;          
        extern uint8_t MRS_FAR bios_can3_tx_msg_queue_end;          
        extern uint8_t bios_can3_tx_msg_queue_interrupt_clear_flag; 
    #endif

    extern bios_can_msg_typ MRS_FAR bios_can4_tx_msg_queue[];       
    extern uint8_t MRS_FAR bios_can4_tx_msg_queue_beg;              
    extern uint8_t MRS_FAR bios_can4_tx_msg_queue_end;              
    extern uint8_t bios_can4_tx_msg_queue_interrupt_clear_flag;     

    #pragma DATA_SEG DEFAULT

#endif 



#endif




