#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define HEADER_SIZE 44  
#define DEVICE "/dev/ttyUSB0"  

int main() {
    const char *filename = "ratatouille.wav";
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("No se pudo abrir el archivo WAV");
        return 1;
    }


    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    printf("filesize %ld \n", file_size);
    rewind(file);

    if (file_size <= HEADER_SIZE) {
        fprintf(stderr, "Archivo inválido o vacío\n");
        fclose(file);
        return 1;
    }

    // Saltar la cabecera WAV
    fseek(file, HEADER_SIZE, SEEK_SET);
    long data_size = file_size - HEADER_SIZE;

    // Abrir el dispositivo serie
    int fd = open(DEVICE, O_WRONLY);
    if (fd < 0) {
        perror("No se pudo abrir el dispositivo serie");
        fclose(file);
        return 1;
    }

    unsigned char byte;
    long sent = 0;
    while (fread(&byte, 1, 1, file) == 1) {
        //printf("Byte %ld: 0x%02X\n", sent, byte);
        write(fd, &byte, 1);
        usleep(125);  // 8000 Hz = 125 µs entre muestras
        sent++;
    }

    printf("Se enviaron %ld bytes de audio a %s\n", sent, DEVICE);

    close(fd);
    fclose(file);
    return 0;
}
