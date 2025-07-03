#ifndef ADC_H
#define ADC_H

#include <stdint.h>

// Inicializa el ADC (configura referencia y prescaler)
void adc_init(void);

// Lee el valor del ADC del canal especificado (0-7)
// Devuelve un valor de 10 bits (0 a 1023)
int adc_get(char input);

#endif // ADC_H
