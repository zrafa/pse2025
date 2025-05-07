/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

/* ultrasound_get_distance()
 * 	devuelve la distancia en cm del objeto delante del sensor
 * 	devuelve -1 si no existe ningun objeto
 */
int ultrasound_get_distance(void)
{
	* ddr_b &= ~(1 << 2); //PB2 (D10) Echo (Entrada)
	* ddr_b |= (1 << 3); //PB2 (D11) Trigger (Salida)

	int i = -1;
	int timeout;

	* puerto_b |= (1 << 3); //comienzo señal de trigger
	_delay_us(10); //mantengo la señal durante 10 microsegundos
	* puerto_b &= ~(1 << 3); //apago señal de trigger

	//comienzo a esperar echo
	while(!(* pin_b & (1 << 2))){
		_delay_us(1);
		timeout++;
		if(timeout > 30000) return -1; //no hubo respuesta
	}

	//una vez que prende empiezo a contar
	while(* pin_b & (1 << 2)){
		_delay_us(1);
		i++;
		if (i> 38000) return -1; //fuera de rango
	}
	//cerró, calculo cm y devuelvo
	i = i/58;

	return i;
}