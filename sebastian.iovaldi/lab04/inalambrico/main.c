
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

uint8_t recv_bit()
{
    uint8_t value = adc_get(1);
    _delay_ms(MS);
    return value > 50;
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

uint8_t recv()
{
    while(recv_bit());
    uint8_t result = 0;

    for(int i=0; i<8; i++)
        result |= (recv_bit() >> i);
    return result;
}

int main()
{
    serial_init();
	adc_init();
    led_init();
    button_init();
    led_on();

    char* str = "Hola mundo!"; 

	while(1)
    {  
        uint8_t value = serial_get_char();
        send(value);
     //   uint8_t buffer[4];
     //   for(int i=0; i<4; i++)
     //   {
     //        buffer[i] = serial_get_char();
     //       send(buffer[i]);
     //       serial_put_char(buffer[i]);
     //   }
      //   send('h');
      //   send('o');
      //   send('l');
      //   send('a');
      //   send(' ');
      //   send('m');
      //   send('u');
      //   send('n');
      //   send('d');
      //   send('o');
      //   send('!');

        

        //serial_put_char(value);
   //     for(int i=0; i<4; i++)

        
      //  for(int i=0; i<10; i++)
      //      send(str[i]);


      //  while(!button_pulsed());

	}
}


