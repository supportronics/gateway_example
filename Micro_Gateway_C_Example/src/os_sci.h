#ifndef _OS_SCI_H_
#define _OS_SCI_H_

#include "PE_Types.h"
#include "os_io_tables.h"
#include "user_code.h"
#include "graph_includes.h"



#define DELAY_KENNER 0xFF55

extern const unsigned int crcTab[256];
#define UPDATECRC(crc,c) (crcTab[(((crc) >> 8) & 0xFF)] ^ ((crc) << 8) ^ (c))

#ifndef USER_BUFFER_SIZE
 #define USER_BUFFER_SIZE 10
#endif


#ifndef SCI_USER_ACTIVE
   #undef USER_BUFFER_SIZE
   #define USER_BUFFER_SIZE 1
#endif

typedef struct {
 uint16_t  pointer;
 uint16_t  pointer_buf;
 uint16_t  max;
 uint16_t  size;
 uint8_t send_active;
 uint16_t  delay_after_send;
 uint16_t  msg_cnt;
 uint32_t timeout_rx_freigabe;
 uint8_t sci_nr;
 uint8_t sci_error_test;
 uint8_t sci_error_counter1;
 uint8_t sci_error_counter2;
 uint8_t data_bits_9;
 uint8_t parity;
 uint32_t baudrate;
 uint16_t  baudrate_user_defined;
 uint8_t full_duplex;
 uint8_t rs485_de_pin;
  uint8_t AS_SerFlag;
 uint8_t data[USER_BUFFER_SIZE];


}  type_sci_tx_buffer;

extern type_sci_tx_buffer ext_dyn_sci_tx_buffer;

#define sci_tx_buffer ext_dyn_sci_tx_buffer


 void MainDelay(unsigned int wait);

 void sci_int_buffer_send_start(void);

 void sci_int_buffer_send(void);

 void sci_buffer_send(void);

 void sci_init(void);

 uint8 sci_put_queue(uint8 data);

 void sci_enable(uint8 mode_sel);

 void sci_timeout_control(void);

 void unsigned_int_to_hi_lo(unsigned int  wert, unsigned char *hi ,unsigned char *lo);

 unsigned int calculate_crc(unsigned int laenge, unsigned char* buffer);

#endif 

