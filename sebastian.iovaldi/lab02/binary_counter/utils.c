
/* utils.c - funciones de soporte al programa principal */

#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_c = (unsigned char *) 0x28;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_c = (unsigned char *) 0x27;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;



void wait(unsigned long frames) 
{
	volatile unsigned long i;
	for (i=0; i<frames; i++);
}

void init() 
{
	*ddr_c = 0x00;
	*puerto_c |= 32;
	*puerto_b = 0x0;
	*ddr_b |= (BIT0 | BIT1 | BIT2 | BIT3);
}

int not_pushed()
{
	return *pin_c & 32;
}
void set_leds(unsigned char bits)
{
	*puerto_b = bits;
}