
#include "adc.h"
#include "serial.h"
#include "utils.h"
unsigned volatile char buttonR = 0b00000001;
unsigned volatile char buttonL = 0b00000010;
void main_init()
{
    bitOn(PORTC, buttonR | buttonL);
    bitOff(DDRC, buttonR | buttonL);
}
main()
{
	volatile char val = 'a';

	adc_init();
	serial_init();
	main_init();
	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_get(3);
		volatile char c;
		if(bitRead(PINC, buttonR)){
			c = 0b00000000;
		}else{
			c = 0b00000001;
		}
		esperar(40); //bouncing
		/* realizar alguna acción con val */
		volatile char envio = (val<<1) | c ;
		serial_put_char(val);
	}

	for(;;);
}
