#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "hw.h"


volatile unsigned long hperiod_us = 0;

void sound_init()
{
    *ddr_c |= BIT0 | BIT1;
}

void play()
{
    while(1)
    {
        if(!hperiod_us)
            continue;
            
        *port_c |= BIT0 | BIT1;
        _delay_us(hperiod_us);
        *port_c &= ~BIT0 | BIT1;
        _delay_us(hperiod_us);
    }
}