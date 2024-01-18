#ifndef __Cpu
#define __Cpu

#define PEcfg_XEQ384CAG 1                       


#include "bios_base.h"







#pragma DATA_SEG DEFAULT

#define CPU_BUS_CLK_HZ              25000000UL  
#define CPU_INSTR_CLK_HZ            25000000UL  
#define CPU_EXT_CLK_HZ              4000000UL   

#define CPU_CORE_HCS12X                         
#define CPU_DERIVATIVE_MC9S12XEQ384             
#define CPU_PARTNUM_MC9S12XEQ384CAG             


extern volatile byte CCR_reg;                   

#pragma CODE_SEG __NEAR_SEG NON_BANKED



void _EntryPoint(void);


__interrupt void Cpu_Interrupt(void);



#pragma CODE_SEG DEFAULT

#define Cpu_SetStopMode()  { __asm("ANDCC #0x7F"); __asm("STOP"); }     
#define Cpu_SetWaitMode()   __asm("WAI")                                
#define Cpu_DisableInt()    __DI()                                      
#define Cpu_EnableInt()     __EI()                                      


void PE_low_level_init(void);


void check_ram_test(void);

extern void ram_test(void);


#endif 

