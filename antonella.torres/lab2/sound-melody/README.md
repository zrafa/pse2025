# Proyecto: Reproductor de melodías con piezo speaker en ATmega328P

Este proyecto implementa la reproducción de una melodía simple utilizando un piezo speaker conectado a un pin digital del microcontrolador ATmega328P. La señal digital se genera controlando la frecuencia de períodos mediante retardos precisos, logrando reproducir diferentes notas musicales.

## 1. Configuración de hardware

- Microcontrolador: ATmega328P (por ejemplo, Arduino Nano o similar)  
- Piezo speaker conectado al pin PB2 (pin digital 10 en Arduino)  
- Alimentación estable a 5V para microcontrolador y piezo  
- Conexión a computadora para programación vía USB o programador ISP

## 2. Cómo compilar, flashear y ejecutar

- Compilar con avr-gcc configurado para ATmega328P a 16 MHz  
- Usar el Makefile proporcionado con comandos:  
  `make` — para compilar  
  `make flash` — para convertir a hex y grabar el firmware en el microcontrolador  
  `make clean` — para limpiar archivos generados  

- Flashear con avrdude usando el programador y puerto serie adecuados (por ejemplo, `/dev/ttyUSB0`)  
- El programa comienza a reproducir la melodía en bucle apenas el microcontrolador se enciende

## 3. Configuración de software

- La función `sound(int frec, int duracion)` genera la señal en el pin PB2 alternando su estado para crear un tono a la frecuencia deseada  
- La frecuencia se calcula controlando el retardo entre alternancias con `_delay_us()` para lograr la duración del medio ciclo, de modo que la frecuencia sea precisa  
- La melodía está almacenada en arreglos:  
  - `melody[]`: frecuencias de las notas (en Hz)  
  - `durations[]`: duración de cada nota (en milisegundos)  
  - `pauses[]`: pausa entre notas (en milisegundos)  
- En el `main()`, se reproduce cada nota de la melodía secuencialmente, respetando duraciones y pausas

## 4. Video demostración

[Enlace al video de demostración]

---

