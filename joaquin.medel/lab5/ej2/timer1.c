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

void setCompareA(volatile uint16_t a){
    timer16b->compareAH = (a >> 8);   // Parte alta de OCR1A
    timer16b->compareAL = (a & 0xFF); // Parte baja de OCR1A
}
void setInputCompareA(volatile uint16_t a){
    timer16b->inputCaptureH = (a >> 8);   // Parte alta de OCR1A
    timer16b->inputCaptureL = (a & 0xFF); // Parte baja de OCR1A
}
void timer1_init(){
    // Preescaler = 8
    timer16b->controlB = 0;
    setInputCompareA(39999);
    timer16b->controlB |=  (1 << 1); // CS11

    // Modo Fast PWM TOP = ICR1 (modo 14)
    timer16b->controlA |= (1 << 1); // WGM11
    timer16b->controlB |= (1 << 3) | (1 << 4); // WGM12 y WGM13

    // Activar salida OC1A en modo no invertido
    timer16b->controlA |= (1 << 7); // COM1A1

    // Inicializar contador
    timer16b->counterH = 0;
    timer16b->counterL = 0;

    // TOP = 39999 → 20ms (

    // Pulso PWM inicial = 1ms
    setCompareA(0);

    // Configurar PB1 (OC1A) como salida
    volatile uint8_t *DDRB = (volatile uint8_t *) 0x24;
    *DDRB |= (1 << 1); // PB1
}