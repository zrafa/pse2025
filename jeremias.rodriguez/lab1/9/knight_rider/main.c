
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



