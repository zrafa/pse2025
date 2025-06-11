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


#define REFS0 0x40
#define REFS1 0x80
#define ADEN  0x80
#define ADSC  0x40

typedef struct
{
    uint8_t low;               /* ADC Data Register Low */
    uint8_t high;
    uint8_t sra;
    uint8_t srb;
    uint8_t mux;
    uint8_t reserved;
    uint8_t dir0;
    uint8_t dir1;

} volatile adc_t;
 
 volatile adc_t *adc = (adc_t *)0x78; /* direccion del primer registro */
 
 void adc_init()
 {
    /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
    de vcc con capacitor externo y encender (habilitar) el periferico */

    adc->mux |= REFS0;
    adc->mux &= ~REFS1;   /* external  */
    adc->mux &= ~0b1111; /* adc0 */

    adc->mux |= 0b100000;

    adc->sra |=  ADEN;
    adc->sra |=  0b101;
    adc->sra &= ~0b010;

    /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
}
 
uint8_t adc_get(char input)
{
    /* 1. Selects which analog input is connected to the ADC */

    /* 2. Write this bit to one to start each conversion */

    adc->sra |= ADSC;

    /* 3. When conversion is complete, it returns to zero */

    while(adc->sra & ADSC);

    /* 4. When conversion is complete, read the data register */
    /* IMPORTANT: ADCL must be read first, then ADCH */
    uint8_t value = adc->high;
    /* return the value */
    return value;
}
 