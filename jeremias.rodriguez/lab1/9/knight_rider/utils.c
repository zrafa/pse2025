
/* utils.c - funciones de soporte al programa principal */

//volatile unsigned char states[2] = {0x3C, 0x00};
/*
0000 0000 --> 00
0010 0000 --> 20
0011 0000 --> 30
0001 1000 --> 18
0000 1100 --> 0C
0000 0100 --> 04
*/

volatile unsigned char restart = (0x3C);
volatile unsigned char states[] = {0x00, 0x20, 0x30,
								   0x18, 0x0C, 0x04,
								   0x00};

extern const volatile int SIZE = sizeof(states);
/* direccion de PORTB (registro de datos) */
volatile unsigned char *puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char *ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char *pin_b = (unsigned char *) 0x23;


void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<45000; i++);
}

/* led_init: configura el puerto b los bits 0-4 como salida */
void leds_init() {
	*(puerto_b) = *(puerto_b) & (~restart); //apago la señal del pin 5 puerto_b
	*(ddr_b) = *(ddr_b) | (restart);
}

/* update: actualiza el puerto b valor de los bits 0-4 */
void update(unsigned char i) {
	*(puerto_b) = *(puerto_b) & (~restart);
	*(puerto_b) = *(puerto_b) | (states[i]);
}
