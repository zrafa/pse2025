#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/time.h>

#define BUFFER_SIZE 4096
#define TIMEOUT_SEC 5
#define SERIAL_PORT "/dev/ttyUSB0"             // Cambiar si tu Arduino aparece como /dev/ttyUSB0
#define OUTPUT_FILE "archivo_recibido.jpg"     // MODIFICADO: nombre del archivo de salida

// Función para calcular segundos transcurridos
int tiempo_transcurrido(struct timeval inicio) {
    struct timeval ahora;
    gettimeofday(&ahora, NULL);
    return (ahora.tv_sec - inicio.tv_sec);
}

int main() {
    // Abrir puerto serial
    int puerto_serial = open(SERIAL_PORT, O_RDONLY | O_NOCTTY);
    if (puerto_serial < 0) {
        perror("Error al abrir el puerto serial");
        return 1;
    }

    // Esperar por reinicio del Arduino
    printf("Esperando que Arduino se reinicie...\n");
    sleep(2);

    // Configurar parámetros del puerto
    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    if (tcgetattr(puerto_serial, &tty) != 0) {
        perror("Error en tcgetattr");
        close(puerto_serial);
        return 1;
    }

    // MODIFICADO: velocidad cambiada a 9600
    cfsetispeed(&tty, B9600);   // MODIFICADO
    cfsetospeed(&tty, B9600);   // MODIFICADO

    tty.c_cflag |= (CLOCAL | CREAD); // Habilitar recepción
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;              // 8 bits de datos
    tty.c_cflag &= ~PARENB;          // Sin paridad
    tty.c_cflag &= ~CSTOPB;          // 1 bit de parada
    tty.c_cflag &= ~CRTSCTS;         // Sin control de flujo

    tty.c_lflag = 0; // Modo sin procesamiento
    tty.c_iflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 0;

    tcflush(puerto_serial, TCIFLUSH);
    if (tcsetattr(puerto_serial, TCSANOW, &tty) != 0) {
        perror("Error en tcsetattr");
        close(puerto_serial);
        return 1;
    }

    // Abrir archivo de salida
    FILE *archivo = fopen(OUTPUT_FILE, "wb");  // Modo binario por compatibilidad
    if (!archivo) {
        perror("Error al crear el archivo de salida");
        close(puerto_serial);
        return 1;
    }

    printf("Leyendo datos desde %s a 9600 baudios...\n", SERIAL_PORT);

    unsigned char buffer[BUFFER_SIZE];
    int total_bytes = 0;
    struct timeval ultimo_byte;
    gettimeofday(&ultimo_byte, NULL);

    while (1) {
        int bytes_leidos = read(puerto_serial, buffer, sizeof(buffer));
        if (bytes_leidos > 0) {
            fwrite(buffer, 1, bytes_leidos, archivo);
            total_bytes += bytes_leidos;
            gettimeofday(&ultimo_byte, NULL); // reinicia temporizador
        } else {
            if (tiempo_transcurrido(ultimo_byte) >= TIMEOUT_SEC) {
                break;
            }
            usleep(100000); // Dormir 100 ms
        }
    }

    printf("Lectura finalizada. Bytes recibidos: %d\n", total_bytes);

    fclose(archivo);
    close(puerto_serial);

    printf("Archivo guardado como '%s'\n", OUTPUT_FILE);
    return 0;
}
