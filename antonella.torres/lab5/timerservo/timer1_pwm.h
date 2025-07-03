#ifndef TIMER1_PWM_H
#define TIMER1_PWM_H

#include <avr/io.h>

/**
 * Inicializa el Timer1 en modo Fast PWM (modo 14),
 * con frecuencia configurada mediante el parámetro 'top'.
 * 
 * @param top Valor para ICR1 que define el período del PWM.
 */
void timer1_pwm_init(uint16_t top);

/**
 * Establece el ciclo de trabajo para el canal OC1A (PB1).
 * 
 * @param duty Ciclo de trabajo (valor de OCR1A).
 */
void timer1_pwm_set_duty(uint16_t duty);

#endif
