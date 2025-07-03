# Proyecto: Encendido y apagado de un LED con ATmega328P

Este proyecto enciende y apaga un único LED conectado al pin digital 13 del Arduino (PB5 en el ATmega328P) con una pausa entre cada cambio de estado.

## 1. Configuración de hardware

- Microcontrolador: ATmega328P  
- LED conectado a: Puerto B, bit 5 (corresponde al pin digital 13 de Arduino).  
- Conexiones:
  - Pin 13 (PB5) → Ánodo del LED  
  - Cátodo del LED → Resistencia de 220Ω → GND

## 2. Cómo compilar, flashear y ejecutar

Este proyecto incluye un Makefile para automatizar los pasos.

Compilar:
  make

Generar el archivo .hex y flashear el microcontrolador:
  make flash

Limpiar archivos generados:
  make clean

Notas:
- Se utiliza avr-gcc con una frecuencia de reloj definida en 16 MHz (-DF_CPU=16000000UL).
- El flasheo se realiza con avrdude, usando programador tipo arduino, puerto /dev/ttyUSB0 y velocidad de 115200 baudios. Modificar según corresponda.

## 3. Configuración de software

- No requiere calibración.
- El parpadeo del LED está definido por la función esperar() en utils.c, que genera un retardo aproximado de 1 segundo.
- Para cambiar la velocidad de parpadeo, modificar el valor del ciclo for en dicha función.

## 4. Video demostración

[Enlace al video de demostración]
