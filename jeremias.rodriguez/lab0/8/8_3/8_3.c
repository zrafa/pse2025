#include <stdio.h>

#define BIT3 4

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

/*
Son el and y el or binarios
*/

int main(){
    unsigned char status;

    status = 0b00110101;
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    status = status | 0xFA;
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    status = status & 20;
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    status |= (1 << 5);
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    status &= ~(1 << BIT3);
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    status |= (1 << BIT3);
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(status));
    printf("\n%i\n",status);
    
    return 0;
}