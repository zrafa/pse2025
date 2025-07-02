# Timer – Cronómetro con Interrupciones y Salida Serial (ATmega328p)

## Descripción

Este proyecto implementa un cronómetro digital utilizando un Arduino Nano Pro (ATmega328p). El cronómetro mide y muestra minutos, segundos y centésimas de segundo, enviando el tiempo transcurrido por el puerto serie cada 100 ms. La medición del tiempo se realiza utilizando el temporizador Timer2 en modo CTC e interrupciones.

## Funcionamiento

- Se utiliza **Timer2** en modo CTC con prescaler 1024 para generar una interrupción cada 10 ms.
- En cada interrupción, se incrementa una estructura de tipo `Cronometro` que lleva el conteo de centésimas, segundos y minutos.
- El tiempo actual (MM:SS:CC) se envía de manera continua por el puerto serie a 9600 bps, con formato de dos dígitos por campo.
- El programa nunca se detiene y actualiza el tiempo indefinidamente.

## Archivos involucrados

- `main.c`
- `serial.c`
- `serial.h`
- `timer2.c`
- `timer2.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Puerto serie:** Adaptador USB-TTL para comunicación con la PC (por ejemplo, `/dev/ttyUSB0`).

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** Un programa de terminal serie (por ejemplo, `cutecom`, `minicom`, `screen`, `PuTTY`) configurado a 9600 bps, 8N1.

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `timer`.

### Generar archivo HEX y grabar en el Arduino Nano Pro

1. Conecta la placa Arduino Nano Pro a la PC (ajusta `/dev/ttyUSB0` si es necesario).
2. Ejecuta:

   ```sh
   make flash
   ```

   Esto convertirá el binario a formato Intel HEX y lo grabará en la placa usando `avrdude`.

3. Para limpiar los archivos generados:

   ```sh
   make clean
   ```

## Uso

1. Abre una terminal serie en la PC a 9600 bps, 8N1.
2. Observarás en la terminal la salida periódica del cronómetro en formato `MM:SS:CC` (minutos, segundos, centésimas).
3. El cronómetro cuenta hasta 99:59:99 y luego reinicia a 00:00:00 automáticamente.

## Detalles de implementación

- **Temporización precisa:** El uso de interrupciones garantiza que el cronómetro sea preciso y no dependa de retardos por software.
- **Estructura Cronometro:** Maneja los campos `centesimas`, `segundos` y `minutos` como variables atómicas (volátiles) actualizadas en la ISR.
- **Salida serial:** El driver serial está configurado para 9600 bps, 8 bits de datos, 1 bit de stop, sin paridad.
- **Modularidad:** El temporizador y el serial están implementados como drivers separados para facilitar su reutilización.

## Video

- Se puede ver un video del programa en ejecución mediante el siguiente enlace: https://drive.google.com/file/d/1XRfqRv6Yp6sQZcHf86LwMk6CkiNDhJKT/view?usp=sharing

## Notas adicionales

- Puedes modificar el código para añadir funciones de pausa, reinicio, o aumentar la precisión/cantidad de dígitos.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.

2025 – Nicolás Iván Jacznik.