#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"

uint16_t convert(uint16_t x, uint16_t in_min, uint16_t in_max, uint8_t out_min, uint8_t out_max) ;

void main()
{
	uint16_t val, show;
	adc_init();
	serial_init();
	_delay_ms(1000);
	while (1) {
		val = 0;
		/* obtener una conversión ADC desde el pin de entrada ADC 0 */
		val = adc_get(3);
		/* realizar alguna acción con val */
		serial_put_int(val, 3);
		serial_put_char('\r');
    	serial_put_char('\n');
		_delay_ms(1000);
	}
}

uint16_t convert(uint16_t x, uint16_t in_min, uint16_t in_max, uint8_t out_min, uint8_t out_max) {
		if (x < in_min) x = in_min;
		if (x > in_max) x = in_max;
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}