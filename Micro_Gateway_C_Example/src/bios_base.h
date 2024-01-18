#ifndef _BIOS_BASE_H_
#define _BIOS_BASE_H_


#include <hidef.h>          
#include "PE_Types.h"       
#include "PE_Error.h"
#include <MC9S12XEP100.h>



typedef uint8_t    uint8;   
typedef int8_t      int8;   
typedef uint16_t  uint16;   
typedef int16_t    int16;   
typedef uint32_t  uint32;   
typedef int32_t    int32;   


#define bios_disable_interrupts()   DisableInterrupts   
#define bios_enable_interrupts()    EnableInterrupts    

#define bios_enter_critical()       { __asm pshc; __asm sei; __asm movb 1,SP+,CCR_reg; } 



#define bios_exit_critical()        { __asm movb CCR_reg, 1,-SP; __asm pulc; } 


#define BIOS_MRS_USE_FAR 1  


#ifdef BIOS_MRS_USE_FAR
#define MRS_FAR __far    
#endif





#ifdef CAN_BLOCK_DB_RAM_EXT
    #define DB_RAM_FAR MRS_FAR      
#else
    #define DB_RAM_FAR              
#endif
#endif

