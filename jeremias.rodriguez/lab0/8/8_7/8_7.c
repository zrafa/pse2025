#include <stdio.h>
 
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c %c%c%c%c %c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x800 ? '1' : '0'), \
  ((byte) & 0x400 ? '1' : '0'), \
  ((byte) & 0x200 ? '1' : '0'), \
  ((byte) & 0x100 ? '1' : '0'), \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 


int main(){
    unsigned char c = 0;
    int a = 190*500;
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(c));
    printf("\n");
    c |= 0xC0;
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(c));
    printf("\n%i\n",c);
    return 0;
}