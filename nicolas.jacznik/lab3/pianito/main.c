/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "sound.h"




int main(void)
{

    /* direccion de DDR B (registro de control) */
    volatile unsigned char * ddr_b = (unsigned char *) 0x24;

    /* direccion PIN B (registro de datos de entrada) */
    volatile unsigned char * pin_b = (unsigned char *) 0x23;

    *ddr_b |= (1 << 5);
    char rcvChar = 0;
    int tiempo = 500;
    /* Configure the UART for the serial driver */
    serial_init();

    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');
    
    while (rcvChar != 'q')
    {
        //Wait for an incoming character 
        rcvChar = serial_get_char();
        switch (rcvChar) {
            case 'a':
                sound(261, tiempo);
                break;
            case 's':
                sound(294, tiempo);
                break;
            case 'd':
                sound(329, tiempo);
                break;
            case 'f':
                sound(349, tiempo);
                break;
            case 'g':
                sound(392, tiempo);
                break;
            case 'h':
                sound(440, tiempo);
                break;
            case 'j':
                sound(494, tiempo);
                break;
            case 'k':
                sound(523, tiempo);
                break;
            default:
                // Nada si no es una tecla de la fila media
                break;
        }
    }

    for (;;);
    
    return 0;
}

