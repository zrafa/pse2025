#include "delay.h"

volatile unsigned char *ddr_b = (unsigned char *) 0x24;
volatile unsigned char *port_b = (unsigned char *) 0x25;
volatile unsigned char *pin_b = (unsigned char *) 0x23;

//0 --> pausado
//1 --> continuar
volatile unsigned char state = 1;

volatile unsigned char contador = 0x00;
volatile unsigned char limit = 0x3C; //0011 1100
volatile unsigned char button_pin = 0x02;
volatile unsigned char count_pins = 0x3C;

/**
 * Reseteo el port para escribir y el pin para leer
 * El ddr en 1 envia señales con portb
 * El ddr con 0 recibe señales con pin 
 */
void led_init(){
    *(ddr_b) |= (count_pins);
    *(port_b) &= (~count_pins);
}

//Estado con pull-up habilitado  {DDxn, PORTxn} = 0b01
//En pull up, pull 0, pull-up 1 (3 semanas para entender esto)
void input_init(){
    *(ddr_b) &= (~button_pin);
    *(port_b) |= (button_pin);
    *(pin_b) &= (~button_pin);
}

void count(){
    if(state){
        contador += 0x04;
        if(contador > limit){
            contador = 0;
        }
    }
    *(port_b) = *(port_b) & (~limit);
    *(port_b) = *(port_b) | (contador);
}

//recibir entrada y actualizar el contador +1
void read(){
    volatile unsigned char save;
    if(!(*(pin_b) & button_pin)){
        delay_ms(30);
        state = (state+1)%2;
    }
}

