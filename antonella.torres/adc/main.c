#include "adc.h"
#include "serial.h"
#include "makesound.h"
#include <util/delay.h>

#define MIN_FREQ 800
#define MAX_FREQ 2800

int main(void)
{
    adc_init();
    serial_init();
    init_ultrasound();


    while (1) {
        uint16_t val = adc_get(2);
        serial_put_number(val);

        uint8_t nivel = val / 64;  // nivel va de 0 a 15

     
        int frec = MIN_FREQ + (nivel * (MAX_FREQ - MIN_FREQ)) / 15;

      
      
		serial_put_char('F');
		serial_put_number(frec);
		sound(frec, 800);
        

        _delay_ms(200);
    }

    return 0;
}
