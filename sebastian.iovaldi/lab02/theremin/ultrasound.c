/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   8000000UL
 #include <util/delay.h>
 
 #define BIT0 1
 #define BIT1 2
 #define BIT2 4
 #define BIT3 8
 #define BIT4 16
 #define BIT5 32
 #define BIT6 64
 
 /* direccion de PORTB (registro de datos) */
 volatile unsigned char * puerto_b = (unsigned char *) 0x25;
 
 /* direccion de DDR B (registro de control) */
 volatile unsigned char * ddr_b = (unsigned char *) 0x24;
 
 /* direccion PIN B (registro de datos de entrada) */
 volatile unsigned char * pin_b = (unsigned char *) 0x23;
 
 /* direccion de PORTB (registro de datos) */
 volatile unsigned char * puerto_c = (unsigned char *) 0x28;
 
 /* direccion de DDR B (registro de control) */
 volatile unsigned char * ddr_c = (unsigned char *) 0x27;
 
 /* direccion PIN B (registro de datos de entrada) */
 volatile unsigned char * pin_c = (unsigned char *) 0x26;
 

void ultrasound_init()
{
    *ddr_c |= BIT2;
    *ddr_c &= ~BIT3;
    *ddr_c &= ~BIT5;

    *ddr_b |= 0b1111;
    *puerto_b = 0x00;
    *puerto_c |= BIT5;
    *ddr_c |= BIT4;
}

void trigger()
{
    *puerto_c |= BIT2;
    _delay_us(10);
    *puerto_c &= ~BIT2;
}

int echo()
{
    return (*pin_c & BIT3);
}

 /* ultrasound_get_distance()
  * 	devuelve la distancia en cm del objeto delante del sensor
  * 	devuelve -1 si no existe ningun objeto
  */
 int ultrasound_get_distance(void)
 {
    int i = -1;
    trigger();
    
    while(!echo());

    while(echo() && i<=36000)
    {
        _delay_us(1);
        i++;
    }

    if(i==36000)
        return -1;


    return i/28;
 }

void set_leds(unsigned char a)
{
    *puerto_b = a;
}

void sound(int freq, int duration)
{
    unsigned period = 1000000 / freq;
    unsigned half_period = period / 2;

    unsigned long elapsed = 0;
    unsigned long duration_us = (unsigned long)duration * 1000UL; 

    while(elapsed < duration_us)
    {
        *puerto_c |= BIT4;
        _delay_us(half_period);
        *puerto_c &= ~BIT4;
        _delay_us(half_period);
        elapsed += period;
    }
}

void speak_off()
{
    *puerto_c &= ~BIT4;
}

int pushed()
{
	return !(*pin_c & BIT5);
}

int pulsed()
{
	static int pressed = 0;

	if(pressed && !pushed())
	{
		pressed = 0;
		return 1;
	}

	pressed = pushed();
	return 0;
}
