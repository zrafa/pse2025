#include "utils.h"
#include "delay.h"

void main(){
    led_init();
    input_init();
    while(1){
        read();
        count();
        delay_ms(300);
    }
}

