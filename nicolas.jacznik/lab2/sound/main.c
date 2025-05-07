#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

void sound(int frec, int duracion){
    unsigned long medio_periodo = (1000000UL / frec) / 2; //El periodo es cuanto dura un ciclo (1 seg/ frec). Medio periodo, es el tiempo que el pin debe estar en alto o en bajo
    unsigned long tiempo_total = duracion * 1000UL;
    unsigned long tiempo_actual = 0;

    while (tiempo_actual < tiempo_total) {
        * puerto_b |= (1 << 5);
        _delay_us(medio_periodo);
        * puerto_b &= ~(1 << 5);
        _delay_us(medio_periodo);

        tiempo_actual += medio_periodo*2;
    }
}

int main(void){

    *ddr_b |= (1 << 5);

    while(1){
        sound(262, 500);   // DO4 - 500ms
        _delay_ms(200);

        sound(294, 500);   // RE4
        _delay_ms(200);

        sound(330, 500);   // MI4
        _delay_ms(200);

        sound(349, 500);   // FA4
        _delay_ms(200);

        sound(392, 500);   // SOL4
        _delay_ms(200);

        sound(440, 500);   // LA4
        _delay_ms(200);

        sound(494, 500);   // SI4
        _delay_ms(200);

        sound(523, 500);   // DO5
        _delay_ms(1000);
    }

}
