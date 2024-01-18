#ifndef __BIOS_ADC_H
#define __BIOS_ADC_H


#include "bios_base.h"
#include "Cpu.h"
#include "os_io.h"




#define ADC_TYPE_V2 0  
#define ADC_TYPE_V1 1  


#define AD1_EnableTrigger AD1_EnableExtChanTrigger      
#define AD1_DisableTrigger AD1_Stop                     





#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void AD1_Interrupt(void);

__interrupt void AD2_Interrupt(void);

#pragma CODE_SEG DEFAULT


byte AD1_Enable(void);

byte AD2_Enable(void);


byte AD1_Disable(void);

byte AD2_Disable(void);


byte AD1_Start(void);


byte AD2_Start(void);


byte AD1_Stop(void);

byte AD2_Stop(void);


byte AD1_Measure(bool WaitForResult);

byte AD2_Measure(bool WaitForResult);


byte AD1_MeasureChan(bool WaitForResult,byte Channel);
byte AD2_MeasureChan(bool WaitForResult,byte Channel);

byte AD1_GetValue16(word *Values);
byte AD2_GetValue16(word *Values);


byte AD1_GetChanValue16(byte Channel,word *Value);

byte AD2_GetChanValue16(byte Channel,word *Value);

void AD1_Init(void);
void AD2_Init(void);



#endif 


