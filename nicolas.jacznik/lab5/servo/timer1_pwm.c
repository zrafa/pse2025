#include "timer1_pwm.h"

void timer1_pwm_init(uint16_t top) {
    // Establecer PB1 (OC1A) como salida
    DDRB |= (1 << PB1);

    // Modo 14: Fast PWM con ICR1 como TOP
    TCCR1A = (1 << COM1A1) | (1 << WGM11);  // Clear on match
    TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11);  // Prescaler = 8

    ICR1 = top;  // Establecer TOP para controlar la frecuencia
    OCR1A = top / 2;  // Inicializar a posición media del servo
}

void timer1_pwm_set_duty(uint16_t duty) {
    OCR1A = duty;
}
