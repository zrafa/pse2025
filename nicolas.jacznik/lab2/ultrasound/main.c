/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "ultrasound.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

int main(void)
{
	int dist_cm = 8;

	serial_init();
	/* un programa embebido nunca finaliza */
	for (;;) {
		serial_put_str("La distancia es de ");

		dist_cm = ultrasound_get_distance();
		serial_put_int(dist_cm, 4);	/* Mostrar distancia */
		serial_put_str(" cm.\r\n");

		_delay_ms(2000);
	}
}
