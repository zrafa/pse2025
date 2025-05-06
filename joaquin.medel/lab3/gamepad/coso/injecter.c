#include <stdio.h>
#include <unistd.h>
#include <time.h>

// Define la cantidad de veces por segundo que quieres que se ejecute el bucle
#define FPS 60
int func()
{
    printf("Ejecución a %d FPS\n", FPS);
}
int main()
{
    struct timespec start, end;
    long interval = 1000000 / FPS; // Intervalo en microsegundos (usleep toma microsegundos)

    while (1)
    {
        // Guarda el tiempo de inicio de la iteración
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Coloca aquí el código que deseas ejecutar cada vez
        func()

            // Guarda el tiempo de fin de la iteración
            clock_gettime(CLOCK_MONOTONIC, &end);

        // Calcula el tiempo que ha tardado la ejecución en microsegundos
        long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

        // Calcula el tiempo de espera restante para alcanzar el intervalo deseado
        long sleep_time = interval - elapsed_time;

        // Si la ejecución fue más rápida que el intervalo, duerme el tiempo restante
        if (sleep_time > 0)
        {
            usleep(sleep_time); // Duerme el tiempo restante en microsegundos
        }
    }

    return 0;
}
