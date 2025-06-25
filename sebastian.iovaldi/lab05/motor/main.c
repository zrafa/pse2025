#include "timer2.h"
#include "adc.h"
#include <util/delay.h>

int main()
{
    T2_Init_PWM();
    ADC_Init();
    T2_SetOCRA(255);
    
    while(1)
    {
        _delay_ms(20);
        uint8_t value = ADC_Get(1);
        T2_SetOCRB(value);
    }

    return 0;
}