#include <stdio.h>

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
tiene overflow
*/

int main(){
    unsigned char RES;
    unsigned char var;
    var = 190;
    printf("Origin "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(var));
    RES = (unsigned char)(var * 500) /190;
    printf("Modify "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(RES));
    return 0;
}