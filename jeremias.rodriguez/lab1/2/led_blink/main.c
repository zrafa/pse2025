
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"
#include "delay.h"

int main(void)
{	
	led_init();

	while (1) {
		delay_ms(100);
		led_on();

		delay_ms(100);
		led_off();
    }
}


