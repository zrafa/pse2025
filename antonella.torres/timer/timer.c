#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

static volatile uint8_t centesimas = 0;
static volatile uint8_t segundos = 0;
static volatile uint8_t minutos = 0;

void timer2_init(void) {
    TCCR2A = (1 << WGM21);                // Modo CTC
    TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20); // prescaler 1024
    OCR2A = 156;                         // Comparación para 10 ms
    TIMSK2 = (1 << OCIE2A);              // Habilitar interrupción compare A
    sei();                              // Habilitar interrupciones globales
}

ISR(TIMER2_COMPA_vect) {
    centesimas++;
    if (centesimas >= 100) {
        centesimas = 0;
        segundos++;
        if (segundos >= 60) {
            segundos = 0;
            minutos++;
            if (minutos >= 60) {
                minutos = 0;
            }
        }
    }
}

uint8_t get_centesimas(void) { return centesimas; }
uint8_t get_segundos(void) { return segundos; }
uint8_t get_minutos(void) { return minutos; }
