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
inicializa un array modifica el valor 2
- Crea un puntero que apunta a array
    lo desplaza 2 lugares y le asigna 99 al elto
- Luego reinicia el puntero
*/

int main () {
    unsigned int array[5];
    array[2] = 99;

    unsigned int *pointer;
    pointer = &array[0];
    *(pointer+2) = 99;

    pointer = array;
}