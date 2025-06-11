#pragma once

#include <stdint.h>

void serial_init();
void serial_put_char (uint8_t c);
char serial_get_char(void);

