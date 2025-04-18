
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
/*00 todos apagados, 22 pb5 y d9 prendido, 11 d9 y d10 prendidos*/
volatile unsigned char states []= {0x00, 0x22, 0x06, 0x0C,0x08,0x00};

extern const volatile int  SIZE =  sizeof(states) / sizeof(states[0]);
volatile unsigned char set=0x2E; //todos los pines a utilizar como salida 

void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<5000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	// se configura los bits del puerto b a utilizar como salida  y apagamos x las dudas q haya alguno prendido
		*ddr_b |=set;
		*puerto_b &= ~(0x2E);
}

void leds_on(unsigned char i) {
	*puerto_b &= ~(0x2E);
	*puerto_b |= states[i];    

}
