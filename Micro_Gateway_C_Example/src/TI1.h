
#ifndef __TI1
#define __TI1


#include "Cpu.h"


#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TI1_Interrupt(void);

#pragma CODE_SEG DEFAULT


#endif 

