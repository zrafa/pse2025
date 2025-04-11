#define BIT3 8
#include <stdio.h>

int main()
{
    int registro = 0x19;
    if ( registro & BIT3 ) 
        printf ("el bit3 de la variable registro es 1 \n");

    return 0;
}
