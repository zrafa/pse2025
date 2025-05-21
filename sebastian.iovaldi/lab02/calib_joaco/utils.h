
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H

//#define esperar(n) for(volatile unsigned long i=0; i<1780ul*n; i++)

void esperar(int ms);
void led_init();
void led_on();
void led_off();


#endif	/* _UTILS_H */
