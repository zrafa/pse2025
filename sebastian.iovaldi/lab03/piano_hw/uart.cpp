#include "uart.hpp"

void uart::rtx(bool on)
{
    puerto_serial->status_control_b |= 0x10;
}