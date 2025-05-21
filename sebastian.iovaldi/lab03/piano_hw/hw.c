#include "hw.h"

volatile uart_t *puerto_serial = (uart_t *) (0xc0);

volatile unsigned char * port_c = (unsigned char *) 0x28;
volatile unsigned char * ddr_c =  (unsigned char *) 0x27;
volatile unsigned char * pin_c =  (unsigned char *) 0x26;
