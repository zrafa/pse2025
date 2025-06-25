
#include "adc.h"
#include "serial.h"
#include "utils.h"
#include "speaker_driver.h"
#include <stdint.h>
void reproducir_nota(uint8_t val)
{
	volatile uint8_t rango = val / 4;

	switch (rango)
	{
	case 0:
		sound(DO2, 200);
		break;
	case 1:
		sound(DOs2, 200);
		break;
	case 2:
		sound(RE2, 200);
		break;
	case 3:
		sound(REs2, 200);
		break;
	case 4:
		sound(MI2, 200);
		break;
	case 5:
		sound(FA2, 200);
		break;
	case 6:
		sound(FAs2, 200);
		break;
	case 7:
		sound(SOL2, 200);
		break;
	case 8:
		sound(SOLs2, 200);
		break;
	case 9:
		sound(LA2, 200);
		break;
	case 10:
		sound(LAs2, 200);
		break;
	case 11:
		sound(SI2, 200);
		break;

	case 12:
		sound(DO3, 200);
		break;
	case 13:
		sound(DOs3, 200);
		break;
	case 14:
		sound(RE3, 200);
		break;
	case 15:
		sound(REs3, 200);
		break;
	case 16:
		sound(MI3, 200);
		break;
	case 17:
		sound(FA3, 200);
		break;
	case 18:
		sound(FAs3, 200);
		break;
	case 19:
		sound(SOL3, 200);
		break;
	case 20:
		sound(SOLs3, 200);
		break;
	case 21:
		sound(LA3, 200);
		break;
	case 22:
		sound(LAs3, 200);
		break;
	case 23:
		sound(SI3, 200);
		break;

	case 24:
		sound(DO4, 200);
		break;
	case 25:
		sound(DOs4, 200);
		break;
	case 26:
		sound(RE4, 200);
		break;
	case 27:
		sound(REs4, 200);
		break;
	case 28:
		sound(MI4, 200);
		break;
	case 29:
		sound(FA4, 200);
		break;
	case 30:
		sound(FAs4, 200);
		break;
	case 31:
		sound(SOL4, 200);
		break;
	case 32:
		sound(SOLs4, 200);
		break;
	case 33:
		sound(LA4, 200);
		break;
	case 34:
		sound(LAs4, 200);
		break;
	case 35:
		sound(SI4, 200);
		break;

	case 36:
		sound(DO5, 200);
		break;
	case 37:
		sound(DOs5, 200);
		break;
	case 38:
		sound(RE5, 200);
		break;
	case 39:
		sound(REs5, 200);
		break;
	case 40:
		sound(MI5, 200);
		break;
	case 41:
		sound(FA5, 200);
		break;
	case 42:
		sound(FAs5, 200);
		break;
	case 43:
		sound(SOL5, 200);
		break;
	case 44:
		sound(SOLs5, 200);
		break;
	case 45:
		sound(LA5, 200);
		break;
	case 46:
		sound(LAs5, 200);
		break;
	case 47:
		sound(SI5, 200);
		break;

	case 48:
		sound(DO6, 200);
		break;
	case 49:
		sound(DOs6, 200);
		break;
	case 50:
		sound(RE6, 200);
		break;
	case 51:
		sound(REs6, 200);
		break;
	case 52:
		sound(MI6, 200);
		break;
	case 53:
		sound(FA6, 200);
		break;
	case 54:
		sound(FAs6, 200);
		break;
	case 55:
		sound(SOL6, 200);
		break;
	case 56:
		sound(SOLs6, 200);
		break;
	case 57:
		sound(LA6, 200);
		break;
	case 58:
		sound(LAs6, 200);
		break;
	case 59:
		sound(SI6, 200);
		break;

	default:
		sound(DO7, 200);
		break; // Valores fuera de rango (60+)
	}}
	main()
	{
		int val = 'a';

		adc_init();
		serial_init();
		sound_init();
		serial_put_char('s');
		serial_put_char('t');
		serial_put_char('a');
		serial_put_char('r');
		serial_put_char('t');
		serial_put_char('\r');
		serial_put_char('\n');

		while (1)
		{
			/* obtener una conversión ADC desde el pin de entrada ADC 2 */
			val = adc_get(3);
			/* realizar alguna acción con val */
			reproducir_nota(val);

			esperar(500);
		}

		for (;;)
			;
	};

