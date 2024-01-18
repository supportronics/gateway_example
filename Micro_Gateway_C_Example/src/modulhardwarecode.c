//--------------------------------------------------------------------------
/// \file     modulhardwarecode.c
/// \brief    Multiplexen der HSD-Statuswerte. Dazu muss per CS_DIS vom HSD
///           so umgeschalten werden, dass die Werte des HSD1 statt HSD0 
///           gelesen werden.
/// \author   dr/
/// \date     22.08.2011
/// \version  1.00
//--------------------------------------------------------------------------
#include "bios.h"
#include "os.h"

#define SW_SCI_OFF() SCI0CR2 &= ( (~SCI0CR2_RE_MASK) & (~SCI0CR2_TE_MASK) & (~SCI0CR2_TIE_MASK) & (~SCI0CR2_RIE_MASK) & (~SCI0CR2_TCIE_MASK) & (~SCI0CR2_ILIE_MASK));

#define SW_SCI_ON()  SCI0CR2 |= ( SCI0CR2_TE_MASK | SCI0CR2_RE_MASK | SCI0CR2_RIE_MASK );

void modulhardwarecode (void) {                    
}


void modulhardwarecode_adc_multiplex(uint8 multiplex_nr) { 
}


void modulhardwarecode_timer(void) { 
}


void modulhardwarecode_sleep(void) 
{       
    DisableInterrupts;                            
    
    os_pin_write(DO_LIN_EN, 1);
    SW_SCI_ON(); 
    
    (void)Start_wait(30); // 1ms warten // os_wait() nicht möglich da Interrupts deaktiviert.
    
    os_pin_write(DO_LIN_EN, 0);
    
    os_pin_write(DO_CAN1_STB_N, 0);
    os_pin_write(DO_CAN2_STB_N, 0);
          
    (void)Start_wait(30); // 1ms warten
    os_pin_write(DO_CAN1_EN, 0);
    os_pin_write(DO_CAN2_EN, 0);
    
    os_pin_write(DO_POWER, 0);
    
    (void)Start_wait(7000); // Zur Sicerheit ca. 200ms auf Sleep warten

    // Notstrategie, falls nicht erfolgreich
    os_pin_write(DO_POWER, 1);
    
    os_pin_write(DO_CAN1_STB_N, 1);
    os_pin_write(DO_CAN2_STB_N, 1);
    os_pin_write(DO_CAN1_EN, 1);
    os_pin_write(DO_CAN2_EN, 1);
    
    EnableInterrupts;      
}


void modulhardwarecode_init(void)
{
    // MODRR setzt schon der Bootloader. Für Standalone wird es hier nochmal gesetzt.
    // CAN4 (für MC_CAN1) auf PM4, PM5 legen
    MODRR_MODRR2 = 1;
    MODRR_MODRR3 = 0;
          
    // CAN0 (für MC_CAN2) auf PM2, PM3 legen
    MODRR_MODRR0 = 1;
    MODRR_MODRR1 = 0;
    
    os_pin_write(DO_CAN1_WAKE, 1);
    os_pin_write(DO_CAN2_WAKE, 1);
    (void)Start_wait(5);
    os_pin_write(DO_CAN1_WAKE, 0);        
    os_pin_write(DO_CAN2_WAKE, 0);
 }
