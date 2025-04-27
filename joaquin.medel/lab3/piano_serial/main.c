/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "speaker_driver.h"
#define ms 10000
int main(void)
{
    char rcvChar = 0;

    /* Configure the UART for the serial driver */
    serial_init();
    sound_init();
    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');

    while (rcvChar != 'q')
    {

        rcvChar = serial_get_char();

        if (rcvChar == 'a')
            sound(DO6, ms);
        if (rcvChar == 's')
            sound(RE6, ms);
        if (rcvChar == 'd')
            sound(MI6, ms);
        if (rcvChar == 'f')
            sound(FA6, ms);
        if (rcvChar == 'g')
            sound(SOL6, ms);
        if (rcvChar == 'h')
            sound(LA6, ms);
        if (rcvChar == 'j')
            sound(SI6, ms);
        if (rcvChar == 'k')
            sound(DO7, ms);
    }

    for (;;)
        ;

    return 0;
}
