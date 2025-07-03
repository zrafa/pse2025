# Proyecto: LED Oscilante con ATmega328P

Este proyecto permite encender y apagar varios LEDs conectados al puerto B del ATmega328P, simulando un efecto de barrido hacia un lado y luego hacia el otro.

---

## 1. Configuración de hardware

- Microcontrolador: ATmega328P
- LEDs conectados a: Puerto B, bits 1, 2, 3 y 5 (corresponden a pines digitales 9, 10, 11 y 13 de Arduino).
- Conexiones:
  - Pin 13 (PB5) → LED
  - Pin 11 (PB3) → LED
  - Pin 10 (PB2) → LED
  - Pin 9  (PB1) → LED
  - Cada LED debe estar conectado en serie con una resistencia (por ejemplo, 220Ω) a GND.

---

## 2. Cómo compilar, flashear y ejecutar

Este proyecto cuenta con un Makefile. Para compilar, flashear y limpiar, se utilizan los siguientes comandos:

Compilar:
  make

Antes de realizar el siguiente paso, Conecta la placa Arduino Nano Pro a la PC (ajusta /dev/ttyUSB0 si es necesario). 

Generar el archivo .hex y flashear al microcontrolador:
  make flash

Limpiar archivos generados:
  make clean

Notas:
- Se compila usando avr-gcc con una frecuencia de reloj definida en 16 MHz (`-DF_CPU=16000000UL`).
- El flasheo se realiza usando avrdude con programador tipo `arduino` y puerto `/dev/ttyUSB0` a 115200 baudios. Modificar según el entorno si es necesario.

---

## 3. Configuración de software

- No requiere calibración.
- El comportamiento de los LEDs se define en el arreglo `states[]` dentro de `utils.c`. Cada valor representa un patrón de encendido.
- El retardo entre cambios de patrón se define en la función `esperar()`. Se puede modificar la duración ajustando el valor del ciclo `for`.

---

## 4. Video demostración



---
