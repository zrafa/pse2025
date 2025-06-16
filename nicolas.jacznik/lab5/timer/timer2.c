#include <avr/io.h>
#include <avr/interrupt.h>

void timer2_init_ctc(void) {
    TCCR2A = (1 << WGM21);   // Modo CTC
    TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);  // Prescaler = 1024
    OCR2A = 155;             // 10 ms -> 100 Hz
    TIMSK2 = (1 << OCIE2A);  //interrupción por comparación
}
