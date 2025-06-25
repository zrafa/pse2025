
#include "adc.h"
#include "serial.h"
#include "utils.h"

#include <stdint.h> 
#include <util/delay.h>
#include "speaker_driver.h"
#define umbral 0x50
#define msCiclo 75
#define msInicial 75

unsigned volatile char buttonR = 0b00000001;
unsigned volatile char buttonL = 0b00000010;
void main_init()
{
    bitOn(PORTC, buttonR | buttonL);
    bitOff(DDRC, buttonR | buttonL);
}
int main()
{
	volatile uint8_t val = 'a';
	
	adc_init();
	serial_init();
	main_init();
	sound_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_get(4);
		volatile char c = 0;
		/* realizar alguna acción con val */
		while(val > umbral){
			val = adc_get(4);
		}
		//_delay_ms(msCiclo/3);
		_delay_ms(msInicial*1.5);
		for(int i =0;i<8;i++){
			val = adc_get(4);
			if(val > umbral){
				c = c | 1 << i;
			}
			_delay_ms(msCiclo);
		};
		val = adc_get(4);
		if(val < umbral){
			_delay_ms(msCiclo);
		}
		serial_put_char(c);
		c = 0;


	}
	while(0){
		val =adc_get(4);
		serial_put_char(val);
	}

	for(;;);
}
