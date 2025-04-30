#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 16000000UL
#include <util/delay.h>
#include "utils.h"
#include "serial.h"
#define SPEAKER_PIN 0b00000100 // PORTB2 (bit 2)

void sound_init()
{
    bitOn(DDRB, SPEAKER_PIN); // Configura el pin como salida
}

void sound(volatile int frecuencia, volatile int duracion)
{
    // 1/frecuencia segundos de cada ciclo, 1000000/frecuencia uS de cada ciclo
    if (frecuencia == 0)
    {
        _delay_ms(duracion);
        return;
    }

    unsigned long uS = 500000UL / frecuencia; // medio ciclo

    // Convierte la duración de mS a uS
    unsigned volatile long duracionUs = (unsigned long)duracion * 1000;
    unsigned volatile long i = 0;
    while (i < duracionUs)
    {
        bitOn(PORTB, SPEAKER_PIN);
        _delay_us(uS);
        bitOff(PORTB, SPEAKER_PIN);
        _delay_us(uS);
        i += uS * 2;
    }
}
void sound2(volatile int frecuencia, volatile char c)
{
    // 1/frecuencia segundos de cada ciclo, 1000000/frecuencia uS de cada ciclo

    unsigned long uS = 500000UL / frecuencia; // medio ciclo

    // Convierte la duración de mS a uS

    while (c == serial_get_char())
    {
        bitOn(PORTB, SPEAKER_PIN);
        _delay_us(uS);
        bitOff(PORTB, SPEAKER_PIN);
        _delay_us(uS);
    }
}