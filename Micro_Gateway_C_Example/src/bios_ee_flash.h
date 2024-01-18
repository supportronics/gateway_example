#ifndef _BIOS_EE_FLASH_H_
#define _BIOS_EE_FLASH_H_





#include "bios_base.h"



#define BIOS_FLASH_SEG_EEPROM                   0x10000         
#define BIOS_FLASH_LAENGE_EEPROM                0x0300          
#define BIOS_MAX_RAM_BLOCK_SIZE                 0x0100          

#define BIOS_RAM_ADRESS_BEREICH_UEBERSCHRITTEN  1               
#define BIOS_FLASH_SCHREIB_FEHLER               2               
#define bios_init_flash                         bios_flash_init 





typedef uint8* far bios_ee_flash_ptr; 
typedef uint8*     bios_ee_ram_ptr;   


typedef struct
{
   const bios_ee_flash_ptr flash_ptr;    
   const bios_ee_ram_ptr ram_ptr;        
   uint16 flash_block_size;              
   uint16 max_ram_block_size;            
   uint16 ram_block_size;                
}bios_ee_config_typ;





void bios_flash_wb(bios_ee_flash_ptr data_ptr, uint8 data);


void bios_flash_clr(bios_ee_flash_ptr data_ptr);



void bios_flash_init(void);

#endif

