#include <stdbool.h>
#include "hw.h"

void button_init()
{
    *ddr_c  &= ~BIT5;
	*port_c |=  BIT5;
}

bool button_pushed()
{
	return !(*pin_c & BIT5);
}

bool button_pulsed()
{
    static bool pressed = false;
    bool pulse = pressed && !button_pushed();
    pressed = button_pushed();
    return pulse;
}