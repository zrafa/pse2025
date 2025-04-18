
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"
#include <stdio.h>
int main(void)
{	
	unsigned char i = 0;
    char dir = 1; // Dirección: 1 = derecha, -1 = izquierda
  
	led_init();
    while (1) {
		esperar();
        leds_on(i);
        
        i += dir;

        // Si llega al final o al principio, cambia de dirección
        if (i == SIZE - 1 || i == 0) {
            dir = -dir;
        }
            
    }
}


