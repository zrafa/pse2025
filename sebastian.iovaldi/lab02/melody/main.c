/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */
 
 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   8000000UL
 #include <util/delay.h>
 #include "utils.h"
 float melody[] = {
    155.56f, 174.61, 196.00, 207.65, 196.00, 174.61, 155.56,  // E♭3, F3, G3, A♭3, G3, F3, E♭3
    155.56, 174.61, 196.00, 207.65, 233.08, 196.00, 174.61,  // E♭3, F3, G3, A♭3, B♭3, G3, F3
    155.56, 196.00, 207.65, 233.08, 207.65, 196.00, 174.61,  // E♭3, G3, A♭3, B♭3, A♭3, G3, F3
    155.56, 174.61, 196.00, 207.65, 196.00, 174.61, 155.56   // E♭3, F3, G3, A♭3, G3, F3, E♭3
};

int main(void)
{
    init();
    int i = 0;
    while(1)
    {
        sound(melody[i++], 100);
    }

    
 }
 