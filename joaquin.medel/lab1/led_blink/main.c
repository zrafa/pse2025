
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/*
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los
 * pines 8-13 de arduino
 */

#include "utils.h"

int main(void)
{
	led_init();
	led_on();
	while (1)
	{
		esperar(1000);
		led_on();

		esperar(1000);
		led_off();
	}
}
