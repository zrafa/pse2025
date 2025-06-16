/**********************************************************************
 *
 * Filename:    adc.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/
 #include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */

#ifndef _ADC_H
#define _ADC_H

/* === Configuración de ADMUX === */

/* Referencia de voltaje */
#define ADC_REF_AREF         0x00  // AREF, pin externo
#define ADC_REF_AVCC         0x40  // AVcc con capacitor en AREF (REFS0=1)
#define ADC_REF_INTERNAL     0xC0  // Referencia interna 1.1V (REFS1=1, REFS0=1)

/* Canal analógico (A0 a A7) */
#define ADC_CHANNEL_0        0x00
#define ADC_CHANNEL_1        0x01
#define ADC_CHANNEL_2        0x02
#define ADC_CHANNEL_3        0x03
#define ADC_CHANNEL_4        0x04
#define ADC_CHANNEL_5        0x05
#define ADC_CHANNEL_6        0x06
#define ADC_CHANNEL_7        0x07

/* Alineación del resultado */
#define ADC_ALIGN_RIGHT      0x00
#define ADC_ALIGN_LEFT       0x20  // ADLAR = 1


/* === Configuración de ADCSRA === */

/* === Control del ADC (ADCSRA) === */
#define ADC_ENABLE           0x80  // ADEN
#define ADC_START_CONVERSION 0x40  // ADSC
#define ADC_CONVERSION_BUSY  0x40  // ADSC sigue en 1 mientras convierte

/* Prescaler (divisor de reloj del ADC) */
#define ADC_PRESCALER_2      0x01
#define ADC_PRESCALER_4      0x02
#define ADC_PRESCALER_8      0x03
#define ADC_PRESCALER_16     0x04
#define ADC_PRESCALER_32     0x05
#define ADC_PRESCALER_64     0x06
#define ADC_PRESCALER_128    0x07 //yo uso solo este

void adc_init(void);
uint8_t adc_get(char);

#endif /* _SERIAL_H */