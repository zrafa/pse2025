#include <stdint.h>
#include <avr/interrupt.h>

/* Overlay Timer1 */
typedef struct
{
    uint8_t tccr1a;      // 0x80
    uint8_t tccr1b;      // 0x81
    uint8_t tccr1c;      // 0x82
    uint8_t reserved;    // 0x83
    uint16_t tcnt1;      // 0x84-0x85
    uint16_t icr1;       // 0x86-0x87
    uint16_t ocr1a;      // 0x88-0x89
    uint16_t ocr1b;      // 0x8A-0x8B
} volatile timer1_t;

/* Punteros a registros */
volatile timer1_t* timer1 = (timer1_t*) 0x80;
volatile uint8_t* timsk1 = (uint8_t*) 0x6F;

volatile uint8_t* puerto_b = (uint8_t*) 0x25;
volatile uint8_t* ddr_b    = (uint8_t*) 0x24;


#define F_CPU 16000000UL
#define PRESCALER 8UL
#define FRECUENCIA_DESEADA 11025UL
#define TOP_ICR1 ((F_CPU / (PRESCALER * FRECUENCIA_DESEADA)))


static volatile uint16_t muestra_escalada = 0;


void timer_init(void)
{
    // Configurar PB1 (OC1A) como salida
    *ddr_b |= (1 << 1);  // PB1 salida

    // Modo Fast PWM, TOP=ICR1 (modo 14)
    timer1->tccr1a = (1 << 7) | (1 << 1);       // COM1A1, WGM11
    timer1->tccr1b = (1 << 4) | (1 << 3) | (1 << 1); // WGM13, WGM12, CS11 (prescaler 8)

    timer1->icr1 = (uint16_t)TOP_ICR1;   // TOP para frecuencia
    timer1->ocr1a = timer1->icr1 / 2;    // duty inicial 50%

    *timsk1 |= (1 << 0); // Habilitar interrupción por overflow (TOIE1)

    sei(); // Habilitar interrupciones globales
}

void timer_set_dato_raw(uint8_t dato)
{
  
    uint16_t max_duty = timer1->icr1 / 5;  // 20% de TOP
    muestra_escalada = ((uint32_t)dato * max_duty) / 255;
}

ISR(TIMER1_OVF_vect)
{
    timer1->ocr1a = muestra_escalada;
}

