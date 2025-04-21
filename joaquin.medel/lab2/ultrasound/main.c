/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "ultrasound.h"
#include "utils.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	int dist_cm = 8;

	serial_init();
	ultrasound_init();
	serial_put_int(dist_cm, 4); /* Mostrar distancia */
	led_init();
	/* un programa embebido nunca finaliza */
	for (;;)
	{
		led_off();
		serial_put_str("Comienzo buscar distancia  \r\n");

		dist_cm = ultrasound_get_distance();
		serial_put_int(dist_cm, 4); /* Mostrar distancia */
		serial_put_str("\r\n");
		if (dist_cm < 10)
		{
			led_on();
		}
		_delay_ms(1000);
	}
}
