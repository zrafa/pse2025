#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL

#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint8_t out_min, uint8_t out_max) {
    if (x < in_min) x = in_min;
    if (x > in_max) x = in_max;
    return (uint16_t)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int main(void)
{
    uint16_t val = 0, len = 4, min, max;

    adc_init();
    serial_init();

    while (1) {
        val = adc_get(3);  // Leer ADC canal 0

        serial_put_int(val, len);
        serial_put_char('\r');
        serial_put_char('\n');

        _delay_ms(200);  // Pequeña pausa entre lecturas
    }

    return 0; // Nunca se llega, pero es correcto ponerlo
}
