/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#define TRIG 0 //va al pb0
#define ECHO 1 //va el pb1
#include <util/delay.h>
#include "makesound.h"


volatile unsigned char *port_b = (unsigned char *) 0x25;
volatile unsigned char *ddr_b  = (unsigned char *) 0x24;
volatile unsigned char *pin_b  = (unsigned char *) 0x23;

/* ultrasound_get_distance()
 * 	devuelve la distancia en cm del objeto delante del sensor
 * 	devuelve -1 si no existe ningun objeto
 */

void soundT(){
	//frecuencia de do= 261 hz -> 1/261=3.83ms(1 ciclo), medio ciclo 1.9ms 
	*ddr_b |= (1 << 2); //utilizamos el pb0 como salida
	while (1){
		
		*port_b ^= (1 << 2); 
		_delay_us(1915);	
	}

	
}

void sound (int frec, int duracion){
	*ddr_b |= (1 << 2); //utilizamos el pb0 como salida
	float medio_ciclo_us = (1000000.0 / frec) / 2.0;  // medio ciclo en microsegundos
    int ciclos = (duracion * 1000) / (2 * medio_ciclo_us);  // cuántos ciclos caben en ese tiempo

	if (frec==0) {
		_delay_us(duracion*1000);
	}

    for(int i = 0; i < ciclos*2; i++) {
        *port_b ^= (1 << 2);  // Alternar estado pin PB2
        _delay_us(medio_ciclo_us);
    }
}


 void init_ultrasound() {
    *ddr_b |= (1 << TRIG);   
    *ddr_b &= ~(1 << ECHO);  
	*port_b &= ~(1 << TRIG); // se pone en bajo antes de enviar
}
int ultrasound_get_distance(void)
{
	int i = -1;
	int duracion = 0;
	int timeout = 0;
	_delay_us(2);
	//iniciamos pulso
	*port_b |= (1 << TRIG);
	_delay_us(10);
	*port_b &= ~(1 << TRIG);


	//cuando el echo se pone en alto volvio
	while (!(*pin_b & (1 << ECHO))) {
		_delay_us(1);
		timeout++;
		if (timeout > 30000) return -1; // no se detectó nada
	}

	//por cada seg que pasa medimos 
	while (*pin_b & (1 << ECHO)) {
		_delay_us(1);
		duracion++;
		if (duracion > 38000) break; // fuera de alcance 
	}
	
	i=duracion / 58;

	/* completar con driver de ultrasonido */

	return i;
}
