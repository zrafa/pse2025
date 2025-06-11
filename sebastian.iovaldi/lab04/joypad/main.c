
#include "adc.h"
#include "serial.h"
#include "button.h"
#include <util/delay.h>


int main()
{
    serial_init();
	adc_init();
    button_init();

	while(1)
    {
        if(button_pulsed())
            serial_put_char('h');
        
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		uint8_t val = adc_get(1);

		/* realizar alguna acción con val */
        _delay_ms(100);

        serial_put_char(val);
	}
}
