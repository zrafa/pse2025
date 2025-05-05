/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "pin_config.h"


volatile unsigned char trigger_pin = 0b00000001;
volatile unsigned char echo_pin = 0b00000010;
volatile unsigned char pin_5 = 0b00100000;

volatile int signal;

void start_ultrasound(){
	make_input_DDRB(echo_pin);
	make_output_DDRB(trigger_pin);
	make_output_DDRB(pin_5);
}

/* ultrasound_get_distance()
 * 	devuelve la distancia en cm del objeto delante del sensor
 * 	devuelve -1 si no existe ningun objeto
 */
int ultrasound_get_distance(void)
{
	volatile int i = -1, tiempo = 0;
	/* completar con driver de ultrasonido */
	//Mando una señal durante 10US,
	//Espero la respuesta si pasan mas de 36ms, no habra respuesta
	//Pregunto durante 36ms si hubo respuesta o hasta encontrar
	write_signal_B(trigger_pin, 1);
	_delay_us(10);
	write_signal_B(trigger_pin, 0);
	
	while((read_signal_B(echo_pin)) == 0){}
	while((read_signal_B(echo_pin)) != 0 && tiempo < 36000){
		_delay_us(1);
		tiempo++;
	}

	if(tiempo < 36000){
		i = tiempo/14;
	}

	return i;
}
