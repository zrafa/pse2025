#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"
#include "frecuencias.h"


volatile unsigned char sound_pin = 0b00010000;

void config_sound();
void wait(volatile long int n);
void sound(long int frec, long int duracion);

void main()
{
	volatile uint16_t val, len;
	volatile uint32_t extra;
	volatile int duration_nota;
	duration_nota = 1000 / (8*3);

	config_sound();
	adc_init();
	serial_init();
	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 0 */
		val = adc_get(3);
		/* realizar alguna acción con val */
		extra = ((uint32_t)val * 10000) / 1023;
		serial_put_int(extra, 10);
		serial_put_char('\r');
    	serial_put_char('\n');
		sound(NOTE_C6+extra, duration_nota);

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
	volatile long int tiempo = duracion*1000;
	volatile long int count_cicle = 0;
	volatile long int time_cicle = ((1000000ul / frec));
	const long int half_time_cicle = time_cicle / 2;

	if(frec == 0){
		wait(tiempo);
	}
	else{
		while(count_cicle < tiempo){
			write_signal_B(sound_pin, 1);
			wait(half_time_cicle);
			write_signal_B(sound_pin, 0);
			wait(half_time_cicle);
			count_cicle += time_cicle;
		}
	}
}
