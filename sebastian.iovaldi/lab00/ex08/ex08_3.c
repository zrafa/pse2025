#define BIT3 3

#include <stdio.h>

int main()
{
    unsigned char status;
    
    status = 0b00110101;
    printf("%08b\n", status);

    printf("%08b OR  %08b = %08b\n", status, 0xFA, status | 0xFA);
    status = status | 0xFA;

    printf("%08b AND %08b = %08b\n", status, 20, status & 20);
    status = status & 20;

    printf("%08b OR  %08b = %08b\n", status, (1<<6), status | (1<<6));
    status |= (1 << 6);

    printf("%08b AND %08b = %08b\n", status, (unsigned char)(~(1 << BIT3)), (status & ~(1 << BIT3)));
    status &= ~(1 << BIT3);

    printf("%08b OR  %08b = %08b\n", status, (1 << BIT3), status | (1 << BIT3));
    status |= (1 << BIT3);
    
    return 0;
}