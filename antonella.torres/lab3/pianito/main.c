/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "makesound.h"
int main(void)
{
    char rcvChar = 0;
    int ms=1000;

    

    /* Configure the UART for the serial driver */
    serial_init();
    init_ultrasound();


    sound(659,200);
    sound(659,200);
    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');

    while (rcvChar != 'q')
    {
        /* Wait for an incoming character */
        rcvChar = serial_get_char();
        if (rcvChar == 'a'){
            sound(261, ms);  // DO
        }            
        if (rcvChar == 'b')
            sound(293, ms);  // RE
        if (rcvChar == 'c')
            sound(329, ms);  // MI
        if (rcvChar == 'd')             
            sound(349, ms);  // FA
        if (rcvChar == 'e')             
            sound(392, ms);  // SOL
        if (rcvChar == 'f')             
            sound(440, ms);  // LA
        if (rcvChar == 'g')            
            sound(493, ms);  // SI 
      
      
        serial_put_char(rcvChar);

        serial_put_char('\r');
        serial_put_char('\n');
        

    }

    for (;;);

    return 0;
}

