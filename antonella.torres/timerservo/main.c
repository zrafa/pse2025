#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "timer1_pwm.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

#include "serial.h"

int main(void) {
    adc_init();
    timer1_pwm_init(39999);             // PWM a 50 Hz (TOP = 39999)
    serial_init();

    while (1) {
        uint8_t valor_adc = adc_get(ADC_CHANNEL_0);  // Leer valor de potenciómetro (0–255)

        //(entre 700 y 2800 ticks, esto es para mi servo)
        uint16_t duty = 700 + ((uint32_t)valor_adc * 2800) / 255;  // 700 + 2800 = 3500


        timer1_pwm_set_duty(duty);  // Actualizar PWM

        // Mostrar por UART
        serial_put_string("ADC: ");
        serial_put_number(valor_adc);
        serial_put_string(" | PWM: ");
        serial_put_number(duty);
        serial_put_char('\r');
        _delay_ms(50);
    }
}