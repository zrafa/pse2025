#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

int port;

void serial_init()
{
    port = open("/dev/ttyUSB0", O_WRONLY, O_NOCTTY);

    if (port < 0)
        perror("Error al abrir el puerto");
}

void serial_send(uint8_t keys)
{
    printf("Sending: %x...\n", keys);
    write(port, &keys, 1);
}

void serial_close()
{
    close(port);
}