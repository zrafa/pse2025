

#include "utils.h"

int main(void)
{
    init();
    long counter = -1;
    unsigned long frame = 0;
    while (not_pushed())
    {
        esperar(25);
        if (!((++frame) % 50))
        {

            bitOff(PORTB, 0b00001111);
            bitOn(PORTB, (volatile unsigned char)(++counter) % 16);
        }
    }
}
/*
int main(void)
{
    init();
    unsigned char counter = 0;
    while (1)
    {
        esperar(5);
        while (not_pushed())
            ;
        esperar(5);
        while (!not_pushed())
            ;
        bitOff(PORTB, 0b00001111);
        bitOn(PORTB, (volatile unsigned char)(++counter) % 16);
    }
}*/
