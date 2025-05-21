#include <stdbool.h>
#include <util/delay.h>

void serial_init();
void serial_put_char (uint8_t c);
char serial_get_char(void);
void button_init();
bool button_pulsed();

void ultrasound_init();
uint8_t ultrasound_get_distance(void);

int main(void)
{
    char rcvChar = 0;

    serial_init();
    button_init();
    ultrasound_init();

    while(1)
    {
      uint8_t distance = ultrasound_get_distance();
      uint8_t out = distance | (button_pulsed() << 7);
      serial_put_char(out);

      _delay_ms(100);
    }

    return 0;
 }