/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   16000000UL
#include <util/delay.h>



int main(void)
{
    volatile unsigned int i;
    /* direccion de PORTB (registro de datos) */
    volatile unsigned char * puerto_b = (unsigned char *) 0x25;

    /* direccion de DDR B (registro de control) */
    volatile unsigned char * ddr_b = (unsigned char *) 0x24;

    /* direccion PIN B (registro de datos de entrada) */
    volatile unsigned char * pin_b = (unsigned char *) 0x23;

    *ddr_b |= (1 << 5);

    *ddr_b &= ~(1 << 4); //pin d12 como entrada
    *puerto_b |= (1 << 4); //Activo pull-up interno en PB4

    *ddr_b &= ~(1 << 3); //pin d11 como entrada
    *puerto_b |= (1 << 3); //Activo pull-up interno en PB3

    *ddr_b &= ~(1 << 2); //pin d10 como entrada
    *puerto_b |= (1 << 2); //Activo pull-up interno en PB2

    /* Configure the UART for the serial driver */
    serial_init();

    //serial_put_char('s');
    int alreadyPressed = 0;
    volatile unsigned int count = 0;
    while(1){
        /*
        //LOGICA PARA IMITAR COMPORTAMIENTO DEL TECLADO
        if(!(*pin_b & (1 << 4))){ //leer el estado del pin
            if(!alreadyPressed){
                for (i=0; i<45000; i++);        // Esperar el switch bounce
                if (!(*pin_b & (1 << 4))) {     // Confirmar que sigue presionado
                    serial_put_char('a');
                }
                alreadyPressed = 1; 
            }else{
                if(count <= 100){
                    _delay_us(5000);
                    count++;
                }else{
                    while (!(*pin_b & (1 << 4))){
                        serial_put_char('a');
                        _delay_us(40000);
                    }
                    count=0;
                    alreadyPressed = 0;
                }
            }   
        }else{
            count=0;
            alreadyPressed = 0;
        }
        */

        if(!(*pin_b & (1 << 4))){ //leer el estado del pin
            for (i=0; i<45000; i++);        // Esperar el switch bounce
            if (!(*pin_b & (1 << 4))) {     // Confirmar que sigue presionado
                serial_put_char('a');
                while (!(*pin_b & (1 << 4))){
                    serial_put_char('a');
                    //_delay_us(40000);
                } // Esperar a que se suelte el botón
            }     
        }
        if(!(*pin_b & (1 << 3))){ //leer el estado del pin
            for (i=0; i<45000; i++);        // Esperar el switch bounce
            if (!(*pin_b & (1 << 3))) {     // Confirmar que sigue presionado
                serial_put_char('s');
                while (!(*pin_b & (1 << 3))){
                    serial_put_char('s');
                    //_delay_us(40000);
                } // Esperar a que se suelte el botón // Esperar a que se suelte el botón
            }     
        }
        if(!(*pin_b & (1 << 2))){ //leer el estado del pin
            for (i=0; i<45000; i++);        // Esperar el switch bounce
            if (!(*pin_b & (1 << 2))) {     // Confirmar que sigue presionado
                serial_put_char('d');
                while (!(*pin_b & (1 << 2))){
                    serial_put_char('d');
                    //_delay_us(40000);
                } // Esperar a que se suelte el botón // Esperar a que se suelte el botón
            }     
        }
    }

    for (;;);
    
    return 0;
}

