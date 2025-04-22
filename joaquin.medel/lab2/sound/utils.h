
/* utils.h - funciones de soporte al programa principal */

/*
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los
 * pines 8-13 de arduino
 */

#ifndef _UTILS_H
#define _UTILS_H

#define PORTB (volatile unsigned char *)0x25
#define DDRB (volatile unsigned char *)0x24
#define PINB (volatile unsigned char *)0x23

void esperar(volatile unsigned int);
void led_init();
void led_on();
void led_off();
void bitOff(volatile unsigned char *registro, volatile unsigned char bits);
void bitOn(volatile unsigned char *registro, volatile unsigned char bits);
#endif /* _UTILS_H */
