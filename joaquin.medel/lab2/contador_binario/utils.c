
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los
 * pines 8-13 de arduino
 */

/* puertos de E/S */

#include "utils.h"
void bitOn(volatile unsigned char *registro, volatile unsigned char bits)
{
	*registro |= bits;
}
void bitOff(volatile unsigned char *registro, volatile unsigned char bits)
{
	*registro &= ~bits;
}
int not_pushed()
{
	return *PINC & 32;
}
void led_init()
{
	bitOn(DDRB, 0b100000);
}
void led_on()
{
	bitOn(PORTB, 0b100000);
}
void led_off()
{
	bitOff(PORTB, 0b100000);
}
void init()
{
	bitOff(DDRC, 0b100000);
	bitOn(PORTC, 0b100000);
	bitOn(DDRB, 0b1111);
	bitOff(PORTB, 0b1111);
}
void esperar(volatile unsigned int n)
{
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	volatile unsigned long j = 359ul * n;
	for (i = 0; i < j; i++)
		;
}
