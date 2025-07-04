
#include "adc.h"
#include "serial.h"
#include "led.h"
#include "button.h"
#include <util/delay.h>
#include <stdio.h>

#define MS 75

void send_bit(char x)
{   
    if(x) 
        led_on();
    else 
        led_off();
    _delay_ms(MS);
}

void send(uint8_t x)
{
    send_bit(0);
    for(int i=0; i<8; i++)
        send_bit((x >> i) & 1);
    send_bit(0);
    send_bit(1);
    send_bit(1);
    _delay_ms(MS);
}


int main()
{
    serial_init();
	adc_init();
    led_init();
    button_init();
    led_on();

	while(1)
    {  
        uint8_t value = serial_get_char();
        send(value);
	}
}


