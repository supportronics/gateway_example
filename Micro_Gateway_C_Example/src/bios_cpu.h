#ifndef _BIOS_CPU_H_
#define _BIOS_CPU_H_


#include "bios_base.h"
#include "Cpu.h"      



#define CLK_SEL_50MHZ   





void bios_init_cpu_clock(void);



void bios_disable_watchdog(void);


void bios_enable_watchdog(void);


void bios_reset_watchdog(void);


#endif
