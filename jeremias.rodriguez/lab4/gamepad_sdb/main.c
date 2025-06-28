#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"

volatile unsigned char pin_button = 0b00010000;

void main()
{
	int val;
	adc_init();
	serial_init();
	make_input_DDRB_PUP(pin_button);
	while (1) {
		val = adc_get(3);
		serial_put_int(val, 4);
		serial_put_char('\r');
		serial_put_char('\n');
		if(read_signal_B(pin_button) == 0){
			serial_put_char(' ');
			serial_put_char('\r');
			serial_put_char('\n');
		}
	}

	for(;;);
}