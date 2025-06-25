#include <stdint.h>
typedef struct
{
    uint8_t controlA; //TCCR1A 0x80
    uint8_t controlB; //TCCR1B 0x81
    uint8_t controlC; //TCCR1C 0x82
    uint8_t reserved; //Salto 0x83
    uint8_t counterL; // 0x84
    uint8_t counterH; // 0x85
    uint8_t inputCaptureL; // 0x86
    uint8_t inputCaptureH; // 0x87
    uint8_t compareAL; // 0x88
    uint8_t compareAH; // 0x89
    uint8_t compareBL; // 0x8A
    uint8_t compareBH; // 0x8B
} volatile timer16;


/* puntero a la estructura de los registros del periferico */
timer16 *timer16b = (timer16 *)(0x80);

void setCompareA(uint16_t a){
    timer16b->compareAH = (a >> 8);   // Parte alta de OCR1A
    timer16b->compareAL = (a & 0xFF); // Parte baja de OCR1A
}
void timer1_init(){
    timer16b->controlB |=  0b00000010; //Preescalar 8 bits
    timer16b->controlB |=  0b00001000; //Modo CTC WGM12

    timer16b->counterH = 0;
    timer16b->counterL = 0;

    volatile uint8_t *TIMSK1 = (volatile uint8_t *)0x6f;
    *TIMSK1 |= 0b00000010;
    volatile uint8_t *SREG =(volatile uint8_t *) 0x5f;
    *SREG |= 0b10000000;
    
    setCompareA(20000);//1 centesima, por defecto 
}