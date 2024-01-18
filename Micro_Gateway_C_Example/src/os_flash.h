#ifndef _OS_FLASH_H_
#define _OS_FLASH_H_


#include "bios_flash.h"

#define OS_FLASH_AREA_START              0x790000   
#define OS_FLASH_AREA_SIZE               0xFFFF     
#define OS_FLASH_AREA_END                0x79FFFF   





byte os_flash_erase_sector(flash_addr Addr);

byte os_flash_write_word(flash_addr Addr, word data);

byte os_flash_write_block( flash_addr Addr, flash_data_addr source, word number);

byte os_flash_read_word(flash_addr Addr, word *data);





#endif

