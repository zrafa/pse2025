#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8
#define BIT4 16
#define BIT5 32

volatile unsigned char * port_b = (unsigned char *) 0x25;
volatile unsigned char * ddr_b = (unsigned char *) 0x24;
volatile unsigned char * pin_b = (unsigned char *) 0x23;

void led_init()
{
	*port_b = 0x0;
	*ddr_b |= (BIT0 | BIT1 | BIT2 | BIT3);
}

void led_on() 
{
	*port_b |= BIT0;
}

void led_off()
{
	*port_b &= ~BIT0;
}