
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H

extern const volatile int SIZE;

void esperar();
void leds_init();
void update(unsigned char);


#endif	/* _UTILS_H */
