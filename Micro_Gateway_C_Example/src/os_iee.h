#ifndef __OS_IEE_H
#define __OS_IEE_H



#include "CAN_HCS12_BL.h"
#include "EE_RAM.h"  


#define KENNER_PROP_V1          28071   
#define KENNER_PROP_V2          28072   
#define KENNER_CAN_IO           28341   
#define KENNER_CAN_IO_V2        28073   
#define KENNER_CAN_IO_PRO_WP    28074   
#define KENNER_M2600            28075   
#define KENNER_M2600_WOINA      28087   


void os_eeprom_read_all(uint8 choice);

void os_eeprom_write_all(uint8 choice);



uint8 os_eeprom_read_data(uint16 Addr, uint8 *Data, uint16 Size);


uint8 os_eeprom_write_data(uint16 Addr, uint8 *Data, uint16 Size);


#endif

