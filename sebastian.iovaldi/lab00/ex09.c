#include <stdio.h>

int main()
{
    unsigned char RES;
    unsigned char var;
    var = 190;
    RES = (unsigned char)(var*500)/190;

    printf("var: %d\n", var);
    printf("var*500: 32bits -> %d, 8bits -> %d \n", var*500, (unsigned char)(var*500));
    printf("%d / %d = %d\n", (unsigned char)(var*500), 190, (unsigned char)(var*500)/190);

    printf("RES: %d\n", RES);

    /*El valor aritmetico de var*500 no entra en 8 bits */

    return 0;
}