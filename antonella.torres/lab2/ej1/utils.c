
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar(unsigned int ms) {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450*ms; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	/* COMPLETAR */

		*ddr_b |= (1 << 5);

}

void led_on() {
	*puerto_b |= (1 << 5);  // Pone PB5 en alto (LED encendido)
}
void led_off() {
	*puerto_b &= ~(1 << 5); // Pone PB5 en bajo (LED apagado)
}