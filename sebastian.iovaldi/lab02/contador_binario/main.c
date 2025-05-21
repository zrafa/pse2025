#include "utils.h"

int main(void)	
{	
	init();
	unsigned char counter = 0;

    int running = 0;

	while (1) 
	{
        if(pulsed())
            running = !running;

        delay_ms(300);

        if(running)
            set_leds((++counter)%16);
	}
}