#ifndef _BIOS_INTERRUPTS_H_
#define _BIOS_INTERRUPTS_H_



#include "bios.h"
#include "can_db.h"
#include "PE_Types.h"
#include "bios_can.h"



#define CAN0_RX  0              
#define CAN1_RX  1              
#define CAN2_RX  2              
#define CAN3_RX  3              
#define CAN4_RX  3              


extern uint8 can_any_received_flg[];    




#pragma CODE_SEG __NEAR_SEG NON_BANKED

ISR(TI1_Interrupt);             
ISR(TI2_Interrupt);             
ISR(TI3_Interrupt);             
ISR(TI4_Interrupt);             

ISR(ECT_CH0_Interrupt);         
ISR(ECT_CH1_Interrupt);         
ISR(ECT_CH2_Interrupt);         
ISR(ECT_CH3_Interrupt);         
ISR(ECT_CH4_Interrupt);         
ISR(ECT_CH5_Interrupt);         
ISR(ECT_CH6_Interrupt);         
ISR(ECT_CH7_Interrupt);         
ISR(ECT_Ovf_Interrupt);         

ISR(CAN0_Interrupt);            
ISR(CAN1_Interrupt);            
ISR(CAN2_Interrupt);            
ISR(CAN3_Interrupt);            
ISR(CAN4_Interrupt);            

ISR(CAN0_Interrupt_tx);         
ISR(CAN1_Interrupt_tx);         
ISR(CAN2_Interrupt_tx);         
ISR(CAN3_Interrupt_tx);         
ISR(CAN4_Interrupt_tx);         

ISR(CAN0_Interrupt_Error);      
ISR(CAN1_Interrupt_Error);      
ISR(CAN2_Interrupt_Error);      
ISR(CAN3_Interrupt_Error);      
ISR(CAN4_Interrupt_Error);      

ISR(SCI0_Interrupt);            
ISR(SCI1_Interrupt);            
ISR(SCI2_Interrupt);            
ISR(SCI3_Interrupt);            
ISR(SCI4_Interrupt);            
ISR(SCI5_Interrupt);            
ISR(SCI6_Interrupt);            
ISR(SCI7_Interrupt);            

ISR(PortP_Interrupt);           
ISR(PortH_Interrupt);           
ISR(PortJ_Interrupt);           

ISR(real_time_Interrupt);       


#pragma CODE_SEG DEFAULT
#endif

