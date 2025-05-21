#include "joypad.hpp"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

joypad::joypad() : 
    port { open("/dev/ttyUSB0", O_RDONLY | O_NOCTTY) },
    process {[this](){ while(running) code_m = recv(); }}
{
    if (port < 0)
    {
        std::cerr << "Joypad not found.\n";
        std::terminate();
    }

    struct termios tty;
    tcgetattr(port, &tty);

    cfsetispeed(&tty, B2400);
    cfsetospeed(&tty, B2400);

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

joypad::~joypad()
{
    running = false;
    process.join();
    close(port);
}

bool joypad::pulsed()
{
    bool pulsed = code_m & 128;
    code_m &= 127;
    return pulsed;
}

std::uint8_t joypad::sensor() const
{
    return code_m & 127;
}

std::uint8_t joypad::recv() const
{
    std::uint8_t buffer;

    if (read(port, &buffer, 1) > 0)
        return buffer;
    
    return 0x00;
}