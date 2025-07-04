/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

 #include "serial.h"
 #include "ultrasound.h"
 
 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   8000000UL
 #include <util/delay.h>
 
int main(void)
{
    int dist_cm = 8;
    serial_init();
    ultrasound_init();

     /* Ejemplo de uso de la biblioteca serial */
         serial_put_str("HOLA MUNDO \r\n");
     
     /* un programa embebido nunca finaliza */
     for (;;) {
        dist_cm = ultrasound_get_distance();
        serial_put_int(dist_cm, 4);	/* Mostrar distancia */

        if(dist_cm < 10)
            set_leds(0b1111);
        else 
            set_leds(0b0000);

    _delay_ms(100);
    }
 }
 