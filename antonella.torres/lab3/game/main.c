
/* puertos de E/S */
#include "serial.h"
/* direccion de PORTB (registro de datos) */
volatile unsigned char * port_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;




void init() {
       // Configuro d9 para pulsador
    *ddr_b &= ~(1 << 1);  
    *port_b |= (1 << 1);  
    *ddr_b &= ~(1 << 2);  


    *port_b |= (1 << 2);  

}

void esperar(unsigned int ms) {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450*ms; i++);
}


int main (void){

    init();
    serial_init();

    while (1) {
        if ((*pin_b & (1 << 1)) == 0 && (*pin_b & (1 << 2)) == 0) {  
            esperar(50);                
            // mientras no se soltaron los botones espero
            while ((*pin_b & (1 << 1)) == 0 && (*pin_b & (1 << 2)) == 0);
            esperar(50);         
            serial_put_char('A');    
            serial_put_char('D');    
            
        }
        else {
            if ((*pin_b & (1 << 1)) == 0) {
                esperar(50);                
                // mientras no se solto el boton espero
                while ((*pin_b & (1 << 1)) == 0);
                
                
                esperar(50);               
                serial_put_char('D');    
            }
            else{
                if ((*pin_b & (1 << 2)) == 0) {
                    esperar(50);                
                    // mientras no se solto el boton espero
                    while ((*pin_b & (1 << 2)) == 0);
                    esperar(50);               
                    serial_put_char('A');    
                }
            }

    }
}
}