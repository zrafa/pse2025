#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>





void sound(int frec, int duracion){

    /* direccion de PORTB (registro de datos) */
    volatile unsigned char * puerto_b = (unsigned char *) 0x25;

    unsigned long medio_periodo = (1000000UL / frec) / 2; //El periodo es cuanto dura un ciclo (1 seg/ frec). Medio periodo, es el tiempo que el pin debe estar en alto o en bajo
    unsigned long tiempo_total = duracion * 1000UL;
    unsigned long tiempo_actual = 0;

    while (tiempo_actual < tiempo_total) {
        * puerto_b |= (1 << 5);
        _delay_us(medio_periodo);
        * puerto_b &= ~(1 << 5);
        _delay_us(medio_periodo);

        tiempo_actual += medio_periodo*2;
    }
}