/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

 #include "serial.h"
 #include "ultrasound.h"
 
 #define __DELAY_BACKWARD_COMPATIBLE__
 #define F_CPU   8000000UL
 #include <util/delay.h>
 

 float octaveFrequencies[12] = {
    261.63f, // C4 (Do)
    277.18f, // C#4 / Db4
    293.66f, // D4 (Re)
    311.13f, // D#4 / Eb4
    329.63f, // E4 (Mi)
    349.23f, // F4 (Fa)
    369.99f, // F#4 / Gb4
    392.00f, // G4 (Sol)
    415.30f, // G#4 / Ab4
    440.00f, // A4 (La)
    466.16f, // A#4 / Bb4
    493.88f  // B4 (Si)
};

float escalaMenor[] = {
    440.00, // A4
    493.88, // B4
    523.25, // C5
    587.33, // D5
    659.25, // E5
    698.46, // F5
    783.99  // G5
};

float escalaMenorArmonica[] = {
    440.00, // A4
    493.88, // B4
    523.25, // C5
    587.33, // D5
    659.25, // E5
    698.46, // F5
    830.61  // G#5
};

float escalaDorica[] = {
    440.00, // A4
    493.88, // B4
    523.25, // C5
    587.33, // D5
    659.25, // E5
    739.99, // F#5
    783.99  // G5
};

float escalaFrigia[] = {
    440.00, // A4
    466.16, // Bb4
    523.25, // C5
    587.33, // D5
    659.25, // E5
    698.46, // F5
    783.99  // G5
};

int main(void)
{
    int dist_cm = 8;
    serial_init();
    ultrasound_init();

     /* Ejemplo de uso de la biblioteca serial */
         serial_put_str("HOLA MUNDO \r\n");
            serial_put_int(dist_cm, 4);	/* Mostrar distancia */
     
     /* un programa embebido nunca finaliza */

     int running = 0;
     for (;;) {

        if(pulsed())
            running = !running;

        if(running)
        {
            dist_cm = ultrasound_get_distance();
            int nota = (int)((dist_cm / 10.0) * 7);
            if(dist_cm <= 10)
            {
                set_leds(nota+1);
                sound(escalaFrigia[7-nota], 100);
            }
            else 
                set_leds(0);
        }
    }
 }
 