#ifndef _CAN_DB_TABLES_DATA_H_
#define _CAN_DB_TABLES_DATA_H_





#include "can_db_tables.h"
#include "bios.h"

#include "user_code.h"


extern uint8  dyn_CAN_FILTER_SETTING; 
extern uint32 dyn_CAN_FILTER[];
extern uint32 dyn_CAN_MASK[];


typedef struct
{  
  uint8 bus_id_in;
  uint8 bus_id_out;
} can_gateway_db_const_typ;
extern volatile const can_gateway_db_const_typ can_gateway_db_const[];  


typedef struct
{
    uint32  filter[2];    
    uint32  mask[2];    
    uint8   mask_division;
} can_db_filter_typ;


typedef struct
{
    uint16   DP_MAX;
    uint8    BUS_MAX;
    uint16   BLOCK_MAX;
    uint8    BLOCK_USER_MAX;  
    uint8    GATEWAY_DB_MAX;  
    uint16   BAUDRATE;
    uint8    BUS_1;
    uint8    user_filter_active;
    uint8    can_gw_route;
    uint8    sa_active;         
    uint8    sa_db;             
    uint8    sa_val;            
    uint16   sa_db_rx;          
    uint16   sa_val_rx;         
    can_db_filter_typ f_set[5];
} can_db_typ;


typedef struct {
  uint8  hw_module_id;            
  uint8  hw_module_active;        
  uint8  bios_baudrate_id;        
  uint8  gw_input;                
  bios_can_baudrate_typ baudrate; 
} can_bus_db_const_typ;
extern volatile const can_bus_db_const_typ can_bus_db_const[];



typedef struct {
  uint8  bus_id;                  
  uint32 can_id;                  
  uint8  can_id_ext;              
  uint32 zykluszeit_ms_max;       
  uint32 zykluszeit_ms_min;       
  uint8  msg_len_dlc;             
  uint8  tx;		              
  uint8  can_bus_gw;              
  uint32 can_id_mask;             
  uint8  mux_start;               
  uint8  mux_length;              
  uint8  mux_val;                 
} can_block_db_const_typ;

extern volatile const can_block_db_const_typ can_block_db_const[];


typedef struct {
  can_block_id nr_can_block;      
  uint8  pos_bit_0;               
  uint8  bit_laenge;              
  uint8  datentyp;                
  uint8  data_format;             
} can_datenpunkt_db_const_typ;



extern volatile const can_datenpunkt_db_const_typ can_datenpunkt_db_const[];



typedef struct {
  uint8  last_data[8];          
  uint32 time_stamp_read;
  uint32 time_stamp_write;
  uint32 time_stamp_transmit;
  uint8  received       :1;
  uint8  transmit       :1; 
  uint8  transmit_stop  :1; 
  bios_can_msg_typ msg;
} can_block_db_ram_typ;


typedef struct {
  uint8  can_id_active;           
  uint8  bus_id;                  
  uint32 can_id;                  
  uint8  can_id_ext;              
  uint32 can_id_mask;             
}can_block_db_user_typ;



extern can_db_typ can_db;    

#ifdef CAN_BLOCK_DB_RAM_EXT
    #pragma DATA_SEG DEFAULT_RAM_EXT
#endif
extern can_block_db_ram_typ DB_RAM_FAR can_block_db_ram[];     
#pragma DATA_SEG DEFAULT

extern can_block_db_user_typ can_block_db_user[];   

extern uint8 can_bus_db_disable[];


#define   dyn_CAN_DP_MAX                can_db.DP_MAX
#define   dyn_CAN_BUS_MAX               can_db.BUS_MAX
#define   dyn_CAN_BLOCK_MAX             can_db.BLOCK_MAX
#define   dyn_CAN_BLOCK_USER_MAX        can_db.BLOCK_USER_MAX
#define   dyn_CAN_BAUDRATE              can_db.BAUDRATE
#define   dyn_CAN_BUS_1                 can_db.BUS_1

#define   dyn_OS_PORT_INPUT_PIN_MAX     os_io->PORT_INPUT_PIN_MAX
#define   dyn_OS_PORT_PIN_MAX           os_io->PORT_PIN_MAX
#define   dyn_OS_ANALOG_PIN_MAX         os_io->PORT_ANALOG_PIN_MAX


void can_db_tables_data_init(void);

void can_db_tables_set_tx_wait( uint16_t value );


uint16_t can_tables_get_tx_wait( void );



#endif


