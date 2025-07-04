 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   8000000UL
 #include <util/delay.h>
 #include "utils.h"
 int melody[] = {
    155, 174, 196, 207, 196, 174, 155,  // E♭3, F3, G3, A♭3, G3, F3, E♭3
    155, 174, 196, 207, 233, 196, 174,  // E♭3, F3, G3, A♭3, B♭3, G3, F3
    155, 196, 207, 233, 207, 196, 174,  // E♭3, G3, A♭3, B♭3, A♭3, G3, F3
    155, 174, 196, 207, 196, 174, 155   // E♭3, F3, G3, A♭3, G3, F3, E♭3
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
 