#include <stdbool.h>

#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8
#define BIT4 16
#define BIT5 32

extern volatile unsigned char * port_b ;// = (unsigned char *) 0x25;
extern volatile unsigned char * ddr_b ;// = (unsigned char *) 0x24;
extern volatile unsigned char * pin_b ;// = (unsigned char *) 0x23;

 
/* direccion PIN B (registro de datos de entrada) */

void button_init()
{
    *ddr_b  &= ~2;
	*port_b |= 2;
}

bool button_pushed()
{
	return !(*pin_b & 2);
}

bool button_pulsed()
{
    static bool pressed = false;
    bool pulse = pressed && !button_pushed();
    pressed = button_pushed();
    return pulse;
}