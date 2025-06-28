/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"

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

volatile adc_t *adc = (adc_t *) (0x78);


void adc_init()
{
    /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
    de vcc con capacitor externo y encender (habilitar) el periferico */
    adc->admux |= (1 << 6);
    adc->adcsra |= (1 << 7);
    /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
    adc->adcsra |= (1 << 2) | (1 << 1) | (1 << 0);
}

uint16_t adc_get(char input)
{
    int val;
    /* 1. Selects which analog input is connected to the ADC */
    adc->admux |= (input & 0x0F);
    /* 2. Write this bit to one to start each conversion */
    adc->adcsra |= (1 << 6);
    /* 3. When conversion is complete, it returns to zero */
    while(!((adc->adcsra) & (1 << 6)));
    /* 4. When conversion is complete, read the data register */
    /* IMPORTANT: ADCL must be read first, then ADCH */
    val = ((uint16_t) adc->adcl) | (((uint16_t) adc->adch) << 8);
    /* return the value */
    return val;
}