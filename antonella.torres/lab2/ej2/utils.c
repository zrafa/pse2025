
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * port_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar(unsigned int ms) {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450*ms; i++);
}


void init() {
    // d8,d10,d11 tienen conectados leds
    *ddr_b |= (1 << 0); 
    *ddr_b |= (1 << 2); 
    *ddr_b |= (1 << 3); 

	*port_b &= ~0x0D; 


    // Configuro d9 para pulsador
    *ddr_b &= ~(1 << 1);  
    *port_b |= (1 << 1);  


	
}
void contador_binario() {
    volatile unsigned char contador = 0;
    volatile unsigned char pausado = 0;

    while (1) {
        if ((*pin_b & (1 << 1)) == 0) {  
            pausado = !pausado;         
            esperar(50);                

            // mientras no se solto el boton espero
            while ((*pin_b & (1 << 1)) == 0);
            esperar(50);               
        }

        if (!pausado) {
			//si no esta pausado sigo contando 
			*port_b = (*port_b & ~((1 << 0) | (1 << 2) | (1 << 3))) |
			((contador & 0x01) << 0) |   // d8
			((contador & 0x02) << 1) |   // d10
			((contador & 0x04) << 1);    // d11
  
            contador = (contador + 1) % 8;
            esperar(3000);
			esperar(3000);
		
        }
    }

}