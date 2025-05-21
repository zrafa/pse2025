#include <stdbool.h>
#include <stdint.h>

void render_init();
void render_update(uint8_t keys);
void render_close();
bool input_update(uint8_t* keys);

void serial_init();
void serial_send(uint8_t keys);
void serial_close();

int main(int argc, char** argv)
{
    uint8_t keys = 0;
    uint8_t prev = keys;

    render_init();
    serial_init();

    while(input_update(&keys))
    {
        render_update(keys);
        if(prev!=keys)
            serial_send(prev = keys);
    }

    serial_close();
    render_close();

    return 0;
}