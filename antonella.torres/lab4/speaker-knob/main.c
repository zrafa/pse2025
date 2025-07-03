#include "adc.h"
#include "serial.h"
#include "sound.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

int main(void)
{
	/* direccion de PORTB (registro de datos) */
	volatile unsigned char * puerto_b = (unsigned char *) 0x25;

	/* direccion de DDR B (registro de control) */
	volatile unsigned char * ddr_b = (unsigned char *) 0x24;

	*ddr_b |= (1 << 5);

	uint8_t val;
	serial_init();
	adc_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 0 */
 		val = adc_get(ADC_CHANNEL_0);
		val = 255 -val;
		//serial_put_number(val);
		/* realizar alguna acción con val */
		if(val > 3){
		sound(val*3, 5);
		}else{
			sound(3*3, 5);
		}
	}
	for(;;);
}
