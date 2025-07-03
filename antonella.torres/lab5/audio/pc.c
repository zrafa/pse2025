#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#define CABECERA_WAV 44
#define VELOCIDAD_BAUD B115200
#define PUERTO_SERIE "/dev/ttyUSB0"  // Cambiar si es diferente

int main() {
    // Abrir archivo WAV
    FILE *wav = fopen("salida.wav", "rb");
    if (!wav) {
        perror("Error abriendo archivo WAV");
        return 1;
    }

    // Saltar la cabecera de 44 bytes
    fseek(wav, CABECERA_WAV, SEEK_SET);

    // Abrir puerto serie
    int serial = open(PUERTO_SERIE, O_WRONLY | O_NOCTTY);
    if (serial < 0) {
        perror("Error abriendo el puerto serie");
        fclose(wav);
        return 1;
    }

    // Configurar puerto serie
    struct termios opciones;
    tcgetattr(serial, &opciones);
    cfsetispeed(&opciones, VELOCIDAD_BAUD);
    cfsetospeed(&opciones, VELOCIDAD_BAUD);
    opciones.c_cflag |= (CLOCAL | CREAD); // Habilitar lectura y señal local
    opciones.c_cflag &= ~CSIZE;
    opciones.c_cflag |= CS8;              // 8 bits
    opciones.c_cflag &= ~PARENB;          // Sin paridad
    opciones.c_cflag &= ~CSTOPB;          // 1 bit de stop
    opciones.c_cflag &= ~CRTSCTS;         // Sin control de flujo
    tcsetattr(serial, TCSANOW, &opciones);

    // Leer y enviar byte por byte
    unsigned char buffer;
    while (fread(&buffer, 1, 1, wav) == 1) {
        write(serial, &buffer, 1);
        usleep(125);  // ~8000 muestras por segundo (1/8000 s = 125 µs)
    }

    // Cierre
    close(serial);
    fclose(wav);

    printf("Transferencia finalizada.\n");
    return 0;
}
