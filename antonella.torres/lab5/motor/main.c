
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"                                                                                                                                                                                                                                                                                                            

#include "serial.h"
#include <avr/io.h>
#include "adc.h"
#include "timer2_pwm.h"


void timer2_pwm_init(void);
uint8_t map_adc_to_pwm(uint16_t adc_value);

uint8_t map_adc_to_pwm(uint16_t adc_value) {
    if (adc_value > 1023) adc_value = 1023;
    return (adc_value * 255UL) / 1023;
}




int main(void) {

    adc_init();
    timer2_pwm_init();
    serial_init();

    

    while (1) {
        uint16_t adc_value = adc_get(2);
        
        
        serial_put_number(adc_value); 
 

        uint8_t pwm_value = map_adc_to_pwm(adc_value);

      
        serial_put_number(pwm_value); 

        timer2_set_duty_a(pwm_value);
        timer2_set_duty_b(pwm_value);

        _delay_ms(100);
    }
}


