
#include "can_db_tables_data.h"


static uint16_t bios_can_tx_buffer_full_wait = 1000;




can_db_typ can_db;


#ifdef CAN_BLOCK_DB_RAM_EXT
    #pragma DATA_SEG DEFAULT_RAM_EXT
#endif


can_block_db_ram_typ MRS_FAR can_block_db_ram[CAN_BLOCK_MAX+1];    
#pragma DATA_SEG DEFAULT

uint8 can_bus_db_disable[CAN_BUS_MAX+1];  


#define CAN_BLOCK_USER_MAX  0
can_block_db_user_typ can_block_db_user[CAN_BLOCK_USER_MAX+1];




extern void put_signal_value_to_data_block(uint32 value, uint8* MRS_FAR data_can_block, uint8 startbit, uint8 laenge, uint8 data_format);

#pragma DATA_SEG DEFAULT_RAM_EXT

#if OS_CAN0_ENABLE_MSG_QUEUE_A_B
    bios_can_msg_typ MRS_FAR os_can0_msg_queue_A[OS_CAN0_MSG_QUEUE_A_SIZE];
    bios_can_msg_typ MRS_FAR os_can0_msg_queue_B[OS_CAN0_MSG_QUEUE_B_SIZE];
#endif
#if OS_CAN1_ENABLE_MSG_QUEUE_A_B
    bios_can_msg_typ MRS_FAR os_can1_msg_queue_A[OS_CAN1_MSG_QUEUE_A_SIZE];
    bios_can_msg_typ MRS_FAR os_can1_msg_queue_B[OS_CAN1_MSG_QUEUE_B_SIZE];
#endif    
#if OS_CAN2_ENABLE_MSG_QUEUE_A_B
    bios_can_msg_typ MRS_FAR os_can2_msg_queue_A[OS_CAN2_MSG_QUEUE_A_SIZE];
    bios_can_msg_typ MRS_FAR os_can2_msg_queue_B[OS_CAN2_MSG_QUEUE_B_SIZE];
#endif 
#ifdef XEP100_ACTIVE
  #if OS_CAN3_ENABLE_MSG_QUEUE_A_B
      bios_can_msg_typ MRS_FAR os_can3_msg_queue_A[OS_CAN3_MSG_QUEUE_A_SIZE];
      bios_can_msg_typ MRS_FAR os_can3_msg_queue_B[OS_CAN3_MSG_QUEUE_B_SIZE];
  #endif
#endif
#if OS_CAN4_ENABLE_MSG_QUEUE_A_B
    bios_can_msg_typ MRS_FAR os_can4_msg_queue_A[OS_CAN4_MSG_QUEUE_A_SIZE];
    bios_can_msg_typ MRS_FAR os_can4_msg_queue_B[OS_CAN4_MSG_QUEUE_B_SIZE];
#endif



uint8 MRS_FAR dyn_OS_CAN0_MSG_QUEUE_A_SIZE;
uint8 MRS_FAR dyn_OS_CAN0_MSG_QUEUE_B_SIZE;
uint8 MRS_FAR dyn_OS_CAN1_MSG_QUEUE_A_SIZE;
uint8 MRS_FAR dyn_OS_CAN1_MSG_QUEUE_B_SIZE;
uint8 MRS_FAR dyn_OS_CAN2_MSG_QUEUE_A_SIZE;
uint8 MRS_FAR dyn_OS_CAN2_MSG_QUEUE_B_SIZE;
uint8 MRS_FAR dyn_OS_CAN3_MSG_QUEUE_A_SIZE;
uint8 MRS_FAR dyn_OS_CAN3_MSG_QUEUE_B_SIZE;
uint8 MRS_FAR dyn_OS_CAN4_MSG_QUEUE_A_SIZE;
uint8 MRS_FAR dyn_OS_CAN4_MSG_QUEUE_B_SIZE;

#pragma DATA_SEG DEFAULT



bios_can_baudrate_typ can_db_baudrate;

void can_db_tables_data_init_baudrate(int8* name, uint8 sj, uint8 pre, uint8 t_seg1, uint8 t_seg2)
{ 
    uint8 i;   

    for( i = 0; i < BIOS_CAN_BAUDRATE_NAME_LEN; ++i )
    {
        if( name[i] != 0 ) 
        {
            can_db_baudrate.name[i] = name[i];
        }  
        else
        {
            break;
        }  
    }  

    while( i < BIOS_CAN_BAUDRATE_NAME_LEN )    
    {
        can_db_baudrate.name[i] = 0; 
        i++;
    }

    can_db_baudrate.name[BIOS_CAN_BAUDRATE_NAME_LEN] = 0; 

    can_db_baudrate.sj = sj;        
    can_db_baudrate.pre = pre;      
    can_db_baudrate.t_seg1 = t_seg1;
    can_db_baudrate.t_seg2 = t_seg2;

    bios_can_set_ext_baudrate(&can_db_baudrate);
    return;
}


void can_create_mask(uint8 bus_id, uint32* mask, uint32* filter, uint8 *mask_division) 
{

  #ifdef USER_CAN_FILTER_ACTIVE

    can_create_mask_simple(bus_id, mask, filter, mask_division);  

  #else

    uint32 addr_id[2][CAN_BLOCK_MAX+20];
    uint32 addr_mask[2][CAN_BLOCK_MAX+20];  

    dyn_can_create_mask(bus_id,  mask, filter, mask_division, (uint32*)addr_id,  (uint32*)addr_mask, CAN_BLOCK_MAX+20); 

  #endif

}




#define MACRO_DEFINE_TO_STR(arg) #arg

void can_db_tables_data_init(void)
{  
    uint16 i;

    can_db.DP_MAX               = CAN_DP_MAX;
    can_db.BUS_MAX              = CAN_BUS_MAX;
    can_db.BLOCK_MAX            = CAN_BLOCK_MAX;
    can_db.BLOCK_USER_MAX       = CAN_BLOCK_USER_MAX;
    can_db.GATEWAY_DB_MAX       = CAN_GATEWAY_DB_MAX; 
    can_db.BAUDRATE             = CAN_BAUDRATE;
    can_db.BUS_1                = CAN_BUS_1;        

    #ifdef USER_CAN_FILTER_ACTIVE 
      can_db.user_filter_active = 1;
      can_db.f_set[0].filter[0] = CAN0_FILTER_A;
      can_db.f_set[0].filter[1] = CAN0_FILTER_B;
      can_db.f_set[0].mask[0]   = CAN0_MASK_A;
      can_db.f_set[0].mask[1]   = CAN0_MASK_B;
      can_db.f_set[0].mask_division = CAN0_MASK_DIVISION;      

      can_db.f_set[1].filter[0] = CAN1_FILTER_A;
      can_db.f_set[1].filter[1] = CAN1_FILTER_B;
      can_db.f_set[1].mask[0]   = CAN1_MASK_A;
      can_db.f_set[1].mask[1]   = CAN1_MASK_B;
      can_db.f_set[1].mask_division = CAN1_MASK_DIVISION;

      can_db.f_set[2].filter[0] = CAN2_FILTER_A;
      can_db.f_set[2].filter[1] = CAN2_FILTER_B;
      can_db.f_set[2].mask[0]   = CAN2_MASK_A;
      can_db.f_set[2].mask[1]   = CAN2_MASK_B;
      can_db.f_set[2].mask_division = CAN2_MASK_DIVISION;

      can_db.f_set[3].filter[0] = CAN3_FILTER_A;
      can_db.f_set[3].filter[1] = CAN3_FILTER_B;
      can_db.f_set[3].mask[0]   = CAN3_MASK_A;
      can_db.f_set[3].mask[1]   = CAN3_MASK_B;
      can_db.f_set[3].mask_division = CAN3_MASK_DIVISION;

      can_db.f_set[4].filter[0] = CAN4_FILTER_A;
      can_db.f_set[4].filter[1] = CAN4_FILTER_B;
      can_db.f_set[4].mask[0]   = CAN4_MASK_A;
      can_db.f_set[4].mask[1]   = CAN4_MASK_B;
      can_db.f_set[4].mask_division = CAN4_MASK_DIVISION;            

    #else
      can_db.user_filter_active = 0;
    #endif

    can_db_tables_data_init_baudrate(
        MACRO_DEFINE_TO_STR(CAN_BAUDRATE_def_BEZEICHNUNG),
                            CAN_BAUDRATE_def_sj,
                            CAN_BAUDRATE_def_pre,
                            CAN_BAUDRATE_def_t_seg1,
                            CAN_BAUDRATE_def_t_seg2);


    #ifdef CAN_GW_MODE_ROUTE
        can_db.can_gw_route = 1;
    #endif


    dyn_OS_CAN0_MSG_QUEUE_A_SIZE = OS_CAN0_MSG_QUEUE_A_SIZE;
    dyn_OS_CAN0_MSG_QUEUE_B_SIZE = OS_CAN0_MSG_QUEUE_B_SIZE;
    dyn_OS_CAN1_MSG_QUEUE_A_SIZE = OS_CAN1_MSG_QUEUE_A_SIZE;
    dyn_OS_CAN1_MSG_QUEUE_B_SIZE = OS_CAN1_MSG_QUEUE_B_SIZE;
    dyn_OS_CAN2_MSG_QUEUE_A_SIZE = OS_CAN2_MSG_QUEUE_A_SIZE;
    dyn_OS_CAN2_MSG_QUEUE_B_SIZE = OS_CAN2_MSG_QUEUE_B_SIZE;
    dyn_OS_CAN3_MSG_QUEUE_A_SIZE = OS_CAN3_MSG_QUEUE_A_SIZE;
    dyn_OS_CAN3_MSG_QUEUE_B_SIZE = OS_CAN3_MSG_QUEUE_B_SIZE;
    dyn_OS_CAN4_MSG_QUEUE_A_SIZE = OS_CAN4_MSG_QUEUE_A_SIZE;
    dyn_OS_CAN4_MSG_QUEUE_B_SIZE = OS_CAN4_MSG_QUEUE_B_SIZE;

    for (i=0;i<can_db.BLOCK_MAX;i++)
    {
        if (can_block_db_const[i].mux_length)
        {  
            put_signal_value_to_data_block(can_block_db_const[i].mux_val, can_block_db_ram[i].msg.data, can_block_db_const[i].mux_start, can_block_db_const[i].mux_length, DF_INTEL);                      
        }
    }


    return;
}


void can_db_tables_set_tx_wait( uint16_t value )
{
     bios_can_tx_buffer_full_wait = value;
}


#pragma INLINE
uint16_t can_tables_get_tx_wait( void )
{
	  return bios_can_tx_buffer_full_wait;
}



