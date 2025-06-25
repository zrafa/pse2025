#include "utils.h"
#include "timer1.h"
#include "serial.h"
unsigned int dato;
ISR(TIMER1_COMPB_vect)
{
    setCompareA(dato);
}
int main(){
    timer1_init();
    serial_init();
    setCompareA(0);
    while (1){
        dato = 0;
        
    }
    while (0)
    {
        dato = serial_get_char();
    }
    
}
    
