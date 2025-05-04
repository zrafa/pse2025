#include "pin_config.h"
/**
 * Libreria para iniciar, configurar y usar los pines
*/


volatile unsigned char * PORT_B = (unsigned char *) 0x25;
volatile unsigned char * DDR_B = (unsigned char *) 0x24;
volatile unsigned char * PIN_B = (unsigned char *) 0x23;
volatile unsigned char * PORT_C = (unsigned char *) 0x28;
volatile unsigned char * DDR_C = (unsigned char *) 0x27;
volatile unsigned char * PIN_C = (unsigned char *) 0x26;


/**
 * Espera un codigo (0x00) que indique el pin 
*/
volatile void make_input_DDRB_PUP(unsigned char pin){
    *(DDR_B) &= (~pin);
    *(PORT_B) |= (pin);
}

volatile void make_input_DDRB(unsigned char pin){
    *(DDR_B) &= (~pin);
    *(PORT_B) &= (~pin);
}

volatile void make_output_DDRB(unsigned char pin){
    *(PORT_B) &= (~pin);
    *(DDR_B) |= (pin);
}

volatile void make_input_DDRC(unsigned char pin){
    *(DDR_C) &= (~pin);
    *(PORT_C) |= (pin);
    *(PIN_C) &= (~pin);
}

volatile void make_output_DDRC(unsigned char pin){
    *(PORT_C) &= (~pin);
    *(DDR_C) |= (pin);
}

void write_signal_B(unsigned char pin, unsigned char signal){
    if(signal > 0){
        *(PORT_B) |= (pin);
    }
    else{
        *(PORT_B) &= (~pin);
    }
}

int read_signal_B(unsigned char pin){
    return (*(PIN_B) & pin);
}
