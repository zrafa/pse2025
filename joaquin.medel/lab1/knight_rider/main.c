#include "utils.h"
#define ms 500
int arr[] = {
    0b0000,
    0b0001,
    0b0001,
    0b0011,
    0b0110,
    0b1100,
    0b1000,
    0b0000};

int main(void)
{
    char volatile i = 0;
    char volatile n = 8;
    bitOn(DDRB, 0b1111);
    esperar(ms);
    while (1)
    {
        i = 0;
        while (i < 8)
        {
            bitOff(PORTB, 0b1111);
            bitOn(PORTB, arr[i]);
            i++;
            esperar(ms);
        }
        i = 7;
        while (i >= 0)
        {
            /* code */
            bitOff(PORTB, 0b1111);
            bitOn(PORTB, arr[i]);
            i--;
            esperar(ms);
        }
    }
}