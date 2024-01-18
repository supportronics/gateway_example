#ifndef _BIOS_SPI_H_
#define _BIOS_SPI_H_



#include "bios_base.h"
#include "bios_cpu.h"



#ifdef CLK_SEL_50MHZ
      #define BIOS_SPI_24414_BAUD           1       
#else
      #define BIOS_SPI_19531_3_BAUD         1       
#endif

#define BIOS_SPI_19531_BAUD                 2       
#define BIOS_SPI_625K_BAUD                  3       
#define BIOS_SPI_5M_BAUD                    4       

#ifdef CLK_SEL_50MHZ
      #define BIOS_SPI_12_5M_BAUD           5       
#else
      #define BIOS_SPI_10M_BAUD             5       
#endif

#ifdef CLK_SEL_50MHZ
      #define BIOS_SPI_25M_BAUD             6       
#else
      #define BIOS_SPI_20M_BAUD             6       
#endif


#define BIOS_SPI_MODE_0                     0       
#define BIOS_SPI_MODE_3                     3       



#define bios_spi0_init(baudrate, spi_mode) bios_spi_module_init(0, baudrate, spi_mode)      
#define bios_spi1_init(baudrate, spi_mode) bios_spi_module_init(1, baudrate, spi_mode)      
#define bios_spi2_init(baudrate, spi_mode) bios_spi_module_init(2, baudrate, spi_mode)      


void bios_spi_module_init(uint8 module, uint8 baudrate, uint8 spi_mode);


uint8_t bios_spi_rw_char(uint8_t value, uint8_t *receive8, uint8_t module);


uint8_t bios_spi_rw_atmel(uint8_t value, uint8 module);


#endif
