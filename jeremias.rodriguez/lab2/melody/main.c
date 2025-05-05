#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL

#include "serial.h"
#include "pin_config.h"
#include "frecuencias.h"
#include <util/delay.h>

volatile unsigned char sound_pin = 0b00010000;


int melody[] = {
    REST, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_G4,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, /**/NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_E5, /**/NOTE_FS5, NOTE_D5, NOTE_C5, NOTE_A4, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, /**/NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, /**/NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, /**/NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, /**/NOTE_G4, NOTE_D5, NOTE_CS5, NOTE_C5, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, /**/NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4,
    NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, /**/NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, /**/NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_E5, /**/NOTE_FS5, NOTE_D5, NOTE_C5, NOTE_A4, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4,
    NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, /**/NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, /**/NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, /**/NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, /**/NOTE_G4, 0, 0
  };
  
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
volatile int noteDurations[] = {
    2, 8, 8, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8,
    4, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8,
    8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/ 2, 8, 8, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8,
    8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8,
    4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/2, 4, 8
  };
void config_sound();
void sound(long int frec, long int duracion);

/**
Divido 1 segundo por la duracion de la nota. Tipo:
- redonda = 1000/2
- blanca = 1000/4
- negra = 1000/8
- corchea = 1000/16
- semicorchea = 1000/32
*/

int main(void)
{
	serial_init();
	volatile int size = sizeof(melody), i = 0;
    volatile int duration_nota, pausa_entre_notas;
	config_sound();
    for (i = 0; i < size / sizeof(melody[0]); i++) {
        duration_nota = 1000 / (noteDurations[i]);
        sound(melody[i], duration_nota);
        pausa_entre_notas = duration_nota * 1.30;
        _delay_us(pausa_entre_notas);
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
    volatile long int time_cicle = ((1.0 / frec)*1000000);
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
