#include <stdio.h>

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {  // Recorremos de bit más significativo a menos significativo
        printf("%d", (byte >> i) & 1);
    }
}

int main() {
    unsigned char byte = 0b10111110; // Ejemplo de byte en binario
    printf("Representación binaria: ");
    printBinary(byte);
    printf("\n");

    return 0;
}
