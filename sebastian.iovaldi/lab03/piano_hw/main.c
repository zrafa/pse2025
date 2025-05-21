 //#include "serial.h"

void play();
void sound_init();
void serial_init();
void serial_put_char (char c);
char serial_get_char(void);

int main(void)
{
    char rcvChar = 0;
 
    serial_init();
    sound_init();

    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');

    play();

    while(rcvChar != 'q')
    {
        /* Wait for an incoming character */
        rcvChar = serial_get_char();
 
        /* Echo the character back along with a carriage return and line feed */
        serial_put_char(rcvChar);
        serial_put_char('\r');
        serial_put_char('\n');
    }

    for (;;);
 
    return 0;
}