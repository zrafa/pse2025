/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "makesound.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
// Notas en Hz
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392

int main(void)
{

    while (1) {
		sound(659, 400);  // E5
        _delay_ms(150);
        sound(659, 400);  // E5
        _delay_ms(150);
        sound(0, 400);    // silencio
        _delay_ms(150);
        sound(659, 400);  // E5
        _delay_ms(150);
        sound(0, 400);
        _delay_ms(150);
        sound(523, 400);  // C5
        _delay_ms(150);
        sound(659, 400);  // E5
        _delay_ms(150);
        sound(784, 600);  // G5
        _delay_ms(400);

        sound(392, 800);  // G4
        _delay_ms(600);
    }


	/*
	int dist_cm = 8;

	serial_init();

    	serial_put_str("HOLA MUNDO \r\n");
    	serial_put_int(dist_cm, 4);	
    
		for (;;) {
			serial_put_str("HOLA MUNDO \r\n");
		
			dist_cm = ultrasound_get_distance(); 
		
			if (dist_cm != -1) {
				serial_put_str("Distancia: ");        
				serial_put_int(dist_cm, 4);           
				serial_put_str(" cm\r\n");            
			} else {
				serial_put_str("No se detecta objeto.\r\n");
			}
		
			_delay_ms(1000);  
		}
		*/
}

