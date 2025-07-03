#include <avr/io.h>
#include <util/delay.h>
#include "timer1.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

#include "serial.h"
int main(void)
{
    serial_init();
    timer_init();

    while (1)
    {
        uint8_t dato = serial_get_char(); 
        timer_set_dato_raw(dato);         
    }
}