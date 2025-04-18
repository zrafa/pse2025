#define BIT0 1
#define BIT1 2
#define BIT2 4

#include <stdio.h>

int main()
{
    int registro = 0xD7;
    printf("reg: %08b\n", registro);

    registro &= ~( BIT0 |BIT1 | BIT2 ); 
    printf("Setting 0 bit 0, 1 & 2...\nreg: %08b\n", registro);

    return 0;
}