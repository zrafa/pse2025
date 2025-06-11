
#include "adc.h"
#include "serial.h"
#include "led.h"
#include <util/delay.h>

int main()
{
    serial_init();
	adc_init();
    led_init();

	while(1)
    {   
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		uint8_t val = adc_get(1);

		/* realizar alguna acción con val */
        led_on();
        _delay_ms(500);
      //  led_off();
        _delay_ms(500);

        serial_put_char(val);
	}
}
