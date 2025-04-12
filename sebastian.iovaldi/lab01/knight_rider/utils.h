
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H

#define play(animation, times, speed) play_animation(animation, sizeof(animation)/sizeof(unsigned char), times, speed)

void wait(unsigned long frames);
void init();
void set_leds(unsigned char bits);
void play_animation(unsigned char* animation, int size, int times, int speed);


#endif	/* _UTILS_H */
