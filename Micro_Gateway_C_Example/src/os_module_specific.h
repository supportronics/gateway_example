#ifndef _OS_MODULE_SPECIFIC_H_
#define _OS_MODULE_SPECIFIC_H_



#include "bios_sci.h"
#include "os_io.h"
#include "bios_spi.h"
#include "SPI_Flash.h"

#define TYPE_M2600    101
#define TYPE_MGATEWAY 110 

#define SPI_RX_BUFFER_SIZE  4
#define SPI_TX_BUFFER_SIZE  4
#define SPI_MODULE_0        0
#define SPI_MODULE_1        1
#define SPI_MODULE_2        2

#define SPECIFIC_DO_CS_SS   0 

#define PIGGY_CAN_HS        1
#define PIGGY_CAN_LS        2
#define PIGGY_HSD           3
#define PIGGY_RTC           4
#define PIGGY_INPUT         5
#define PIGGY_CAN_TJA1145   6

enum e_mgateway_specific
{
    SPECIFIC_DO_GPIO0_0=0,
    SPECIFIC_DO_CAN2_TXD,
    SPECIFIC_A_GPIO0_0,
    SPECIFIC_DI_RS232_TXD3,
    SPECIFIC_DI_SPI1_CS0,
    SPECIFIC_MAX
};


void os_specific_m2600(void);

void os_specific_mgateway_init(void);

#endif
