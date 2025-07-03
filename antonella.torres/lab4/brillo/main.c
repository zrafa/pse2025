#include "adc.h"
#include "serial.h"
#include <util/delay.h>

/* Direcciones registros PORTB */
volatile unsigned char * port_b = (unsigned char *) 0x25;  // PORTB
volatile unsigned char * ddr_b  = (unsigned char *) 0x24;  // DDRB
volatile unsigned char * pin_b  = (unsigned char *) 0x23;  // PINB

void init() {
    adc_init();
    serial_init();

    // Configurar PB0 (D8) como entrada con pull-up para pulsador
    *ddr_b &= ~(1 << 0);    // entrada
    *port_b |= (1 << 0);    // pull-up interno activado
}

void esperar(unsigned int ms) {
    volatile unsigned long i;
    for (i=0; i<450*ms; i++);
}

int main() {
    init();

    while (1) {
        // Leer ADC canal 2
        uint16_t val = adc_get(2);

        // Enviar valor ADC por serial
        serial_put_number(val);
        serial_put_char('\n');

        // Leer estado del pulsador en PB0
        if ((*pin_b & (1 << 0)) == 0) {  // Pulsador presionado
            esperar(50);  // debounce
            while ((*pin_b & (1 << 0)) == 0);  // espera a que se suelte
            esperar(50);
            serial_put_char('B');  // Enviar 'B' por serial
            serial_put_char('\n');
        }

        _delay_ms(100);
    }
}

/*
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
*/