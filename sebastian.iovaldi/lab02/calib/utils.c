
/* utils.c - funciones de soporte al programa principal */


#define BIT5 32

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

void esperar() 
{
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	volatile unsigned long j = 151ul*1000;
	for (i=0; i<j; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	/* COMPLETAR */
	*ddr_b |= BIT5;
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on() {
	/* COMPLETAR */
	*puerto_b |= BIT5;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off() {
	/* COMPLETAR */
	*puerto_b &= ~BIT5;
}