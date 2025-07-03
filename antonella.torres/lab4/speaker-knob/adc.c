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
        uint8_t adcl;                   /* ADC Data Register Low */
	uint8_t adch;                   /* ADC Data Register High*/
        uint8_t adcsra;                 /* ADC Control and Status Register A*/
        uint8_t adcsrb;                 /* */
        uint8_t admux;                  /* ADC Multiplexer Selection Register*/
        uint8_t reserved;               /* */
        uint8_t didr0;                  /* */

} volatile adc_t;

volatile adc_t *adc = (adc_t *) (0x78); /* direccion del primer registro */


void adc_init()
{
        /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
        de vcc con capacitor externo y encender (habilitar) el periferico */
        adc->admux = ADC_REF_AVCC | ADC_ALIGN_LEFT | ADC_CHANNEL_0;
        /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
        adc->adcsra = ADC_ENABLE | ADC_PRESCALER_128;
}

uint8_t adc_get(char input)
{
    /* 1. Selecciona el canal de entrada manteniendo la referencia y alineación */
    adc->admux = (adc->admux & 0xF0) | (input & 0x0F);  // Mantener REFS y ADLAR, cambiar MUX
    /* 2. Iniciar la conversión (ADSC = 1) */
    adc->adcsra |= ADC_START_CONVERSION;  // ADSC
    /* 3. Esperar a que la conversión termine (ADSC vuelve a 0) */
    while (adc->adcsra & ADC_CONVERSION_BUSY);
    /* 4. Leer el resultado (ADCL primero, luego ADCH) */
    uint8_t low = adc->adcl;
    uint8_t high = adc->adch;
    /* 5. Combinar y retornar los 10 bits */
    //return (high << 8) | low; //castear a uint16_t
    return adc->adch;
}