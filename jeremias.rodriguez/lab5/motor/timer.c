
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pin_config.h"

//extern volatile unsigned long ticks = 0;


typedef struct
{
    uint8_t tccr1a;
    uint8_t tccr1b;
    uint8_t tccr1c;
    uint8_t reserved;
    uint16_t tcnt1;
    uint16_t icr1;
    uint16_t ocr1a;
    uint16_t ocr1b;
    
}volatile timer1_t;

volatile timer1_t *timer1 = (timer1_t*) 0x80;

volatile unsigned char *timer1_timsk1 = (unsigned char *) (0x6F);

#define SYSTEM_TICKS 16000000
#define PRESCALAR 8
#define TICKS_PER_SECOND 1000

void timer_init(void)
{ 
    //Seteo fast PWM
    timer1->tccr1b |= (1 << 4) | (1 << 3);
    timer1->tccr1a |= (1 << 1);
    
    timer1->tccr1b |= (1 << 1); //CS11
    
    timer1->tccr1a |= (1 << 7); //COM1A1
    
    timer1->icr1 = 39999; //0 a 39999 : 40000

    make_output_DDRB(0b00000010);
} 


void servo_angulo(int ang){
    timer1->ocr1a = (uint16_t) ang;
}

void set_motor_speed(uint8_t duty_percent) {
    timer1->ocr1a = duty_percent;
}
