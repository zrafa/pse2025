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
	unsigned int dist_cm = 8;
	
	start_ultrasound();
	serial_init();
	/* un programa embebido nunca finaliza */
	for (;;) {
		serial_put_str("Envio señal... \r\n");

		dist_cm = ultrasound_get_distance();
		if(dist_cm == -1){
			serial_put_str("El objeto esta lejos\r\n");
		}
		else{
			serial_put_int(dist_cm, 4);	/* Mostrar distancia */
			serial_put_str("\r\n");
		}
		_delay_ms(10);
	}
}

