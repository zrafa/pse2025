/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

int main(void){

unsigned char ledPos[8] = {32,48,24,12,4,12,24,48};


*ddr_b = 255;

while(1){
volatile unsigned long i, j;

for(i = 0; i<8;i++){
    *puerto_b = ledPos[i];
    for (j=0; j<45000; j++);
}

}


}