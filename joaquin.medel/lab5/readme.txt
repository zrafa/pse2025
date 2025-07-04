## Descripción

Este laboratorio utiliza el **Timer 1** del ATmega328 con interrupciones para lograr un control más preciso del tiempo. Además, se emplea el mismo temporizador para la **generación de señales PWM**, útiles para controlar dispositivos externos.

## Conexiones

Conectar el dispositivo que requiera la señal PWM al pin **D9** (OC1A) del microcontrolador.

## Uso
1. Ejecutar:
   make && make flash
2. Requisitos:
   - Tener instaladas las siguientes herramientas:
     - make
     - avr-gcc
     - avrdude
   - Conectar el Arduino al puerto serie y asegurarse de que el puerto esté **libre y sin uso por otras aplicaciones**.

## Videos

(https://drive.google.com/file/d/1s2SgG0bbhpZU7awdKYJAG9CHs8YEiIoa/view?usp=drive_link)
