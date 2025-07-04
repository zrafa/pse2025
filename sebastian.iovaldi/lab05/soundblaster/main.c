#include "timer1.h"
#include "adc.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "serial.h"

volatile uint8_t value = 10;

ISR(TIMER1_COMPB_vect)
{
    setCompareA(value);
}

int main()
{
    timer1_init();
    serial_init();

    int i = 0;
    while(1)
    {
        value = serial_get_char();
    }
}