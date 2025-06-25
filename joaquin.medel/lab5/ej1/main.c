#include "timer1.h"
#include "utils.h"
#include <avr/interrupt.h>
#include "serial.h"
#include "speaker_driver.h"
int unsigned volatile centesimas;
int unsigned volatile segundos;
int unsigned volatile minutos;
#define ms 12
ISR(TIMER1_COMPA_vect)
{
    centesimas += 1;
    
    if (centesimas >= 100) {
        centesimas = 0;
        segundos += 1;
    }
    
    if (segundos >= 60) {
        segundos = 0;
        minutos += 1;
    }
}
int main()
{
    centesimas  = 0;
    minutos = 0;
    segundos = 0;
    led_init();
    timer1_init();
    serial_init();
    sound_init();
    char str[9];
    while (1)
    {
        str[0] = '\r'; 
        str[1] = minutos / 10 + '0'; 
        str[2] = minutos % 10 + '0'; 
        str[3] = ':'; 
        str[4] = segundos / 10 + '0'; 
        str[5] = segundos % 10 + '0'; 
        str[6] = ':';   
        str[7] = centesimas / 10 + '0'; 
        str[8] = centesimas % 10 + '0'; 
        serial_put_string(str,9);
    }

    return 0;
}