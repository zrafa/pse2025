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
0 4 8 C 0 4
ptr al final: 0xFFA0000C | Como es int se desplaza de a 4 bytes por el tamaño del int
21, ya que a traves de b se puede modificar
Direccion de x[2] es la de ptr al finalizar
*/

int main () {

	int x[3];
	int *ptr;

	char a;
	char *b;

    x[0] = 10;
    x[1] = 32;
    x[2] = 101;
	ptr = &x[0];
    printf("%X\n",ptr);
	ptr++;
	ptr++;
    printf("%X\t%i\n",ptr,*ptr);
	a = 5;
	b = &a;
	printf ("a=%i, lo apuntado por b=%i, el contenido de b=%X, y la direccion de b=%X \n", a, *b, b, &b);
	
	*b = 21;
    printf ("a=%i, lo apuntado por b=%i, el contenido de b=%X, y la direccion de b=%X \n", a, *b, b, &b);
	
}