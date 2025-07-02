#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer2_init(void);

uint8_t get_centesimas(void);
uint8_t get_segundos(void);
uint8_t get_minutos(void);

#endif
