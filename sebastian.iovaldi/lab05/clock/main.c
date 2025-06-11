#include "timer2.h"
#include "serial.h"
#include <util/delay.h>
#include <stdio.h>

uint16_t ticks = 0;

void update_clock()
{
    ticks = T2_GetTicks();
}

void show_clock()
{
    char str[9];
    sprintf(str, "%02d:%02d:%02d\r", (ticks/6000)%60, (ticks/100)%60, ticks%100);
    serial_put_str(str, 9);
};

int main()
{
    serial_init();
    T2_Init(update_clock);
    while(1)
    {
        _delay_ms(5);
        show_clock();
    }
}