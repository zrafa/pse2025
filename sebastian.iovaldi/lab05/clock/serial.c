#include <stdint.h>

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

volatile uart_t *puerto_serial = (uart_t *) (0xc0);

#define USART_BAUDRATE 2400UL
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
 
void serial_init()
{
    puerto_serial->status_control_b |= 0x08;    /* enables tx */
    puerto_serial->status_control_b |= 0x10;    /* enables rx */

    puerto_serial->status_control_b &= ~0x04;   /* 8 bits per frame */
    puerto_serial->status_control_c |= 0x06;    /* 8 bits per frame */

    puerto_serial->status_control_c &= ~0xC0;   /* Asynchronous USART */
    puerto_serial->status_control_c &= ~0x08;   /* 1 stop bit */
    puerto_serial->status_control_c &= ~0x48;   /* parity bit - disabled */
    puerto_serial->status_control_c &= ~0x01;   /* clock polarity (not async)*/

    puerto_serial->baud_rate_high = (unsigned char)BAUD_PRESCALE >> 8;
    puerto_serial->baud_rate_low  = (unsigned char)BAUD_PRESCALE & 0xFF;
}

void serial_put_char (uint8_t c)
{
    while(!(puerto_serial->status_control_a & 0x20));
    puerto_serial->data_es = c;
}

void serial_put_str(uint8_t* str, int size)
{
    for(int i=0; i<size; i++)
        serial_put_char(str[i]);
}

char serial_get_char(void)
{
    while(!(puerto_serial->status_control_a & 0b10000000));
    return puerto_serial->data_es;
}
 