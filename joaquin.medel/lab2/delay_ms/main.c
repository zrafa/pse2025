

#include "utils.h"

int main(void)
{
    led_init();
    led_on();
    while (1)
    {
        esperar(1000);
        led_on();

        esperar(1000);
        led_off();
    }
}
