
#include "adc.h"
#include "serial.h"
#include <util/delay.h>

int main(void)
{
	uint8_t val;
	serial_init();
	adc_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 0 */
 		val = adc_get(ADC_CHANNEL_0);
		 serial_put_number(val);
		/* realizar alguna acción con val */

		_delay_ms(500);

	}

	for(;;);
}
