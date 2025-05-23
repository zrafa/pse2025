/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

 #ifndef _UTILS_H
 #define _UTILS_H
  
 void delay_ms(int ms);
 void init();
 void set_leds(unsigned char bits);
 
 int pulsed();

 #endif	/* _UTILS_H */