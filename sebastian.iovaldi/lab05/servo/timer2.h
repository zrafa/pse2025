#pragma once

#include <stdint.h>

void T2_Init(void(*int_handler)());
void T2_Init_PWM();
void T2_SetOCRB(uint8_t value);
void T2_SetPulseWidth(uint8_t value);

uint16_t T2_GetTicks();