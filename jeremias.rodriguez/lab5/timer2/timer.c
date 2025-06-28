#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned long time = 0;

typedef struct{
    uint8_t tccr2a;
    uint8_t tccr2b;
    uint8_t tcnt2;
    uint8_t ocr2a;
    uint8_t ocr2b;
} volatile timer2_t;

volatile timer2_t *timer2 = (timer2_t *)(0xB0);

volatile unsigned char *timer2_timsk2 = (unsigned char *)(0x70);

/**
Como se pide cada sentecima de segundo, son 100 milis
Considerando la formula
OCR2A = (F_CPU / (Prescaler × Freq)) - 1

Como el reloj es de 16mhz --> 16.000.000
16.000.000 / (1024*100) = 156.25 
*/

#define TIMER2_PRESCALER_BITS 0b00000111 // Prescaler 1024

//(SYSTEM_TICKS/PRESCALAR) //PRESCALAR O TICKS_PER_SECONDS
#define TIMER_OCR2A 155  // Calculado para 100Hz con prescaler 1024

#define TIMER2_CTC 0x02 //Modo 2 CTC


#define SYSTEM_TICKS 16000000
#define PRESCALAR 1024
#define TICKS_PER_SECOND 1000


ISR(TIMER2_COMPA_vect){
    time++;
}

void timer_init(){
    timer2->tccr2a |= TIMER2_CTC;
    timer2->tccr2b |= TIMER2_PRESCALER_BITS;
    timer2->ocr2a |= TIMER_OCR2A;

    (*timer2_timsk2) |= 0x02; //OCIE2A

    sei();
}