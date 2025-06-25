#ifndef _TIMER1_H
#define _TIMER1_H
#define USART_BAUDRATE 9600
#include <stdint.h>
void setCompareA(uint16_t a);
void timer1_init();

#endif /* _TIMER1_H */