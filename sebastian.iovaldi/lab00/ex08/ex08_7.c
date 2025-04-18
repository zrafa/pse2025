#define BIT6 64
#define BIT7 128

#include <stdio.h>

int main()
{
    int registro = 0x14;
    printf("reg: %08b\n", registro);

    registro |= ( BIT6 | BIT7 ); 
    printf("Setting 1 bit 6 & 7...\nreg: %08b\n", registro);

    return 0;
}