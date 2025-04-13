
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"

int main(void)
{	
	volatile unsigned int i = 0;
	volatile int direccion = 1;
	leds_init();

	while (1) {
		esperar();
		update(i);
		if(i == 0){
			direccion = 1;
		}
		else if(i == SIZE-1){
			direccion = -1;
		}
		i = i + direccion;
    }
}



