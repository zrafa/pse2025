#include "utils.h"
#include "timer1.h"
#include "serial.h"
void setServoAngle(uint8_t angle) {
    if (angle > 180) angle = 180;
    // Calcula el OCR1A: 2000 + (angle/180)*(4000-2000)
    uint16_t ticks = 2000 + ((uint32_t)angle * 2000) / 180;
    setCompareA(ticks);
}
int main(){
    timer1_init();
    serial_init();
    unsigned volatile char i = 0;
    char c[8];
    c[0] = '<';
    c[1] = '-';
    c[2] = ' ';
    c[7] = '\r';

    unsigned int a = 2000;
    unsigned int b = 0;
    unsigned int temp;
    while (1){
        
        setCompareA(1100);
        temp = a;
        c[6] = temp % 10 + '0';
        temp /= 10;
        c[5] = temp % 10 + '0';
        temp /= 10;
        c[4] = temp % 10 + '0';
        temp /= 10;
        c[3] = temp % 10 + '0';
        serial_put_string(c,8);
        esperar(2000);
        setCompareA(4600);
        esperar(2000);
        a = a - 100;
        b = b + 100;
    }
}
    
