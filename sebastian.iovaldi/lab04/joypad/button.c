#include <stdbool.h>
 
/* direccion de PORTB (registro de datos) */
volatile unsigned char * port_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

 
/* direccion PIN B (registro de datos de entrada) */

void button_init()
{
    *ddr_b  &= ~1;
	*port_b |= 1;
}

bool button_pushed()
{
	return !(*pin_b & 1);
}

bool button_pulsed()
{
    static bool pressed = false;
    bool pulse = pressed && !button_pushed();
    pressed = button_pushed();
    return pulse;
}