#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h> // ← necesario para system()
#define charR Right
#define charL Left
#define STR(s) #s
#define XDOTOOL_KEYDOWN(key) "xdotool keydown " STR(key)
#define XDOTOOL_KEYUP(key) "xdotool keyup " STR(key)
int main()
{
    const char *portname = "/dev/ttyUSB0";
    int serial_port = open(portname, O_RDONLY | O_NOCTTY);
    if (serial_port < 0)
    {
        perror("Error abriendo el puerto serial");
        return 1;
    }

    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0)
    {
        perror("Error obteniendo configuración del puerto");
        close(serial_port);
        return 1;
    }

    // Configuración
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= PARENB;
    tty.c_cflag &= ~PARODD;
    tty.c_cflag &= ~CSTOPB;

    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);

    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_oflag &= ~OPOST;

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
    {
        perror("Error aplicando configuración del puerto");
        close(serial_port);
        return 1;
    }

    unsigned char byte;

    while (1)
    {
        int n = read(serial_port, &byte, 1);
        if (n <= 0)
            continue;
        printf(" \r El byte que llego es ,%i \n",byte);
        

    }

    close(serial_port);
    return 0;
}
