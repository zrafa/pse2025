
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
	0b1100,
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
	
	while (1) 
	{
		play(knight_rider, 4, 20);
		play(bloom, 8, 20);
		play(trail, 1, 15);
		play(bloom, 8, 20);
	}
}


