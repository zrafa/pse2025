#include "utils.h"

int main(void)
{	
	led_init();

	while (1)
    {
		delay_ms(1000);
		led_on();
		delay_ms(1000);
		led_off();
    }
}