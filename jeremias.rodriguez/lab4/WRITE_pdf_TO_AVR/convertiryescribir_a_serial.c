#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <errno.h>

int main() {
    const char *filename = "./fotito.jpg";
    FILE *file = fopen(filename, "rb");

    const char *device = "/dev/ttyUSB0";  // Ruta del dispositivo
    int fd = open(device, O_WRONLY);  // Abrir solo para escritura
    ssize_t bytes_written;

    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);


    printf("Se escribieron\n");
    // Reservar memoria para el contenido
    unsigned char *buffer = (unsigned char *)malloc(file_size * sizeof(char));
    memset(buffer, 0, file_size);
    if (!buffer) {
        perror("No se pudo asignar memoria");
        fclose(file);
        return 1;
    }

    printf("Se escribieron\n");
    size_t newLen = fread(buffer, sizeof(char), file_size, file);
    if ( ferror( file ) != 0 ) {
        fputs("Error reading file", stderr);
    } else {
        buffer[newLen++] = '\0'; /* Just to be safe. */
    }
    fclose(file);

    printf("Archivo leido: %ld bytes\n", file_size);

    if (fd < 0) {
        perror("No se pudo abrir el dispositivo");
        return 1;
    }

    sleep(5);
    printf("NOSE:\t%s\n",buffer);
    size_t len = sizeof(buffer);
    printf("Longitud: %d\n",newLen);

    for (size_t i = 0; i < newLen; i++) {
        ssize_t n = write(fd, &buffer[i], 1);
        if (n < 0) {
            perror("Error al escribir byte");
            break;
        }
        printf("Enviado %x\n", buffer[i]);
        usleep(1000*100);
    }
    
    

    printf("Se escribieron %ld bytes a %s\n", newLen, device);
    close(fd);
    return 0;

    // No olvides liberar la memoria
    free(buffer);
    return 0;
}