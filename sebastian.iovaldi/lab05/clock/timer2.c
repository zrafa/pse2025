#include "timer2.h"

#include <avr/interrupt.h>

#define T2_CTC 0x2
#define T2_CS_DISABLE 0x0
#define T2_CS_PRESCALE_1 0x1
#define T2_CS_PRESCALE_8 0x2
#define T2_CS_PRESCALE_32 0x3
#define T2_CS_PRESCALE_64 0x4
#define T2_CS_PRESCALE_128 0x5
#define T2_CS_PRESCALE_256 0x6
#define T2_CS_PRESCALE_1024 0x7

#define T2_MSK_COMPARE_A 0x2
#define T2_MKS_COMPARE_B 0x4
#define T2_MKS_OVERFLOW  0x1

#define T2_PRESCALAR 256
#define T2_TICKS_PER_SECOND 100
#define TIMER2_OCR2A (F_CPU/T2_PRESCALAR/T2_TICKS_PER_SECOND)

typedef struct 
{
    uint8_t tccr2a;
    uint8_t tccr2b;
    uint8_t tcnt2;
    uint8_t ocr2a;
    uint8_t ocr2b; 

} volatile timer2_t;

volatile timer2_t *timer2 = (timer2_t*)0xB0;
volatile uint8_t* timsk2 = (uint8_t*)0x70;
volatile uint16_t T2_ticks; 

void(*interruption_handler)();

void T2_SetTop(uint8_t top)
{
    timer2->ocr2a = top;
}

void T2_SetMode_CTC()
{
    timer2->tccr2a |= T2_CTC;
    timer2->tccr2b |= T2_CS_PRESCALE_256;
    *timsk2 |= T2_MSK_COMPARE_A;
    T2_SetTop(TIMER2_OCR2A);
}

void T2_Init(void(*int_handler)())
{
    T2_ticks = 0;
    interruption_handler = int_handler;
    T2_SetMode_CTC();
    sei();
}

uint16_t T2_GetTicks()
{
    return T2_ticks;
}

ISR(TIMER2_COMPA_vect)
{
    T2_ticks++;
    /* correccion por impresicion
        TIMER2_OCR2A es 156.5 ; */
        T2_SetTop( T2_ticks%2 ? TIMER2_OCR2A : TIMER2_OCR2A+1 );   

    interruption_handler();
}

