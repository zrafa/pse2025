
#include "adc.h"
#include "serial.h"

#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>
//--------
//RECEPTOR
//--------
int main(void)
{
    volatile unsigned int i;
    /* direccion de PORTB (registro de datos) */
    volatile unsigned char * puerto_b = (unsigned char *) 0x25;

    /* direccion de DDR B (registro de control) */
    volatile unsigned char * ddr_b = (unsigned char *) 0x24;


	uint8_t val;
	serial_init();
	adc_init();
    unsigned char letra = 0x00;
    //adc_get para asignar valor por default (de laser encendido)
    int limite = 50;
	while (1) {
        
		/* obtener una conversión ADC desde el pin de entrada ADC 0 */
 		val = adc_get(ADC_CHANNEL_0);
		//serial_put_number(val);
        
		//variable char
        if (val > limite){
            _delay_ms(1);
            if (val > limite){ //es bistart
                for(int i = 0; i < 8; i++){
                    _delay_ms(7);
                    val= adc_get(ADC_CHANNEL_0);
                    if (val<limite){
                        letra = ((letra << 1)| 0b00000001);
                        //serial_put_number(1);
                    }else{
                        letra = ((letra << 1)| 0b00000000);
                        //serial_put_number(0);
                    }
                }
                _delay_ms(7);
                val= adc_get(ADC_CHANNEL_0);
                if (val>limite){
                    serial_put_char(letra);
                }
            }
            _delay_ms(13);
        }
        //PSEUDOCODIGO:
        //if val MUCHO menor a default
            //delay de 20 ms (suponiendo t = 100 ms)
            //si sigue estando abajo, lo interpreto como bitstart
                //for 8 iteraciones
                    //sleep t
                    //if adc_get BAJO
                        //guardo 0 << 1
                    //else guardo 1 << 1
                //if adc_get BAJO
                    //bit stop OK
                    //serial_put
                //else nada papi
        //sleep t

	}

	for(;;);
}
