#define MS_1 450
#define US_1 0.45

void _delay_ms(unsigned long ms){
    volatile unsigned long i;
    for(i = 0; i<ms*MS_1; i++);
}

void _delay_us(unsigned long ms){
    volatile unsigned long i;
    for(i = 0; i<ms*US_1; i++);
}