/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "ultrasound.h"
#include "pin_config.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

#define MILLI_IN_MICRO 1000
#define DURACION_NOTA 1
#define VARIACION_FREC 50
#define COTA_SUP 30
#define COTA_INF 1

volatile unsigned long int nota_do = 10000;
volatile unsigned char sound_pin = 0b00010000;

void config_sound();
void sound(long int frec, long int duracion);

int main(void)
{
	volatile unsigned int dist_cm = 1, new_frec = 0;
	
	config_sound();
	start_ultrasound();
	serial_init();
	/* un programa embebido nunca finaliza */
	for (;;) {
		dist_cm = 0;
		dist_cm = ultrasound_get_distance();
		if(dist_cm >= COTA_INF && dist_cm <= COTA_SUP){
			new_frec = dist_cm*VARIACION_FREC;
			sound(new_frec, DURACION_NOTA);
		}
	}
}

void config_sound(){
    make_output_DDRB(sound_pin);
}

/*
    frecuencia en hz
    Cuantos ciclos de señal se completan en 1 segundo
    duracion --> millisegundos
    */
void sound(long int frec, long int duracion){
    volatile long int tiempo = duracion*MILLI_IN_MICRO;
    volatile long int count_cicle = 0;
    volatile long int time_cicle = (1000000ul / frec);
    const long int half_time_cicle = time_cicle / 2;

    if(frec == 0){
        _delay_us(tiempo);
    }
    else{
        while(count_cicle < tiempo){
            write_signal_B(sound_pin, 1);
            _delay_us(half_time_cicle);
            write_signal_B(sound_pin, 0);
            _delay_us(half_time_cicle);
            count_cicle += time_cicle;
        }
    }
}
