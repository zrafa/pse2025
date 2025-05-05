/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "pin_config.h"
#include <util/delay.h>

volatile unsigned char pin_button_L = 0b00000100;
volatile unsigned char pin_button_R = 0b00000010;
volatile unsigned char pin_button_Shot = 0b00000001;

volatile unsigned char pin_5 = 0b00100000;
void config_sound();
void wait(volatile long int n);
void sound(long int frec, long int duracion);


int main(void)
{
    char rcvChar = 0;
    
    make_input_DDRB_PUP(pin_button_Shot);
    make_input_DDRB_PUP(pin_button_L);
    make_input_DDRB_PUP(pin_button_R);
    make_output_DDRB(pin_5);
    /* Configure the UART for the serial driver */
    serial_init();
    volatile int duration_nota;
    duration_nota = 1000 / (8*3);

    while (rcvChar != 'q')
    {
        
        /* Wait for an incoming character */
        
        if(read_signal_B(pin_button_R) == 0){
            serial_put_char('s');
            _delay_ms(100);
        }
        if(read_signal_B(pin_button_Shot) == 0){
            serial_put_char('d');
            _delay_ms(100);
        }
        if(read_signal_B(pin_button_L) == 0){
            serial_put_char('a');
            _delay_ms(100);
        }
    }

    for (;;);

    return 0;
}

