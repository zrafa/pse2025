
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"

unsigned char knight_rider[] = 
{
	0b1000,
	0b1100,
	0b0110,
	0b0011,
	0b0001,
	0b0011,
	0b0110,
	0b1100
};

unsigned char bloom[] = 
{
	0b0101,
	0b1010
};

unsigned char trail[] = 
{
    0b1000,
    0b1100,
    0b1110,
    0b1111,
    0b0111,
    0b0011,
    0b0001,
    0b0011,
    0b0111,
    0b1111,
    0b1110,
    0b1100
};

int main(void)
{	
	init();
	unsigned char counter = 0;
	unsigned long frame = 0;
	while(not_pushed())
	{
		wait(1000);
		if(!((++frame)%50))
			set_leds((++counter)%16);
	}

	while(1);
}
/*
int main(void)	
{	
	init();
	unsigned char counter = 0;
	while (1) 
	{
		wait(1000);
		while(not_pushed());
		wait(1000);
		while(!not_pushed());
		set_leds((++counter)%16);
	}
}*/