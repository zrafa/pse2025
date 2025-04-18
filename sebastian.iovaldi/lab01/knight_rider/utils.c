
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

void wait(unsigned long frames) 
{
	volatile unsigned long i;
	for (i=0; i<frames; i++);
}

void init() 
{
	*ddr_b |= (BIT0 | BIT1 | BIT2 | BIT3);
}

void set_leds(unsigned char bits)
{
	*puerto_b = bits;
}

void play_animation(unsigned char* animation, int size, int times, int speed)
{
	while(times--)
	{
		for(int index=0; index<size; index++)
		{
			set_leds(animation[index]);
			wait(450000/speed);
		}
	}
}
