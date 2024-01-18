#ifndef __bios_flash
#define __bios_flash



#include "Cpu.h"




#ifndef __BWUserType_bios_flash_TAddress
#define __BWUserType_bios_flash_TAddress
typedef dword bios_flash_TAddress;       
#endif
#ifndef __BWUserType_bios_flash_TDataAddress
#define __BWUserType_bios_flash_TDataAddress
typedef byte *bios_flash_TDataAddress;    
#endif

#define flash_addr bios_flash_TAddress
#define flash_data_addr bios_flash_TDataAddress


#define bios_flash_AREA_0_START              0x780000   
#define bios_flash_AREA_0_SIZE               0x20000    
#define bios_flash_AREA_0_END                0x79FFFF   
#define bios_flash_AREA_0_SECTOR_SIZE        0x400      
#define bios_flash_AREA_1_START              0x7C0000   
#define bios_flash_AREA_1_SIZE               0x40000    
#define bios_flash_AREA_1_END                0x7FFFFF   
#define bios_flash_AREA_1_SECTOR_SIZE        0x400      
#define bios_flash_AREA_COUNT                2U         
#define bios_flash_AREA_SECTOR_SIZE          0x400      
#define bios_flash_PROGRAMMING_PHRASE        (8U)       
#define bios_flash_ALLOW_CLEAR               (FALSE)    
#define bios_flash_DummyData                 0x10       


#define bios_flash_EraseFlash(Block) bios_flash_EraseFlash_(Block) 




byte bios_flash_SetBlockFlash(bios_flash_TDataAddress Source, bios_flash_TAddress Addr, word Count);


byte WriteWord(bios_flash_TAddress Addr,word Data16); 


byte bios_flash_SetGlobalProtection(bool ProtectAll); 


byte bios_flash_EraseFlash_(byte Block);


void bios_flash_Init(void);  


byte bios_flash_SetByteFlash(bios_flash_TAddress Addr,byte Data); 


byte bios_flash_GetByteFlash(bios_flash_TAddress Addr,byte *Data);   


byte bios_flash_SetWordFlash(bios_flash_TAddress Addr,word Data);


byte bios_flash_GetWordFlash(bios_flash_TAddress Addr,word *Data);  


byte bios_flash_EraseSector(bios_flash_TAddress Addr);


bios_flash_TAddress bios_flash_DataPtr2Addr(void *far Addr); 


bios_flash_TAddress bios_flash_FuncPtr2Addr(void(*far Addr)()); 





#endif 



