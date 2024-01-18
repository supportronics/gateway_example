
#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "bios_cpu.h"
#include "bios_spi.h"
#include "os_timer.h"



#define CHIP_NR_ATMEL    7   
#define SPI_FLASH_MAX_CHIP_SIZE 0xFFFFFF
#define SPI_FLASH_CHIP_ANZAHL 10

#define CHIP_NR_ATMEL_MIN CHIP_NR_ATMEL
#define CHIP_NR_ATMEL_MAX 11

#define ATMEL_FLASH
#define LOGGER_FLEXIS_V3
#define MGATEWAY_SPI_NR 1

#define ATMEL_STARTCODE_NR  131

#define ATMEL_ADDRESS_STARTCODE ((uint32_t) 10)  
#define ATMEL_ADDRESS_PIGGYTYPE (ATMEL_ADDRESS_STARTCODE + 1)  

#define SELECT_SP0_CS0 PORTD_PD3 
#define SELECT_SP0_CS1 PORTD_PD2 
#define SELECT_SP0_CS2 PORTD_PD1


extern byte AKT_Chip_Nr;
#define SYSTEM_CLOCK                    66

#define QSPI_CYCLELENGTH                8       

#define QSPI_TRAM                       0x00    
#define QSPI_RRAM                       0x10    
#define QSPI_CRAM                       0x20    


#define CPU_READ_8(addr)          (*((uint8 *)(addr)))
#define CPU_WRITE_8(addr,data)    *((uint8  *)(addr)) = (uint8)(data);


typedef struct {
    dword baseAddr;                            
} flash_info;


#define RET_SUCCESS                     0       
#define RET_FAILURE                     1           

#define SPI_OPCODE_READ                                    0x03                    
#define SPI_OPCODE_READ_SR                              0x05
#define SPI_OPCODE_ATMEL_READ_SR                0xD7                   
#define SPI_OPCODE_READ_ID                               0x9F                   
#define SPI_OPCODE_READ_OTP                           0x4B                   
#define SPI_OPCODE_READ_FAST                         0x0B

#define SPI_OPCODE_WRITE_SR                   0x01    
#define SPI_OPCODE_WRITE_ENABLE          0x06
#define SPI_OPCODE_WRITE_DISABLE          0x04
#define SPI_OPCODE_PAGE_PROGRAM         0x02
#define SPI_OPCODE_OTP_PROGRAM          0x42        

#define SPI_OPCODE_BULK_ERASE           0xC7
#define SPI_OPCODE_SECTOR_ERASE         0xD8
#define SPI_OPCODE_PARAM_BLOCK_ERASE    0x40        
#define SPI_OPCODE_CLEAR_SR_FLAGS       0x30              

#define SPI_OPCODE_DPD                            0xB9            
#define SPI_OPCODE_DPD_RELEASE          0xAB           


#define SPI_SR_SRWD                     0x80    
#define SPI_SR_P_FAIL                   0x40    
#define SPI_SR_E_FAIL                   0x20    
#define SPI_SR_BP2                         0x10    
#define SPI_SR_BP1                         0x08    
#define SPI_SR_BP0                         0x04    
#define SPI_SR_WEL                        0x02    
#define SPI_SR_WIP                         0x01    

#define SPI_ATMEL_SR_WIP                   0x80    



#define USE_INTEL_FLASH_SIZE_16


#define INTEL_BP_START_ADDRS_16         {   0x200000, 0x1F0000, 0x1E0000, 0x1C0000, \
                                            0x180000, 0x100000, 0x000000, 0x000000  }

#define INTEL_BP_START_ADDRS_32         {   0x400000, 0x3F0000, 0x3E0000, 0x3C0000, \
                                            0x380000, 0x300000, 0x200000, 0x000000  }

#define INTEL_BP_START_ADDRS_64         {   0x800000, 0x7E0000, 0x7C0000, 0x780000, \
                                            0x700000, 0x600000, 0x400000, 0x000000  }

#define TMPL_CF_MBAR             (0x40000000)

#define TMPL_GPIO_PACNT          ( *((volatile dword *)(TMPL_CF_MBAR + 0x80)) )
#define TMPL_GPIO_PADDR          ( *((volatile word *)(TMPL_CF_MBAR + 0x84)) )
#define TMPL_GPIO_PADAT          ( *((volatile word *)(TMPL_CF_MBAR + 0x86)) )

#define TMPL_QSPI_QMR            ( *((volatile word *)(TMPL_CF_MBAR + 0xA0)) )
#define TMPL_QSPI_QDLYR          ( *((volatile word *)(TMPL_CF_MBAR + 0xA4)) )
#define TMPL_QSPI_QWR            ( *((volatile word *)(TMPL_CF_MBAR + 0xA8)) )
#define TMPL_QSPI_QIR            ( *((volatile word *)(TMPL_CF_MBAR + 0xAC)) )
#define TMPL_QSPI_QAR            ( *((volatile word *)(TMPL_CF_MBAR + 0xB0)) )
#define TMPL_QSPI_QDR            ( *((volatile word *)(TMPL_CF_MBAR + 0xB4)) )

#define TMPL_QSPI_QMR_MSTR       (0x8000)
#define TMPL_QSPI_QMR_BITS(x)    ( ((x)&0x000F)<<10 )
#define TMPL_QSPI_QMR_CPOL       (0x0200)
#define TMPL_QSPI_QMR_CPHA       (0x0100)
#define TMPL_QSPI_QMR_BAUD(x)    ( ((x)&0x00FF) )

#define TMPL_QSPI_QDLYR_SPE      (0x8000)

#define TMPL_QSPI_QWR_CSIV       (0x1000)
#define TMPL_QSPI_QWR_ENDQP(x)   (((x)&0x000F)<<8)

#define TMPL_QSPI_QIR_SPIF       (0x0001)

#define TMPL_QSPI_QAR_ADDR(x)    ( ((x)&0x003F) )

#define TMPL_QSPI_QDR_DATA(x)    ( ((x)&0xFF) )

#define TMPL_QSPI_QCR_CS(x)      ( ((x)&0x000F)<<8 )




 extern    byte SM1_SendBlock(byte *flashOutput, word OutputCycles,word *LenOutputCycles);
 extern    byte SM1_RecvBlock(byte *flashInput, word InputCycles,word *LenInputCycles);
 extern    int TMPL_ClearSRFailFlags(flash_info * info);
 extern    uint32 adresse_to_chip_nr(uint32 Adresse ,byte *Chip_Nr );
 extern    void set_SS_signal(byte Chip_Nr , byte ON_OFF);
extern void ATMEL_writeByte_to_Buffer(uint8 Byteadresse,byte *Daten, byte len_Daten);  
extern void ATMEL_writePage_Buffer_to_FlashMemory(unsigned int Page_nr) ;
extern void ATMEL_readPage_FlashMemory_To_Buffer(unsigned int Page_nr) ;
extern int ATMEL_Read(flash_info * info, uint32 addr, uint8 * buffer, uint32 numBytes);
extern void set_Binary_Pagemode(void);
void SPI_Flash_Sector_ERASE(dword Sector_Adr);

void SPI_Speichertest(void);
void ATMEL_write(long wr_pos, uint8_t *buffer_addr, uint16_t anzahl);

void os_atmel_write(uint8_t chip_nr, long wr_pos, uint8_t *buffer_addr, uint16_t anzahl);
void os_atmel_read(uint8_t chip_nr, uint32 addr, uint8 * buffer, uint32 numBytes);

extern uint8 os_spi_config[];

extern uint8 TMPL_ReadStatReg(void);

extern byte ATMEL_writeAlarmdata( long zwAlarmWritePos, unsigned char  buffer[], int anzahl, byte Mode);

#define ATMEL_SAVE_DATA           1
#define ATMEL_READ_BUFFER      2
#define ATMEL_WRITE_BUFFER    3


void INIT_Flash(void);

void TMPL_QSPI_InitHW (
    int     baud, 
    int     resetAll
);

void TMPL_QSPI_RunCycles (
    const uint8 *   flashInput, 
    byte *         flashOutput, 
    dword          inputCycles, 
    dword          outputCycles, 
    dword          outputOffset
);

void TMPL_QSPI_RunCycles2 (
    const uint8 *   flashInput, 
    uint8 *         flashOutput, 
    word          inputCycles, 
    word          outputCycles, 
    word          outputOffset
);

void TMPL_QSPI_Initialize (
    const uint8 **     flashInput, 
    dword             totalCycles
);

void TMPL_QSPI_Process16ByteRound (
    const uint8 **   flashInput, 
    uint8 **         flashOutput, 
    dword *         outputCycles, 
    dword *         outputOffset
);

void TMPL_QSPI_ProcessFinalCycles (
    uint8 **         flashOutput, 
    dword *         outputCycles, 
    dword *         outputOffset, 
    dword           totalCycles
);

void TMPL_QSPI_ReadFlashOutput (
    uint8 **         flashOutput, 
    dword *         outputCycles, 
    dword *         outputOffset, 
    dword           readRamIndex
);


dword TMPL_LookupBPStartAddr ( 
    uint8 sr
);


byte TMPL_PollSRWriteComplete (
    flash_info *     info
);


int TMPL_InitFlashInfo (
    flash_info *     info, 
    dword           base
);



int TMPL_ClearSRFailFlags (
    flash_info *     info
);



int TMPL_ParamBlockErase (
    flash_info *     info,
    dword           addr
);


uint8 TMPL_ReadStatReg (

);

int TMPL_ReadIdent (
    flash_info *    info, 
    uint8 *         ident
);

int TMPL_Read ( 
    flash_info *    info, 
    dword          addr, 
    uint8 *         buffer, 
    dword          numBytes
);
int TMPL_ReadChip ( 
    flash_info *    info, 
    dword          addr, 
    uint8 *         buffer, 
    dword          numBytes
);


int TMPL_FastRead ( 
    flash_info *    info, 
    dword          addr, 
    uint8 *         buffer, 
    dword          numBytes
);






int TMPL_WriteEnable (
    flash_info *     info
);

int TMPL_WriteDisable (
    flash_info *     info
);





int TMPL_WriteStatReg (
    flash_info *     info, 
    uint8            sr
);

int TMPL_PageProgram (
    flash_info *    info, 
    dword          addr, 
    uint8 *         buffer, 
    dword          numBytes
);

int TMPL_ArrayProgram (
    flash_info *    info, 
    dword          addr, 
    uint8 *         buffer, 
    dword          numBytes
);

int TMPL_SectorErase (
    flash_info *     info, 
    dword           addr
);

int TMPL_BulkErase (
    flash_info *     info
);






int TMPL_DeepPowerDown (
    flash_info *     info
);

int TMPL_ReleaseFromDeepPowerDown (
    flash_info *     info
);



int TMPL_UnlockAllBlocks (
    flash_info *     info
);

#endif 

