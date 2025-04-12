#include <stdio.h>
#include "font.h"

void print_char(char c)
{
    for(int i=0; i<5; i++)
        printf("%08b\n", font[(5*c)+i]);
}

int main(int argc, char** argv)
{
    if(argc < 2)
        fprintf(stderr, "Se necesita una caracter de argumento");
    else 
        print_char(*argv[1]);

    return 0;
}