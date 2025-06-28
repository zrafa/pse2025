#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
#include "adc.h"
#include "serial.h"
#include "pin_config.h"
#include <string.h>

volatile unsigned char pin_laser = 0b00010000;

void main()
{
	int val = 0;
	//char texto[] = "Seniora\nNo le quite anios a su vida\nPongale vida a los anios, que es mejor\nSeniora\nNo le quite anios a su vida\nPongale vida a los anios, que es mejor";
	char letra;
	adc_init();
	serial_init();
	make_output_DDRB(pin_laser);
	//pin_laser on
	
	//char letra
	while (1) {
		write_signal_B(pin_laser, 1);
		_delay_ms(5000);
		//condicion de corte
		for(;;){
			write_signal_B(pin_laser, 1);
			_delay_ms(13);
			letra = serial_get_char();
			//pin_laser off --> Bit start 
			write_signal_B(pin_laser, 0);
			//sleep t
			_delay_ms(7);

			//for 8 iteraciones
				//si letra & 0b00000001
					//pin_laser on
				//else
					//pin_laser off
				//
				//sleep t
			for(int j = 0; j < 8; j++){
				write_signal_B(pin_laser, (letra & 0b10000000));
				letra = letra << 1;
				_delay_ms(7);
			}
				
			//pin_laser off --> Bit stop
			write_signal_B(pin_laser, 0);
			//sleep t
			_delay_ms(7);
		}
		

	}

	for(;;);
}
