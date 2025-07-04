#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL

#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"

#define ANALOG_CHANNEL 3

int main(void)
{
    uint16_t val = 0, len = 4;

    adc_init();
    serial_init();

    while (1) {
        val = adc_get(ANALOG_CHANNEL);

        serial_put_int(val, len);
        serial_put_char('\r');
        serial_put_char('\n');

        _delay_ms(200);
    }

    return 0;
}
