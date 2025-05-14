
#include "adc.h"
#include "serial.h"
#include <util/delay.h>

main()
{
	int val;

	adc_init();
	serial_init();



	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		uint16_t val = adc_get(2);
		serial_put_number(val); 
		/* realizar alguna acción con val */

		_delay_ms(500);
	}

	for(;;);
}
