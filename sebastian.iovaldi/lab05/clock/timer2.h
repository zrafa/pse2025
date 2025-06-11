#pragma once

#include <stdint.h>

void T2_Init(void(*int_handler)());
uint16_t T2_GetTicks();