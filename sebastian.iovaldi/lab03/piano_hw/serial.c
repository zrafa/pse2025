#include <avr/interrupt.h>
#include "hw.h"

#define F_CPU 4000000UL
#define USART_BAUDRATE 2400UL
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
 
void serial_init()
{
    puerto_serial->status_control_b |= 0x08;    /* enables tx */
    puerto_serial->status_control_b |= 0x10;    /* enables rx */

    puerto_serial->status_control_b |= 0x80;    /* rcv interrupt enabled */

    puerto_serial->status_control_b &= ~0x04;   /* 8 bits per frame */
    puerto_serial->status_control_c |= 0x06;    /* 8 bits per frame */

    puerto_serial->status_control_c &= ~0xC0;   /* Asynchronous USART */
    puerto_serial->status_control_c &= ~0x08;   /* 1 stop bit */
    puerto_serial->status_control_c &= ~0x48;   /* parity bit - disabled */
    puerto_serial->status_control_c &= ~0x01;   /* clock polarity (not async)*/

    puerto_serial->baud_rate_high = (unsigned char)BAUD_PRESCALE >> 8;
    puerto_serial->baud_rate_low  = (unsigned char)BAUD_PRESCALE & 0xFF;

    sei();
}

void serial_put_char (char c)
{
    while(!(puerto_serial->status_control_a & 0x20));
    puerto_serial->data_es = c;
}

char serial_get_char(void)
{
    while(!(puerto_serial->status_control_a & 0b10000000));
    return puerto_serial->data_es;
}

extern unsigned long hperiod_us;

ISR(USART_RX_vect)
{
    char keys = puerto_serial->data_es;
    unsigned long freq;

    switch (keys)
    {
        case 0x01: freq = 131; break;  // DO (C3)
        case 0x02: freq = 147; break;  // RE (D3)
        case 0x04: freq = 165; break;  // MI (E3)
        case 0x08: freq = 174; break;  // FA (F3)
        case 0x10: freq = 196; break;  // SOL (G3)
        case 0x20: freq = 220; break;  // LA (A3)
        case 0x40: freq = 247; break;  // SI (B3)
        default: freq = 0; break;      // Ninguna tecla válida
    }
    
    hperiod_us = freq ? 500000UL / freq : 0;
}
 
 