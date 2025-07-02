#ifndef TIMER2_PWM_H
#define TIMER2_PWM_H

#include <stdint.h>


typedef struct 
{
    uint8_t tccr2a;  // 0xB0
    uint8_t tccr2b;  // 0xB1
    uint8_t tcnt2;   // 0xB2
    uint8_t ocr2a;   // 0xB3
    uint8_t ocr2b;   // 0xB4
} volatile timer2_t;


extern volatile timer2_t* timer2;

void timer2_pwm_init(void);

//ciclo para el ocr2a
void timer2_set_duty_a(uint8_t duty);

//ciclo para el ocr2b
void timer2_set_duty_b(uint8_t duty);

#endif
