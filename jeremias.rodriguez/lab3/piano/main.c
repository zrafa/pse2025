/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "frecuencias.h"
#include "pin_config.h"
#include <util/delay.h>

volatile unsigned long int nota_do = 2093;
volatile unsigned char sound_pin = 0b00010000;

void config_sound();
void wait(volatile long int n);
void sound(long int frec, long int duracion);


int main(void)
{
    char rcvChar = 0;
    config_sound();
    /* Configure the UART for the serial driver */
    serial_init();

    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');
    volatile int duration_nota;
    duration_nota = 1000 / (8*3);

    while (rcvChar != 'q')
    {
        /* Wait for an incoming character */
        rcvChar = serial_get_char();
        
        //sound(2093, 10);
        switch(rcvChar){
            case 'a':
                sound(NOTE_C6, duration_nota);
                break;
            case 's':
                sound(NOTE_D6, duration_nota);
                break;
            case 'd':
                sound(NOTE_E6, duration_nota);
                break;
            case 'f':
                sound(NOTE_F6, duration_nota);
                break;
            case 'g':
                sound(NOTE_G6, duration_nota);
                break;
            case 'h':
                sound(NOTE_A6, duration_nota);
                break;
            default:
                sound(NOTE_B6, duration_nota);
                break;
        }
    }

    for (;;);

    return 0;
}


void config_sound(){
    make_output_DDRB(sound_pin);
}

void wait(volatile long int n){
    volatile long int i;
    for(i = 0; i < n; i++){
        _delay_us(1);
    }
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