#ifndef _BIOS_SCI_H_
#define _BIOS_SCI_H_



#include "bios_base.h"
#include "bios_cpu.h"



#define BIOS_SCI_MODUL_DEFAULT              1



#define BIOS_SCI_4800_BAUD                  4800                    
#define BIOS_SCI_9600_BAUD                  9600                    
#define BIOS_SCI_19200_BAUD                 19200                   
#define BIOS_SCI_28800_BAUD                 28800                   
#define BIOS_SCI_38400_BAUD                 38400                   
#define BIOS_SCI_115200_BAUD                115200                  


#define BIOS_SCI_8N1                        1                       
#define BIOS_SCI_9N1                        2                       


#define BIOS_SCI_SET_BREAK_LEN              0                       
#define BIOS_SCI_SET_BREAK_LEN_AND_INT_DETECTION    1               

#define BIOS_SCI_BREAK_LEN_10_11            0                       
#define BIOS_SCI_BREAK_LEN_13_14            1                       

#define BIOS_SCI_INT_TDR_EMPTY              (uint16_t)0x0001        
#define BIOS_SCI_INT_TX_COMPLETE            (uint16_t)0x0002        
#define BIOS_SCI_INT_RDR_FULL               (uint16_t)0x0004        
#define BIOS_SCI_INT_IDLE_LINE              (uint16_t)0x0008        
#define BIOS_SCI_INT_RX_OVERRUN             (uint16_t)0x0010        
#define BIOS_SCI_INT_RX_ACTIVE_EDGE         (uint16_t)0x0020        
#define BIOS_SCI_INT_RX_BIT_ERROR           (uint16_t)0x0040        
#define BIOS_SCI_INT_RX_BREAK_DETECT        (uint16_t)0x0080        
#define BIOS_SCI_INT_RX_NOISE               (uint16_t)0x0100        
#define BIOS_SCI_INT_RX_FRAMING_ERROR       (uint16_t)0x0200        
#define BIOS_SCI_INT_RX_PARITY_ERROR        (uint16_t)0x0400        


#define BIOS_SCI_BD_SBR0_MASK               SCI0BD_SBR0_MASK        
#define BIOS_SCI_BD_SBR1_MASK               SCI0BD_SBR1_MASK        
#define BIOS_SCI_BD_SBR2_MASK               SCI0BD_SBR2_MASK        
#define BIOS_SCI_BD_SBR3_MASK               SCI0BD_SBR3_MASK        
#define BIOS_SCI_BD_SBR4_MASK               SCI0BD_SBR4_MASK        
#define BIOS_SCI_BD_SBR5_MASK               SCI0BD_SBR5_MASK        
#define BIOS_SCI_BD_SBR6_MASK               SCI0BD_SBR6_MASK        
#define BIOS_SCI_BD_SBR7_MASK               SCI0BD_SBR7_MASK        
#define BIOS_SCI_BD_SBR8_MASK               SCI0BD_SBR8_MASK        
#define BIOS_SCI_BD_SBR9_MASK               SCI0BD_SBR9_MASK        
#define BIOS_SCI_BD_SBR10_MASK              SCI0BD_SBR10_MASK       
#define BIOS_SCI_BD_SBR11_MASK              SCI0BD_SBR11_MASK       
#define BIOS_SCI_BD_SBR12_MASK              SCI0BD_SBR12_MASK       
#define BIOS_SCI_BD_TNP0_MASK               SCI0BD_TNP0_MASK        
#define BIOS_SCI_BD_TNP1_MASK               SCI0BD_TNP1_MASK        
#define BIOS_SCI_BD_IREN_MASK               SCI0BD_IREN_MASK        
#define BIOS_SCI_BD_SBR_MASK                SCI0BD_SBR_MASK         
#define BIOS_SCI_BD_SBR_BITNUM              SCI0BD_SBR_BITNUM       
#define BIOS_SCI_BD_TNP_MASK                SCI0BD_TNP_MASK         
#define BIOS_SCI_BD_TNP_BITNUM              SCI0BD_TNP_BITNUM       

#define BIOS_SCI_ASR1_BKDIF_MASK            SCI0ASR1_BKDIF_MASK     
#define BIOS_SCI_ASR1_BERRIF_MASK           SCI0ASR1_BERRIF_MASK    
#define BIOS_SCI_ASR1_BERRV_MASK            SCI0ASR1_BERRV_MASK     
#define BIOS_SCI_ASR1_RXEDGIF_MASK          SCI0ASR1_RXEDGIF_MASK   

#define BIOS_SCI_ACR1_BKDIE_MASK            SCI0ACR1_BKDIE_MASK     
#define BIOS_SCI_ACR1_BERRIE_MASK           SCI0ACR1_BERRIE_MASK    
#define BIOS_SCI_ACR1_RXEDGIE_MASK          SCI0ACR1_RXEDGIE_MASK   

#define BIOS_SCI_ACR2_BKDFE_MASK            SCI0ACR2_BKDFE_MASK     
#define BIOS_SCI_ACR2_BERRM0_MASK           SCI0ACR2_BERRM0_MASK    
#define BIOS_SCI_ACR2_BERRM1_MASK           SCI0ACR2_BERRM1_MASK    
#define BIOS_SCI_ACR2_BERRM_MASK            SCI0ACR2_BERRM_MASK     
#define BIOS_SCI_ACR2_BERRM_BITNUM          SCI0ACR2_BERRM_BITNUM   

#define BIOS_SCI_CR1_PT_MASK                SCI0CR1_PT_MASK         
#define BIOS_SCI_CR1_PE_MASK                SCI0CR1_PE_MASK         
#define BIOS_SCI_CR1_ILT_MASK               SCI0CR1_ILT_MASK        
#define BIOS_SCI_CR1_WAKE_MASK              SCI0CR1_WAKE_MASK       
#define BIOS_SCI_CR1_M_MASK                 SCI0CR1_M_MASK          
#define BIOS_SCI_CR1_RSRC_MASK              SCI0CR1_RSRC_MASK       
#define BIOS_SCI_CR1_SCISWAI_MASK           SCI0CR1_SCISWAI_MASK    
#define BIOS_SCI_CR1_LOOPS_MASK             SCI0CR1_LOOPS_MASK      

#define BIOS_SCI_CR2_SBK_MASK               SCI0CR2_SBK_MASK        
#define BIOS_SCI_CR2_RWU_MASK               SCI0CR2_RWU_MASK        
#define BIOS_SCI_CR2_RE_MASK                SCI0CR2_RE_MASK         
#define BIOS_SCI_CR2_TE_MASK                SCI0CR2_TE_MASK         
#define BIOS_SCI_CR2_ILIE_MASK              SCI0CR2_ILIE_MASK       
#define BIOS_SCI_CR2_RIE_MASK               SCI0CR2_RIE_MASK        
#define BIOS_SCI_CR2_TCIE_MASK              SCI0CR2_TCIE_MASK       
#define BIOS_SCI_CR2_TIE_MASK               SCI0CR2_TIE_MASK        

#define BIOS_SCI_SR1_PF_MASK                SCI0SR1_PF_MASK         
#define BIOS_SCI_SR1_FE_MASK                SCI0SR1_FE_MASK         
#define BIOS_SCI_SR1_NF_MASK                SCI0SR1_NF_MASK         
#define BIOS_SCI_SR1_OR_MASK                SCI0SR1_OR_MASK         
#define BIOS_SCI_SR1_IDLE_MASK              SCI0SR1_IDLE_MASK       
#define BIOS_SCI_SR1_RDRF_MASK              SCI0SR1_RDRF_MASK       
#define BIOS_SCI_SR1_TC_MASK                SCI0SR1_TC_MASK         
#define BIOS_SCI_SR1_TDRE_MASK              SCI0SR1_TDRE_MASK       

#define BIOS_SCI_SR2_RAF_MASK               SCI0SR2_RAF_MASK        
#define BIOS_SCI_SR2_TXDIR_MASK             SCI0SR2_TXDIR_MASK      
#define BIOS_SCI_SR2_BRK13_MASK             SCI0SR2_BRK13_MASK      
#define BIOS_SCI_SR2_RXPOL_MASK             SCI0SR2_RXPOL_MASK      
#define BIOS_SCI_SR2_TXPOL_MASK             SCI0SR2_TXPOL_MASK      
#define BIOS_SCI_SR2_AMAP_MASK              SCI0SR2_AMAP_MASK       


#ifdef CLK_SEL_50MHZ
    #define CPU_BUSCLK                      50000000UL              
#else
    #define CPU_BUSCLK                      25000000UL              
#endif



typedef enum
{
    BIOS_SCI0 = 0,                                      
    BIOS_SCI1,                                          
    BIOS_SCI2,                                          
    BIOS_SCI3,                                          
    BIOS_SCI4,                                          
    BIOS_SCI5,                                          
    BIOS_SCI6,                                          
    BIOS_SCI7,                                          
    BIOS_SCI_MODULES_MAX                                
} enum_bios_sci_modules_t;


typedef struct type_bios_sci_module
{
    uint16_t* SCIBD;                                    
    uint8_t* SCICR1;                                    
    uint8_t* SCIASR1;                                   
    uint8_t* SCIACR1;                                   
    uint8_t* SCIACR2;                                   
    uint8_t* SCICR2;                                    
    uint8_t* SCISR1;                                    
    uint8_t* SCISR2;                                    
    uint8_t* SCIDRH;                                    
    uint8_t* SCIDRL;                                    
};



extern const struct type_bios_sci_module bios_sci_reg[BIOS_SCI_MODULES_MAX]; 








#define BIOS_SCI_BAUDRATE_CALC_REG(baud)  (uint16_t)((CPU_BUSCLK + (8UL * (baud))) / (16UL * (baud)) )



#define BIOS_SCI0_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI0_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI0_INT_RDR_FULL_ENABLED          1       
#define BIOS_SCI0_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI0_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI0_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI0_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI0_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI0_INT_MODE (    (BIOS_SCI0_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI0_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI0_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI0_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI0_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI0_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI0_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI0_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI1_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI1_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI1_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI1_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI1_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI1_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI1_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI1_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI1_INT_MODE (    (BIOS_SCI1_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI1_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI1_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI1_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI1_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI1_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI1_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI1_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI2_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI2_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI2_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI2_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI2_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI2_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI2_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI2_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI2_INT_MODE (    (BIOS_SCI2_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI2_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI2_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI2_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI2_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI2_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI2_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI2_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI3_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI3_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI3_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI3_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI3_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI3_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI3_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI3_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI3_INT_MODE (    (BIOS_SCI3_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI3_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI3_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI3_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI3_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI3_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI3_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI3_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI4_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI4_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI4_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI4_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI4_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI4_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI4_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI4_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI4_INT_MODE (    (BIOS_SCI4_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI4_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI4_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI4_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI4_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI4_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI4_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI4_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI5_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI5_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI5_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI5_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI5_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI5_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI5_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI5_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI5_INT_MODE (    (BIOS_SCI5_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI5_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI5_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI5_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI5_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI5_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI5_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI5_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI6_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI6_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI6_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI6_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI6_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI6_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI6_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI6_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI6_INT_MODE (    (BIOS_SCI6_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI6_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI6_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI6_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI6_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI6_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI6_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI6_INT_RX_BREAK_DETECT_ENABLED  <<7) )

#define BIOS_SCI7_INT_TDR_EMPTY_ENABLED         0       
#define BIOS_SCI7_INT_TX_COMPLETE_ENABLED       0       
#define BIOS_SCI7_INT_RDR_FULL_ENABLED          0       
#define BIOS_SCI7_INT_IDLE_LINE_ENABLED         0       
#define BIOS_SCI7_INT_RX_OVERRUN_ENABLED        0       
#define BIOS_SCI7_INT_RX_ACTIVE_EDGE_ENABLED    0       
#define BIOS_SCI7_INT_RX_BIT_ERROR_ENABLED      0       
#define BIOS_SCI7_INT_RX_BREAK_DETECT_ENABLED   0       

#define BIOS_SCI7_INT_MODE (    (BIOS_SCI7_INT_TDR_EMPTY_ENABLED        <<0) | \
                                (BIOS_SCI7_INT_TX_COMPLETE_ENABLED      <<1) | \
                                (BIOS_SCI7_INT_RDR_FULL_ENABLED         <<2) | \
                                (BIOS_SCI7_INT_IDLE_LINE_ENABLED        <<3) | \
                                (BIOS_SCI7_INT_RX_OVERRUN_ENABLED       <<4) | \
                                (BIOS_SCI7_INT_RX_ACTIVE_EDGE_ENABLED   <<5) | \
                                (BIOS_SCI7_INT_RX_BIT_ERROR_ENABLED     <<6) | \
                                (BIOS_SCI7_INT_RX_BREAK_DETECT_ENABLED  <<7) )




#define BIOS_SCI_WHILE_TIMEOUT_MAX_VALUE    (uint16_t)65000         


#if BIOS_SCI_MODUL_DEFAULT == 0
  #define bios_sci_default_func(func_name) bios_sci0_##func_name    
#endif

#if BIOS_SCI_MODUL_DEFAULT == 1
  #define bios_sci_default_func(func_name) bios_sci1_##func_name    
#endif

#if BIOS_SCI_MODUL_DEFAULT == 2
  #define bios_sci_default_func(func_name) bios_sci2_##func_name    
#endif

#if BIOS_SCI_MODUL_DEFAULT == 3
  #define bios_sci_default_func(func_name) bios_sci3_##func_name    
#endif

#if BIOS_SCI_MODUL_DEFAULT == 4
  #define bios_sci_default_func(func_name) bios_sci4_##func_name   
#endif

#if BIOS_SCI_MODUL_DEFAULT == 5
  #define bios_sci_default_func(func_name) bios_sci5_##func_name   
#endif

#if BIOS_SCI_MODUL_DEFAULT == 6
  #define bios_sci_default_func(func_name) bios_sci6_##func_name   
#endif

#if BIOS_SCI_MODUL_DEFAULT == 7
  #define bios_sci_default_func(func_name) bios_sci7_##func_name   
#endif




void bios_sci_module_init(uint8_t module, uint32_t baudrate, uint16_t baudrate_user, uint8_t sci_mode);



#define bios_sci_init   bios_sci_default_func(init)                                         
#define bios_sci0_init(baudrate, sci_mode) bios_sci_module_init(0, baudrate, 0, sci_mode)   
#define bios_sci1_init(baudrate, sci_mode) bios_sci_module_init(1, baudrate, 0, sci_mode)   
#define bios_sci2_init(baudrate, sci_mode) bios_sci_module_init(2, baudrate, 0, sci_mode)   
#define bios_sci3_init(baudrate, sci_mode) bios_sci_module_init(3, baudrate, 0, sci_mode)   
#define bios_sci4_init(baudrate, sci_mode) bios_sci_module_init(4, baudrate, 0, sci_mode)   
#define bios_sci5_init(baudrate, sci_mode) bios_sci_module_init(5, baudrate, 0, sci_mode)   
#define bios_sci6_init(baudrate, sci_mode) bios_sci_module_init(6, baudrate, 0, sci_mode)   
#define bios_sci7_init(baudrate, sci_mode) bios_sci_module_init(7, baudrate, 0, sci_mode)   


uint16_t bios_sci_module_get_interrupt_src(uint8_t module);

#define bios_sci_get_interrupt_src   bios_sci_default_func(get_interrupt_src)               
#define bios_sci0_get_interrupt_src() bios_sci_module_get_interrupt_src(0)                  
#define bios_sci1_get_interrupt_src() bios_sci_module_get_interrupt_src(1)                  
#define bios_sci2_get_interrupt_src() bios_sci_module_get_interrupt_src(2)                  
#define bios_sci3_get_interrupt_src() bios_sci_module_get_interrupt_src(3)                  
#define bios_sci4_get_interrupt_src() bios_sci_module_get_interrupt_src(4)                  
#define bios_sci5_get_interrupt_src() bios_sci_module_get_interrupt_src(5)                  
#define bios_sci6_get_interrupt_src() bios_sci_module_get_interrupt_src(6)                  
#define bios_sci7_get_interrupt_src() bios_sci_module_get_interrupt_src(7)                  


void bios_sci_module_interrupt_ack(uint8_t module, uint16_t src);

#define bios_sci_interrupt_ack   bios_sci_default_func(interrupt_ack)                       
#define bios_sci0_interrupt_ack(src) bios_sci_module_interrupt_ack(0, src)                  
#define bios_sci1_interrupt_ack(src) bios_sci_module_interrupt_ack(1, src)                  
#define bios_sci2_interrupt_ack(src) bios_sci_module_interrupt_ack(2, src)                  
#define bios_sci3_interrupt_ack(src) bios_sci_module_interrupt_ack(3, src)                  
#define bios_sci4_interrupt_ack(src) bios_sci_module_interrupt_ack(4, src)                  
#define bios_sci5_interrupt_ack(src) bios_sci_module_interrupt_ack(5, src)                  
#define bios_sci6_interrupt_ack(src) bios_sci_module_interrupt_ack(6, src)                  
#define bios_sci7_interrupt_ack(src) bios_sci_module_interrupt_ack(7, src)                  


uint8_t bios_sci_module_read_byte(uint8_t module);

#define bios_sci_read_byte   bios_sci_default_func(read_byte)                               
#define bios_sci0_read_byte() bios_sci_module_read_byte(0)                                  
#define bios_sci1_read_byte() bios_sci_module_read_byte(1)                                  
#define bios_sci2_read_byte() bios_sci_module_read_byte(2)                                  
#define bios_sci3_read_byte() bios_sci_module_read_byte(3)                                  
#define bios_sci4_read_byte() bios_sci_module_read_byte(4)                                  
#define bios_sci5_read_byte() bios_sci_module_read_byte(5)                                  
#define bios_sci6_read_byte() bios_sci_module_read_byte(6)                                  
#define bios_sci7_read_byte() bios_sci_module_read_byte(7)                                  


uint8_t bios_sci_module_write_byte(uint8_t module, uint8_t value); 

#define bios_sci_write_byte   bios_sci_default_func(write_byte)                             
#define bios_sci0_write_byte(value) bios_sci_module_write_byte(0, value)                    
#define bios_sci1_write_byte(value) bios_sci_module_write_byte(1, value)                    
#define bios_sci2_write_byte(value) bios_sci_module_write_byte(2, value)                    
#define bios_sci3_write_byte(value) bios_sci_module_write_byte(3, value)                    
#define bios_sci4_write_byte(value) bios_sci_module_write_byte(4, value)                    
#define bios_sci5_write_byte(value) bios_sci_module_write_byte(5, value)                    
#define bios_sci6_write_byte(value) bios_sci_module_write_byte(6, value)                    
#define bios_sci7_write_byte(value) bios_sci_module_write_byte(7, value)                    


void bios_sci_module_write_string(uint8_t module, char* ptr_string);

#define bios_sci_write_string   bios_sci_default_func(write_string)                         
#define bios_sci0_write_string(ptr_string) bios_sci_module_write_string(0, ptr_string)      
#define bios_sci1_write_string(ptr_string) bios_sci_module_write_string(1, ptr_string)      
#define bios_sci2_write_string(ptr_string) bios_sci_module_write_string(2, ptr_string)      
#define bios_sci3_write_string(ptr_string) bios_sci_module_write_string(3, ptr_string)      
#define bios_sci4_write_string(ptr_string) bios_sci_module_write_string(4, ptr_string)      
#define bios_sci5_write_string(ptr_string) bios_sci_module_write_string(5, ptr_string)      
#define bios_sci6_write_string(ptr_string) bios_sci_module_write_string(6, ptr_string)      
#define bios_sci7_write_string(ptr_string) bios_sci_module_write_string(7, ptr_string)      


void bios_sci_module_write_string_far(uint8_t module, char* __far ptr_string);

#define bios_sci_write_string_far   bios_sci_default_func(write_string_far)                     
#define bios_sci0_write_string_far(ptr_string) bios_sci_module_write_string_far(0, ptr_string)  
#define bios_sci1_write_string_far(ptr_string) bios_sci_module_write_string_far(1, ptr_string)  
#define bios_sci2_write_string_far(ptr_string) bios_sci_module_write_string_far(2, ptr_string)  
#define bios_sci3_write_string_far(ptr_string) bios_sci_module_write_string_far(3, ptr_string)  
#define bios_sci4_write_string_far(ptr_string) bios_sci_module_write_string_far(4, ptr_string)  
#define bios_sci5_write_string_far(ptr_string) bios_sci_module_write_string_far(5, ptr_string)  
#define bios_sci6_write_string_far(ptr_string) bios_sci_module_write_string_far(6, ptr_string)  
#define bios_sci7_write_string_far(ptr_string) bios_sci_module_write_string_far(7, ptr_string)  


void bios_sci_module_write_block(uint8_t module, char *ptr_string, uint16_t len);               

#define bios_sci_write_block   bios_sci_default_func(write_block)                               
#define bios_sci0_write_block(ptr_string, len) bios_sci_module_write_block(0, ptr_string, len)  
#define bios_sci1_write_block(ptr_string, len) bios_sci_module_write_block(1, ptr_string, len)  
#define bios_sci2_write_block(ptr_string, len) bios_sci_module_write_block(2, ptr_string, len)  
#define bios_sci3_write_block(ptr_string, len) bios_sci_module_write_block(3, ptr_string, len)  
#define bios_sci4_write_block(ptr_string, len) bios_sci_module_write_block(4, ptr_string, len)  
#define bios_sci5_write_block(ptr_string, len) bios_sci_module_write_block(5, ptr_string, len)  
#define bios_sci6_write_block(ptr_string, len) bios_sci_module_write_block(6, ptr_string, len)  
#define bios_sci7_write_block(ptr_string, len) bios_sci_module_write_block(7, ptr_string, len)  


uint8_t bios_sci_module_send_break(uint8_t module);                         

#define bios_sci_send_break   bios_sci_default_func(send_break)                                 
#define bios_sci0_send_break() bios_sci_module_send_break(0)                                    
#define bios_sci1_send_break() bios_sci_module_send_break(1)                                    
#define bios_sci2_send_break() bios_sci_module_send_break(2)                                    
#define bios_sci3_send_break() bios_sci_module_send_break(3)                                    
#define bios_sci4_send_break() bios_sci_module_send_break(4)                                    
#define bios_sci5_send_break() bios_sci_module_send_break(5)                                    
#define bios_sci6_send_break() bios_sci_module_send_break(6)                                    
#define bios_sci7_send_break() bios_sci_module_send_break(7)                                    


void bios_sci_module_enable_tci_and_ri(uint8_t module);

#define bios_sci_enable_tci_and_ri   bios_sci_default_func(enable_tci_and_ri)                   
#define bios_sci0_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(0)                      
#define bios_sci1_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(1)                      
#define bios_sci2_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(2)                      
#define bios_sci3_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(3)                      
#define bios_sci4_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(4)                      
#define bios_sci5_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(5)                      
#define bios_sci6_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(6)                      
#define bios_sci7_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(7)                      


void bios_sci_module_enable_tci(uint8_t module);

#define bios_sci_enable_tci bios_sci_default_func(enable_tci)                                   
#define bios_sci1_enable_tci() bios_sci_module_enable_tci(1)                                    
#define bios_sci0_enable_tci() bios_sci_module_enable_tci(0)                                    
#define bios_sci2_enable_tci() bios_sci_module_enable_tci(2)                                    
#define bios_sci3_enable_tci() bios_sci_module_enable_tci(3)                                    
#define bios_sci4_enable_tci() bios_sci_module_enable_tci(4)                                    
#define bios_sci5_enable_tci() bios_sci_module_enable_tci(5)                                    
#define bios_sci6_enable_tci() bios_sci_module_enable_tci(6)                                    
#define bios_sci7_enable_tci() bios_sci_module_enable_tci(7)                                    


void bios_sci_module_disable_tci(uint8_t module);

#define bios_sci_disable_tci   bios_sci_default_func(disable_tci)                               
#define bios_sci0_disable_tci() bios_sci_module_disable_tci(0)                                  
#define bios_sci1_disable_tci() bios_sci_module_disable_tci(1)                                  
#define bios_sci2_disable_tci() bios_sci_module_disable_tci(2)                                  
#define bios_sci3_disable_tci() bios_sci_module_disable_tci(3)                                  
#define bios_sci4_disable_tci() bios_sci_module_disable_tci(4)                                  
#define bios_sci5_disable_tci() bios_sci_module_disable_tci(5)                                  
#define bios_sci6_disable_tci() bios_sci_module_disable_tci(6)                                  
#define bios_sci7_disable_tci() bios_sci_module_disable_tci(7)                                  


void bios_sci_module_enable_int_receive(uint8_t module);

#define bios_sci_enable_int_receive   bios_sci_default_func(enable_int_receive)                 
#define bios_sci0_enable_int_receive() bios_sci_module_enable_int_receive(0)                    
#define bios_sci1_enable_int_receive() bios_sci_module_enable_int_receive(1)                    
#define bios_sci2_enable_int_receive() bios_sci_module_enable_int_receive(2)                    
#define bios_sci3_enable_int_receive() bios_sci_module_enable_int_receive(3)                    
#define bios_sci4_enable_int_receive() bios_sci_module_enable_int_receive(4)                    
#define bios_sci5_enable_int_receive() bios_sci_module_enable_int_receive(5)                    
#define bios_sci6_enable_int_receive() bios_sci_module_enable_int_receive(6)                    
#define bios_sci7_enable_int_receive() bios_sci_module_enable_int_receive(7)                    


void bios_sci_module_disable_int_receive(uint8_t module);

#define bios_sci_disable_int_receive   bios_sci_default_func(disable_int_receive)               
#define bios_sci0_disable_int_receive() bios_sci_module_disable_int_receive(0)                  
#define bios_sci1_disable_int_receive() bios_sci_module_disable_int_receive(1)                  
#define bios_sci2_disable_int_receive() bios_sci_module_disable_int_receive(2)                  
#define bios_sci3_disable_int_receive() bios_sci_module_disable_int_receive(3)                  
#define bios_sci4_disable_int_receive() bios_sci_module_disable_int_receive(4)                  
#define bios_sci5_disable_int_receive() bios_sci_module_disable_int_receive(5)                  
#define bios_sci6_disable_int_receive() bios_sci_module_disable_int_receive(6)                  
#define bios_sci7_disable_int_receive() bios_sci_module_disable_int_receive(7)                  


void bios_sci_module_enable_break(uint8_t module, uint8_t break_enable_mode, uint8_t break_len);

#define bios_sci_enable_break   bios_sci_default_func(enable_break)                             
#define bios_sci0_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(0, break_enable_mode, break_len)   
#define bios_sci1_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(1, break_enable_mode, break_len)   
#define bios_sci2_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(2, break_enable_mode, break_len)   
#define bios_sci3_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(3, break_enable_mode, break_len)   
#define bios_sci4_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(4, break_enable_mode, break_len)   
#define bios_sci5_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(5, break_enable_mode, break_len)   
#define bios_sci6_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(6, break_enable_mode, break_len)   
#define bios_sci7_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(7, break_enable_mode, break_len)   


void bios_sci_module_disable_break(uint8_t module);

#define bios_sci_disable_break   bios_sci_default_func(disable_break)                           
#define bios_sci0_disable_break() bios_sci_module_disable_break(0)                              
#define bios_sci1_disable_break() bios_sci_module_disable_break(1)                              
#define bios_sci2_disable_break() bios_sci_module_disable_break(2)                              
#define bios_sci3_disable_break() bios_sci_module_disable_break(3)                              
#define bios_sci4_disable_break() bios_sci_module_disable_break(4)                              
#define bios_sci5_disable_break() bios_sci_module_disable_break(5)                              
#define bios_sci6_disable_break() bios_sci_module_disable_break(6)                              
#define bios_sci7_disable_break() bios_sci_module_disable_break(7)                              


#endif 




void bios_sci_module_interrupt(uint8_t module);

#define bios_sci_interrupt   bios_sci_default_func(interrupt)                                   
#define bios_sci0_interrupt() bios_sci_module_interrupt(0)                                      
#define bios_sci1_interrupt() bios_sci_module_interrupt(1)                                      
#define bios_sci2_interrupt() bios_sci_module_interrupt(2)                                      
#define bios_sci3_interrupt() bios_sci_module_interrupt(3)                                      
#define bios_sci4_interrupt() bios_sci_module_interrupt(4)                                      
#define bios_sci5_interrupt() bios_sci_module_interrupt(5)                                      
#define bios_sci6_interrupt() bios_sci_module_interrupt(6)                                      
#define bios_sci7_interrupt() bios_sci_module_interrupt(7)                                      






extern void (*os_sci_module_interrupt)(uint8_t module);
extern void (*user_sci_module_rx_interrupt)(uint8_t module, uint8_t data);
extern void (*user_sci_module_tx_interrupt)(uint8_t module);
extern void (*lin_rx_frame_handling_interrupt)(uint8_t module, uint8_t data);
extern void (*lin_tx_frame_handling_interrupt)(uint8_t module);

extern uint16_t bios_sci_int_src[BIOS_SCI_MODULES_MAX];
extern uint8_t ext_sci_asr1_bkdif[BIOS_SCI_MODULES_MAX];


