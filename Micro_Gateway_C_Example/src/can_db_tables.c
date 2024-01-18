/*--------------------------------------------------------------------------*/
/** \file     can_db_tables.c
*   \brief    CAN bus database
*
*   \date     18/01/2024    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------*/


#include "can_db_tables.h" 
#include "can_db_tables_data.h"



/** \ingroup can_tables
*   \brief           Table of all CAN datapoints
* --------------------------------------------------------------------------*
*                    Every line defines a datapoint within a CAN block.
*                    Every datapoint is assigned to a CAN block ID
*                    #can_block_id, the order of the IDs has to be the same as
*                    the CAN block table #can_block_db_const.
*                    The table contains bit position, bit length and datatype.
*                    The datapoints are used with #can_db_set_value() or #can_db_get_value().
*                    As parameter use the name from the list #can_dp_id verwendet,
*                    the order has to be the same as in this table.
* --------------------------------------------------------------------------*/
 volatile const can_datenpunkt_db_const_typ can_datenpunkt_db_const[CAN_DP_MAX+1] ; // Array can1_....  with the dp of one CAN interface



/** \ingroup can_tables
*   \brief           Table of all CAN blocks
* --------------------------------------------------------------------------*
*                    Every line defines a CAN block and sets the CAN-ID,
*                    the minimal and maximal time between to messages for sending,
*                    the length of a message and the direction (0=Rx, 1=Tx).
*                    The CAN-IDs must be defined in can_db.h.
*                    Every CAN block is assigned to a ID, the order has to be
*                    the same as in this table.
* --------------------------------------------------------------------------*/
 volatile const can_block_db_const_typ can_block_db_const[CAN_BLOCK_MAX+1] ; // Array can1_....  with the CAN blocks of one CAN interface


 volatile const can_bus_db_const_typ can_bus_db_const[CAN_BUS_MAX+1] = 
{
 //                                                                             Manual setting of segment / jumper-with register
 //HW CAN-Modul          HW CAN-Modul active   CAN Baudrate          Gateway Input         {   Name Str.         SJ                    Prescaler             T_SEG1                T_SEG2                CLK_SRC   }           
 //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //(8 Bit)               (8 Bit)               (8 Bit)               (8 Bit)               {   (10 Byte)         (8 Bit)               (8 Bit)               (8 Bit)               (8 Bit)               (8 Bit)               
 //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{  CAN_BUS_0             ,TRUE                 ,BIOS_CAN_EXT_BAUDRATE,IS_NO_GW_INPUT       ,{   "250 kBit"       ,2                    ,2                    ,13                   ,2                    ,0  }  },             
{  CAN_BUS_1             ,FALSE                ,BIOS_CAN_EXT_BAUDRATE,IS_NO_GW_INPUT       ,{   "125 kBit"       ,2                    ,4                    ,13                   ,2                    ,0  }  },             
{  CAN_BUS_2             ,FALSE                ,BIOS_CAN_EXT_BAUDRATE,IS_NO_GW_INPUT       ,{   "125 kBit"       ,2                    ,4                    ,13                   ,2                    ,0  }  },             
{  CAN_BUS_3             ,FALSE                ,BIOS_CAN_EXT_BAUDRATE,IS_NO_GW_INPUT       ,{   "125 kBit"       ,2                    ,4                    ,13                   ,2                    ,0  }  },             
{  CAN_BUS_4             ,TRUE                 ,BIOS_CAN_EXT_BAUDRATE,IS_NO_GW_INPUT       ,{   "250 kBit"       ,2                    ,2                    ,13                   ,2                    ,0  }  },             
};



 volatile const can_gateway_db_const_typ can_gateway_db_const[CAN_GATEWAY_DB_MAX+1]; 




