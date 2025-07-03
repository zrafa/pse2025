/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

 #include "serial.h"
 #include "ultrasound.h"
 
 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   16000000UL
 #include <util/delay.h>
 
 
     /* direccion de PORTB (registro de datos) */
     volatile unsigned char * puerto_b = (unsigned char *) 0x25;
 
     /* direccion de DDR B (registro de control) */
 volatile unsigned char * ddr_b = (unsigned char *) 0x24;
 
 void sound(int frec, int duracion){
 
 
     unsigned long medio_periodo = (1000000UL / frec) / 2; //El periodo es cuanto dura un ciclo (1 seg/ frec). Medio periodo, es el tiempo que el pin debe estar en alto o en bajo
     unsigned long tiempo_total = duracion * 1000UL;
     unsigned long tiempo_actual = 0;
 
     while (tiempo_actual < tiempo_total) {
         * puerto_b |= (1 << 5);
         _delay_us(medio_periodo);
         * puerto_b &= ~(1 << 5);
         _delay_us(medio_periodo);
 
         tiempo_actual += medio_periodo*2;
     }
 }
 int main(void)
 {
     int dist_cm = 8;
     *ddr_b |= (1 << 5);
 
     serial_init();
     /* un programa embebido nunca finaliza */
     for (;;) {
         serial_put_str("La distancia es de ");
 
         dist_cm = ultrasound_get_distance();
         serial_put_int(dist_cm, 4);	/* Mostrar distancia */
         serial_put_str(" cm.\r\n");
 
         sound(dist_cm*100, 500);
     }
 }