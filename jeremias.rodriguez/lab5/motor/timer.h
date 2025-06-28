#ifndef _TIMER
#define _TIMER

void timer_init();

void set_servo_angle(uint16_t angle);
void set_motor_speed(uint8_t duty_percent);
#endif