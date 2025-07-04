#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "serial.h"
#include "pin_config.h"

#define SEG_IN_MILLIS 1000

volatile unsigned long int nota_do = 261;
volatile unsigned char sound_pin = 0b00010000;


volatile unsigned char * port_b = (unsigned char *) 0x25;

void config_sound();
void sound(unsigned long frec, unsigned long duracion);

int main(void)
{
	serial_init();
	volatile int size = 12, i = 0;
	config_sound();

	sound(nota_do,SEG_IN_MILLIS);/*
	while(1){
		_delay_ms(1000);
		sound(nota_do,1000);
		if(i < size){
			i++;
		}
		else{
			i = 0;
		}
	}
	*/
}

void config_sound(){
    make_output_DDRB(sound_pin);
}

/*
    frecuencia en hz
    Cuantos ciclos de señal se completan en 1 segundo
    duracion --> millisegundos
    */
void sound(unsigned long frec, unsigned long duracion){
    volatile unsigned long tiempo = duracion*1000UL;
    volatile unsigned long time_passed = 0;
    volatile unsigned long time_cicle = ((1000000UL / frec));
    const unsigned long half_time_cicle = time_cicle / 2;

    if(frec == 0){
        _delay_us(tiempo);
    }
    else{
        while(time_passed < tiempo){
            *(port_b) |= (sound_pin);
            _delay_us(half_time_cicle);
            *(port_b) &= (~sound_pin);
            _delay_us(half_time_cicle);
            time_passed += time_cicle;
        }
    }
}