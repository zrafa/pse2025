#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "adc.h"
#include "timer.h"
#include "pin_config.h"

double map(int val, int minInp, int maxInp,int minOut, int maxOut){
	double res;
	res = (double) val/maxInp;
	res = res*(maxOut-minOut);
	res= minOut+res;
	return res;
}

int main(void) {
    adc_init();
    //timer_init();
    uint16_t adc_val, last_val = 0, angle;
    int count = 0; 
    make_output_DDRB(0b00000001);
    make_output_DDRB(0b00000010);
    make_output_DDRB(0b00100000);
    make_input_DDRB_PUP(0b00010000);
    
    write_signal_B(0b00100000, 1);
    while (1) {
        switch(count){
            case 0:
                write_signal_B(0b00000001, 1);
                write_signal_B(0b00000010, 0);
                break;
            case 1:
                write_signal_B(0b00000001, 0);
                write_signal_B(0b00000010, 1);
                break;
            default:
                write_signal_B(0b00000001, 0);
                write_signal_B(0b00000010, 0);
                break;
        }
        if(read_signal_B(0b00010000) == 0){
            count = (count+1)%3;
            _delay_ms(30); 
        }
        _delay_ms(20); 
   }
}