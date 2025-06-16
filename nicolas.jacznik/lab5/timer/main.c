#include <avr/io.h>
#include <avr/interrupt.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "serial.h"
#include "timer2.h"


typedef struct {
    volatile uint8_t centesimas;
    volatile uint8_t segundos;
    volatile uint8_t minutos;
} Cronometro;

volatile Cronometro cronometro = {0, 0, 0};
volatile uint16_t ticks = 0;


ISR(TIMER2_COMPA_vect) {
    ticks++;

    cronometro.centesimas++;
    if (cronometro.centesimas >= 100) {
        cronometro.centesimas = 0;
        cronometro.segundos++;
        if (cronometro.segundos >= 60) {
            cronometro.segundos = 0;
            cronometro.minutos++;
            if (cronometro.minutos >= 100) {
                cronometro.minutos = 0;
            }
        }
    }
}

int main(void) {
    serial_init();
    timer2_init_ctc();
    sei();  //interrupciones globales

    while (1) {
        serial_put_char('\n');
        serial_put_two_digits(cronometro.minutos);
        serial_put_char(':');
        serial_put_two_digits(cronometro.segundos);
        serial_put_char(':');
        serial_put_two_digits(cronometro.centesimas);
        _delay_ms(100);
    }
}
