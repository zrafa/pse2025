# Proyecto: Reproductor de sonidos mediante UART y piezo speaker con ATmega328P
================================================================================

Este proyecto permite reproducir sonidos a través de un buzzer piezoeléctrico conectado a un pin digital del ATmega328P. Las notas musicales se controlan por comandos recibidos vía UART, permitiendo al usuario tocar distintas notas desde una terminal serie.

--------------------------------------------------------------------------------
## 1. Configuración de hardware
--------------------------------------------------------------------------------

- Microcontrolador: ATmega328P
- Piezo speaker: conectado a PB2 (pin digital 10 de Arduino Nano)
- Conexión UART:
  - TX y RX conectados a un adaptador USB-TTL o cable FTDI
  - Velocidad: 9600 bps
- Alimentación: 5V estable para el microcontrolador y el buzzer
- Conexión al host: mediante puerto serie (/dev/ttyUSB0 en Linux, COMx en Windows)

--------------------------------------------------------------------------------
## 2. Cómo compilar, flashear y ejecutar
--------------------------------------------------------------------------------

Requisitos:
- avr-gcc, avrdude, make
- Archivo Makefile con objetivos:
  - make: compila el código
  - make flash: graba el .hex en el microcontrolador
  - make clean: borra archivos generados

Pasos:
1. Conectar el Arduino Nano Pro o placa con ATmega328P al puerto USB.
2. Ajustar el puerto serie en el Makefile si es necesario (/dev/ttyUSB0, etc.).
3. Ejecutar en terminal:

   make
   make flash

4. Abrir una terminal serie con minicom, screen, picocom o similar:

   screen /dev/ttyUSB0 9600

--------------------------------------------------------------------------------
## 3. Configuración de software
--------------------------------------------------------------------------------

- La función serial_init() configura el UART a 9600 bps, 8N1.
- Al iniciar, el sistema reproduce dos notas (E5) y envía "start" por UART.
- Luego espera comandos de usuario:

    'a' → DO (261 Hz)
    'b' → RE (293 Hz)
    'c' → MI (329 Hz)
    'd' → FA (349 Hz)
    'e' → SOL (392 Hz)
    'f' → LA (440 Hz)
    'g' → SI (493 Hz)

- Cada nota se reproduce por 1000 ms.
- Se usa la función sound(frecuencia, duración) que genera una señal cuadrada manipulando el pin PB2.
- También se incluye una función soundT() que genera un tono constante a 261 Hz (usado como ejemplo de nota fija).

