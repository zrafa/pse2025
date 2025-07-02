#ifndef LASER_H
#define LASER_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define LASER_BIT 0
#define LASER_PORT PORTB
#define LASER_DDR  DDRB

#define BIT_DURATION 100
#define START_DELAY 100
#define STOP_DELAY 100

void laser_init();
void sendBit(uint8_t bit);
void sendByte(uint8_t byte);

#endif // LASER_H
