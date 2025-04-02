#include "stdio.h"
#include "font.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
    int value = (int) *argv[1];
    if(argc < 2){
        printf("El programa %s requiere un argumento char\n",argv[0]);
        exit(1);
    }
    printf("%d\n",value);
    for(int i = 0; i < 4; i++){
        printf("%x\n",font[(5*value)+i]);
    }

    return 0;
}