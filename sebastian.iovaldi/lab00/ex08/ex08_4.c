#include <stdio.h>

int main()
{
    unsigned char x = 11;
    printf("x: %d. Base 2: %08b\n", x, x);

    for(int i=0; i<8; i++)
        printf("bit %d: %d\n", i, (x >> i) & 1);
    
    return 0;
}