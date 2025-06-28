#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "adc.h"
#include "timer.h"
#include "serial.h"


double map(int val, int minInp, int maxInp,int minOut, int maxOut){
	double res;
	res = (double) val/maxInp;
	res = res*(maxOut-minOut);
	res= minOut+res;
	return res;
}

int main(void) {
    adc_init();
    timer_init();
    serial_init();
    uint16_t adc_val, last_val = 0, angle;

    while (1) {
        adc_val = adc_get(3);
        angle = map(adc_val,0,255,1000,3500);
        servo_angulo(angle);
        serial_put_int(angle, 4);
        serial_put_char('\r');
        serial_put_char('\n');
        _delay_ms(50);
   }
}