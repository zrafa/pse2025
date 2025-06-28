#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "serial.h"
#include "timer.h"

extern volatile unsigned long time;

void main(){
	timer_init();
    serial_init();
    unsigned long ticks_actual, horas, minutos, segundos;
    while(1){
        //Time 1 = 0.01 Segundo
        ticks_actual = time;
        segundos = ticks_actual/100;
        horas = segundos/3600;
        minutos = (segundos%3600)/60;
        segundos = (segundos%3600)%60;

        serial_put_int(horas, 2);
        serial_put_char(':');
        serial_put_int(minutos, 2);
        serial_put_char(':');
        serial_put_int(segundos, 2);
        serial_put_char('\r');
        _delay_ms(500);
    }
}
