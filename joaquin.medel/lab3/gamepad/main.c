#include "utils.h"
#include "serial.h"
unsigned volatile char buttonR = 0b00000001;
unsigned volatile char buttonL = 0b00000010;
void main_init()
{
    bitOn(PORTC, buttonR | buttonL);
    bitOff(DDRC, buttonR | buttonL);
}
int main()
{
    main_init();
    serial_init();
    serial_put_char('a');
    while (1)
    {
        volatile char c = 0b00000000;
        if (!(bitRead(PINC, buttonR)))
        {
            c = c | buttonR;
        }
        if (!(bitRead(PINC, buttonL)))
        {
            c = c | buttonL;
        }
        serial_put_char(c);
        esperar(20);
    }
    return 0;
}