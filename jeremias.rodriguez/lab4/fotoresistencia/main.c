#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"


void main()
{
	uint16_t val;
	adc_init();
	serial_init();

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
