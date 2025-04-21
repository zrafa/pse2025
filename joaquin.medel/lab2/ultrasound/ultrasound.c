/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

// trigger conectado a D8 PB0
// echo conectado a D9 PB1
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 16000000UL
#include "utils.h"
#include <util/delay.h>

void ultrasound_init(void)
{
	bitOn(DDRB, 0b00000001);
	bitOff(DDRB, 0b00000010);
}

volatile int isEchoActivated()
{
	return (volatile int)((*PORTB & 0b00000010) == 0b00000010);
}
/* ultrasound_get_distance()
 * 	devuelve la distancia en cm del objeto delante del sensor
 * 	devuelve -1 si no existe ningun objeto
 */
int ultrasound_get_distance(void)
{
	volatile int i = -1;
	volatile int mSTardados = 0;
	volatile int cm = 0;
	bitOn(PORTB, 0b00000001);
	_delay_us(10); /* espero 1000 microsegundos (1 milisegundo) */
	bitOff(PORTB, 0b00000001);
	/* completar con driver de ultrasonido */
	while (!isEchoActivated)
	{
		_delay_us(1);
		mSTardados++;
	}
	while (isEchoActivated)
	{
		/* code */
	}
	_delay_us(10);
	i = mSTardados / 58;
	return i;
}
