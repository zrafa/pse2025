/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

 #define BIT5 32

 /* puertos de E/S */
 
 /* direccion de PORTB (registro de datos) */
 volatile unsigned char * puerto_b = (unsigned char *) 0x25;
 
 /* direccion de DDR B (registro de control) */
 volatile unsigned char * ddr_b = (unsigned char *) 0x24;
 
 /* direccion PIN B (registro de datos de entrada) */
 volatile unsigned char * pin_b = (unsigned char *) 0x23;
 
 void delay_ms(int n) 
 {
     volatile unsigned long i;
     volatile unsigned long j = 151ul*n;
     for (i=0; i<j; i++);
 }
 
 void led_init() 
 {
     *ddr_b |= BIT5;
 }
 
 void led_on() 
 {
     *puerto_b |= BIT5;
 }
 
 void led_off()
 {
     *puerto_b &= ~BIT5;
 }