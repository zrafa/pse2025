/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include <avr/io.h>

volatile unsigned char CONFIG_ADMUX = 0b01000000;
volatile unsigned char CONFIG_ADCSRA = 0b10000000;
volatile unsigned char CONFIG_PRESCALAR = 0b00000111; //Es parte del adcsra

volatile unsigned char START_CONVERT = 0b01000000;

/* Estructura de datos del driver ADC */

typedef struct
{
        uint8_t adcl;               /* ADC Data Register Low */
        uint8_t adch;
        uint8_t adcsra; /* ADC Control and Status Register A */
        uint8_t adcsrb;
        uint8_t admux; /* ADC Multiplexer Selection Register */
        uint8_t reserved;
        uint8_t didr0;
} volatile adc_t;

volatile adc_t *adc = (adc_t *)(0x78);/* direccion del primer registro */

void adc_init(void) {
    ADMUX = (1 << REFS0) | (1 << ADLAR); // AVcc como referencia, resultado alineado a la izquierda
    ADCSRA = (1 << ADEN)                 // Habilita el ADC
           | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128
}

uint8_t adc_get(uint8_t input) {
    ADMUX = (ADMUX & 0xF0) | (input & 0x0F);  // Selección de canal (baja 4 bits)
    ADCSRA |= (1 << ADSC);                   // Inicia conversión
    while (ADCSRA & (1 << ADSC));            // Espera fin
    return ADCH;                             // Solo los bits más significativos
}

