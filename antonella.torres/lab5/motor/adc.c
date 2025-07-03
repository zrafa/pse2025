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
        uint8_t ADCL;  
        uint8_t ADCH; 
        uint8_t ADCSRA; /* ADC Control and Status Register A */ 
        uint8_t ADCSRB; /* ADC Control and Status Register B */
        uint8_t ADMUX;

} volatile adc_t;

volatile adc_t *adc = (adc_t *)(0x78);

#define ADEN   7
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0
#define REFS0  6
#define ADSC   6  // Start Conversion



void adc_init()
{
    // Usamos AVcc como referencia (con capacitor externo en AREF)
    adc->ADMUX = (1 << REFS0);

    // Habilitamos ADC y seteamos prescaler a 128
    adc->ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
int adc_get(char input)
{
    // Seleccionamos el canal
    adc->ADMUX = (adc->ADMUX & 0xF0) | (input & 0x0F);

    // Iniciamos conversión
    adc->ADCSRA |= (1 << ADSC);

    // Esperamos a que termine
    while (adc->ADCSRA & (1 << ADSC)) {}

    // Leemos los datos (ADCL primero)
    uint8_t low = adc->ADCL;
    uint8_t high = adc->ADCH;

    return ((uint16_t)high << 8) | low;
}