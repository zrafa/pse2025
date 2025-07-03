/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "ultrasound.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>



int main(void){
    init_ultrasound();

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
}

