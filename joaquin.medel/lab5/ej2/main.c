#include "utils.h"
#include "timer1.h"
#include "serial.h"
#include <stdint.h>
#include <adc.h>

int transformar(uint8_t valor) {
    return 1100 + ((valor * (4600 - 1100)) / 255);
    //1100 valor minimo 4600 valor maximo
}

int main(){
    timer1_init();
    serial_init();
    ADC_Init();
    

    while (1){
        set(transformar(ADC_Get()));
    }
}
    
