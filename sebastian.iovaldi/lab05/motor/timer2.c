#include "timer2.h"

#include <avr/interrupt.h>
#include <math.h>

#define BIT03 0x08

#define T2_CTC 0x02
#define T2_CS_DISABLE 0x0
#define T2_CS_PRESCALE_1 0x1
#define T2_CS_PRESCALE_8 0x2
#define T2_CS_PRESCALE_32 0x3
#define T2_CS_PRESCALE_64 0x4
#define T2_CS_PRESCALE_128 0x5
#define T2_CS_PRESCALE_256 0x6
#define T2_CS_PRESCALE_1024 0x7

#define T2_FastPWM_OutputB_NonInvert 0x20
#define T2_FastPWM 0x3
#define T2_FastPWM_OCRxSet 0x8

#define T2_MSK_COMPARE_A 0x2
#define T2_MKS_COMPARE_B 0x4
#define T2_MKS_OVERFLOW  0x1

#define T2_PRESCALAR 256
#define T2_TICKS_PER_SECOND 100
#define T2_SERVO_HZ 50
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

volatile uint8_t* ddr_d = (uint8_t*) 0x2A;

void(*interruption_handler)();

void T2_SetOCRA(uint8_t value)
{
    timer2->ocr2a = value;
}

void T2_SetOCRB(uint8_t value)
{
    timer2->ocr2b = value;
}

void T2_SetMode_CTC()
{
    timer2->tccr2a |= T2_CTC;
    timer2->tccr2b |= T2_CS_PRESCALE_256;
    *timsk2 |= T2_MSK_COMPARE_A;
    T2_SetOCRA(TIMER2_OCR2A);
}

void T2_Init(void(*int_handler)())
{
    T2_ticks = 0;
    interruption_handler = int_handler;
    T2_SetMode_CTC();
    sei();
}

#define SERVO_PERIOD_HZ 50
#define T2_PULSE_PERIOD (F_CPU/1024/SERVO_PERIOD_HZ)                            /* 78 ticks */
#define T2_MIN_WIDTH_PULSE (T2_PULSE_PERIOD*600)/(1000000/SERVO_PERIOD_HZ)      /* 2 ticks */
#define T2_MAX_WIDTH_PULSE ((T2_PULSE_PERIOD*2400)/(1000000/SERVO_PERIOD_HZ))   /* 9 ticks */

void T2_Init_PWM()
{
    timer2->tccr2a |= T2_FastPWM;
    timer2->tccr2a |= T2_FastPWM_OutputB_NonInvert;
    timer2->tccr2b |= T2_FastPWM_OCRxSet;
    timer2->tccr2b |= T2_CS_PRESCALE_256;

    *ddr_d |= BIT03; /* PD3 como salida pwm */   

    T2_SetOCRA(255);
    T2_SetOCRB(0);
}

void T2_SetPulseWidth(uint8_t value)
{
    uint16_t pulse_range = T2_MAX_WIDTH_PULSE - T2_MIN_WIDTH_PULSE;
    uint16_t pulse = T2_MIN_WIDTH_PULSE + ((uint16_t)value * pulse_range) / 255;
    T2_SetOCRB((uint8_t)pulse);
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
        T2_SetOCRA( T2_ticks%2 ? TIMER2_OCR2A : TIMER2_OCR2A+1 );   

    interruption_handler();
}

