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
    make_output_DDRB(0b00000001);
    make_output_DDRB(0b00000010);
    make_output_DDRB(0b00100000);
    
    write_signal_B(0b00100000, 1);
    while (1) {
        write_signal_B(0b00000001, 1);
        write_signal_B(0b00000010, 0);
        //set_motor_speed(100);
        _delay_ms(20);  // Delay pequeño para estabilidad
   }
}