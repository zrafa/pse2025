
#pragma once 

#include <cstdint>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

struct transmitter
{
    transmitter()
    {
        port = open("/dev/ttyUSB0", O_RDWR, O_NOCTTY);
        if (port < 0)
        {
            perror("Error opening /dev/ttyUSB0");
            exit(-1);
        }
        set_up();
        printf("Press any key to start...\n");
        getchar();

    }   
    

    ~transmitter()
    {
        if(port < 0)
            close(port);
    }

    void send(std::uint8_t byte)
    {
        write(port, &byte, 1);
        sleep(1);
    }

    std::uint8_t recv()
    {
        std::uint8_t byte;
        if (read(port, &byte, 1) > 0)
            return byte;
        perror("Error reading byte");
        return 0xff;
    }

private:

    int port { -1 };

    void set_up()
    {
        struct termios tty;
        tcgetattr(port, &tty);

        cfsetispeed(&tty, B9600);
        cfsetospeed(&tty, B9600);

        tty.c_cflag &= ~PARENB; // No parity
        tty.c_cflag &= ~CSTOPB; // One stop bit
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;     // 8 bits per byte
        tty.c_cflag |= CREAD | CLOCAL;

        tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // Raw mode
        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off flow control
        tty.c_oflag &= ~OPOST; // Raw output   
        
        tcsetattr(port, TCSANOW, &tty);  
    }
};
