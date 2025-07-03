#include <avr/io.h>
#include <util/delay.h>   // Para _delay_ms
#include "timer.h"
#include "serial.h"

#include <stdio.h>  // para sprintf

void enviar_tiempo_uart(void) {
    uint8_t min = get_minutos();
    uint8_t seg = get_segundos();
    uint8_t cen = get_centesimas();

    char buffer[10];
    sprintf(buffer, "%02d:%02d:%02d\r\n", min, seg, cen);
    serial_put_escape_sequence(buffer);
}


int main(void) {
    serial_init();
    timer2_init();

    while (1) {
        enviar_tiempo_uart();
       _delay_ms(1000);  // envía el tiempo cada 500 ms
    }

    return 0;
}
