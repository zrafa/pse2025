/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

int main(void){
volatile unsigned int i;
int esperar = 0;
int prendido = 0;
    *ddr_b &= ~(1 << 4); //Configuro como entrada PB4
    *puerto_b |= (1 << 4); //Activo pull-up interno en PB4

    *ddr_b |= (1 << 5); //Configuro como salida PB5

    while(1){
        if(!(*pin_b & (1 << 4))){ //leer el estado del pin
            for (i=0; i<45000; i++);        // Esperar el switch bounce
            if (!(*pin_b & (1 << 4))) {     // Confirmar que sigue presionado
                *puerto_b ^= (1 << 5);      // Prender o apagar el LED
                while (!(*pin_b & (1 << 4))); // Esperar a que se suelte el botón
            }     
        }
    }
}