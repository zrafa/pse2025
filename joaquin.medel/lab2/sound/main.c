#include "utils.h"
#include "speaker_driver.h"
#include "ultrasound.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU 16000000UL
#include <util/delay.h>
int main()
{
    volatile unsigned long i = 1;
    sound_init();
    ultrasound_init();

    /*const int cumpleanos_notas[] = {
        SOL4, SOL4, LA4, SOL4, DO5, SI4,
        SOL4, SOL4, LA4, SOL4, RE5, DO5,
        SOL4, SOL4, SOL5, MI5, DO5, SI4, LA4,
        FA5, FA5, MI5, DO5, RE5, DO5};

    const int cumpleanos_duraciones[] = {
        500, 500, 1000, 1000, 1000, 2000,
        500, 500, 1000, 1000, 1000, 2000,
        500, 500, 1000, 1000, 1000, 1000, 2000,
        500, 500, 1000, 1000, 1000, 2000};
    volatile int n = 25;
    */
    const int melodia_mario[] = {
        MI7, MI7, REST, MI7, REST, DO7, MI7, REST,
        SOL7, REST, REST, SOL6, REST, REST,
        DO7, REST, REST, SOL6, REST, REST, MI6, REST, REST,
        LA6, REST, SI6, REST, LAs6, LA6, REST,
        SOL6, MI7, SOL7, LA7, REST, FA7, SOL7, REST,
        MI7, REST, DO7, RE7, SI6, REST, REST};

    // Duración de cada nota (en milisegundos)
    const int duraciones_mario[] = {
        200, 200, 200, 200, 200, 200, 200, 200,
        400, 400, 400, 400, 400, 400,
        400, 400, 400, 400, 400, 400, 400, 400, 400,
        200, 200, 200, 100, 200, 200, 200,
        200, 200, 200, 200, 200, 200, 200, 200,
        200, 200, 200, 200, 200, 400, 400};
    const int n = sizeof(melodia_mario) / sizeof(melodia_mario[0]);
    for (uint8_t j = 0; j < n; j++)
    {
        sound(melodia_mario[j], duraciones_mario[j] / 2); // 500 ms por nota
        _delay_ms(100);                                   // Pausa entre notas
    }
}