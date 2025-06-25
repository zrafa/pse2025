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
 uint8_t adcl;  
uint8_t adch; 
uint8_t adcsra; /* ADC Control and Status Register A */
 uint8_t adcsrb; 
uint8_t admux; /* ADC Multiplexer Selection Register */
 uint8_t reserved; 
uint8_t didr0;    
} volatile adc_t;
 /* puntero a la estructura de los registros del periferico */
 volatile adc_t *adc = (adc_t *)(0x78); /*" direccion del primer registro */



void adc_init()
{       

        //01 Avcc external capacitor
        adc->admux = 0b01000000;
        // Primer bit encender adc
        // Ultimos 3 bits preescalar, factor de divisior 128
        adc->adcsra = adc->adcsra | 0b10000111;
        /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
        de vcc con capacitor externo y encender (habilitar) el periferico */

        /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
}

uint8_t adc_get(volatile char input)
{
        //Adlar modo 8 bits
        adc->admux = (adc->admux | 0b00100000) | (input);

        /* 2. Write this bit to one to start each conversion */
        adc->adcsra = adc->adcsra | 0b01000000;
        while (adc->adcsra & 0b01000000)
        {
                /* code */
        }
        
        /* 3. When conversion is complete, it returns to zero */

        /* 4. When conversion is complete, read the data register */
        /* IMPORTANT: ADCL must be read first, then ADCH */
        uint8_t low = adc->adcl;
        uint8_t high = adc->adch;
        return high;
	/* return the value */
}
