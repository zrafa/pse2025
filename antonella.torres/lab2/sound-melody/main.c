
#include "serial.h"
#include "makesound.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>



int main(void)
{

   

    int melody[] = {
        659, 659, 0, 659, 0, 523, 659, 784, 392,    
        523, 392, 330, 440, 494, 466, 440, 392, 523, 
        659, 784, 880, 698, 784, 659, 523, 440, 494, 523
    };
    
    int durations[] = {
        400, 400, 400, 400, 400, 400, 400, 600, 800,
        400, 400, 400, 400, 400, 400, 400, 400, 600,
        400, 400, 400, 400, 400, 400, 400, 400, 400, 800
    };
    
    int pauses[] = {
        150, 150, 150, 150, 150, 150, 150, 400, 600,
        150, 150, 150, 150, 150, 150, 150, 150, 400,
        150, 150, 150, 150, 150, 150, 150, 150, 150, 600
    };
    
 
        while (1) {
            for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
                sound(melody[i], durations[i]);
                _delay_ms(pauses[i]);

            }
        }



    
}

