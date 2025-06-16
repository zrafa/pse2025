
#include "adc.h"
#include "serial.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>



int main(void)
{
    volatile unsigned int i;
    /* direccion de PORTB (registro de datos) */
    volatile unsigned char * puerto_b = (unsigned char *) 0x25;

    /* direccion de DDR B (registro de control) */
    volatile unsigned char * ddr_b = (unsigned char *) 0x24;


	uint8_t val;
	serial_init();
    
    _delay_ms(1000);
    serial_put_char('H');
    _delay_ms(13);
    serial_put_char('O');
    _delay_ms(13);
    serial_put_char('L');
    _delay_ms(13);
    serial_put_char('A');
    _delay_ms(13);
    serial_put_char(' ');
    _delay_ms(13);
    serial_put_char('M');
    _delay_ms(13);
    serial_put_char('U');
    _delay_ms(13);
    serial_put_char('N');
    _delay_ms(13);
    serial_put_char('D');
    _delay_ms(13);
    serial_put_char('O');
    _delay_ms(13);

	for(;;);
}