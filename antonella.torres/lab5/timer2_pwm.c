#include "timer2_pwm.h"


volatile timer2_t* timer2 = (timer2_t*) 0xB0;


volatile uint8_t* ddrd = (uint8_t*) 0x2A; // DDRD
volatile uint8_t* ddrb = (uint8_t*) 0x24; // DDRB
volatile uint8_t* portd = (uint8_t*)0x2B;  // Dirección PORTD
void timer2_pwm_init(void) {

    *ddrd |= (1 << 3);  // PD3 salida
    *ddrb |= (1 << 3);  // PB3 salida



    // Modo Fast PWM 8-bit: WGM21 = 1, WGM20 = 1 (modo 3)
    timer2->tccr2a = (1 << 0) | (1 << 1); // WGM20 | WGM21

    // Salida no invertida en OC2A y OC2B: COM2A1 = 1, COM2B1 = 1
    timer2->tccr2a |= (1 << 7) | (1 << 5); // COM2A1 | COM2B1

    // Prescaler = 64 → CS22 = 1, CS21 = 1
    timer2->tccr2b = (1 << 2) | (1 << 1); // CS22 | CS21

    // Inicializar el duty cycle a 0
    timer2->ocr2a = 0;
    timer2->ocr2b = 0;
}

void timer2_set_duty_a(uint8_t duty) {
    timer2->ocr2a = duty;
}

void timer2_set_duty_b(uint8_t duty) {
    timer2->ocr2b = duty;
}
