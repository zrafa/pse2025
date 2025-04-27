/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"

int main(void)
{
    char rcvChar = 0;

    /* Configure the UART for the serial driver */
    serial_init();

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

        serial_put_char(rcvChar);
        serial_put_char('\r');
        serial_put_char('\n');
    }

    for (;;)
        ;

    return 0;
}
