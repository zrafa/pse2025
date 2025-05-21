/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   4000000UL
#include <util/delay.h>
 
#include "hw.h"
 
void ultrasound_init()
{
    *ddr_c |= BIT2;
    *ddr_c &= ~BIT3;
}

void trigger()
{
    *port_c |= BIT2;
    _delay_us(10);
    *port_c &= ~BIT2;

   // *ddr_c |= BIT3;
}

int echo()
{
    return (*pin_c & BIT3);
}

 /* ultrasound_get_distance()
  * 	devuelve la distancia en cm del objeto delante del sensor
  * 	devuelve -1 si no existe ningun objeto
  */

 uint8_t ultrasound_get_distance(void)  /* [0, 127] cm*/
 {
    int i = 0;
    trigger();
    while(!echo());

    while(echo() && i<=38000)
    {
        _delay_us(1);
        i++;
    }

    if(i==38000)
        return 127;

    unsigned distance = i*4/58;

    return distance > 127 ? 127 : distance;
 }