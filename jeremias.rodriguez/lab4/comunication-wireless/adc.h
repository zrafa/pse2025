/**********************************************************************
 *
 * Filename:    adc.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _ADC_H
#define _ADC_H

void adc_init(void);
uint8_t adc_get(uint8_t);

#endif /* _SERIAL_H */