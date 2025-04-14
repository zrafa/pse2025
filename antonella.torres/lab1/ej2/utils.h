
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H

extern const volatile int SIZE;  


void esperar();
void led_init();
void leds_on();
void led_off();


#endif	/* _UTILS_H */
