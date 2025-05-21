/* utils.c - funciones de soporte al programa principal */

#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8
#define BIT4 16
#define BIT5 32
#define BIT6 64

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_c = (unsigned char *) 0x28;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_c = (unsigned char *) 0x27;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   8000000UL
#include <util/delay.h>

void init()
{
    *ddr_c |= BIT4;
}

void sound(int freq, int duration)
{
    unsigned period = 1000000 / freq;
    unsigned half_period = period / 2;

    unsigned long elapsed = 0;
    unsigned long duration_us = (unsigned long)duration * 1000UL; 

    while(elapsed < duration_us)
    {
        *puerto_c |= BIT4;
        _delay_us(half_period);
        *puerto_c &= ~BIT4;
        _delay_us(half_period);
        elapsed += period;
    }
}