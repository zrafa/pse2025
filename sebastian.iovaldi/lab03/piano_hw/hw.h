#pragma once

#include <stdint.h>

#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8
#define BIT5 32

typedef struct
{
    uint8_t status_control_a;
    uint8_t status_control_b;
    uint8_t status_control_c;
    uint8_t reserved;
    uint8_t baud_rate_low;
    uint8_t baud_rate_high;
    uint8_t data_es;    
} uart_t;


extern volatile unsigned char* port_c;
extern volatile unsigned char* ddr_c;
extern volatile unsigned char* pin_c;
extern volatile uart_t *puerto_serial;