# Generador de Notas Musicales con Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto utiliza un Arduino Nano Pro con microcontrolador ATmega328p para generar notas musicales mediante la activación y desactivación rápida de un pin digital, utilizando retardos precisos por software. El programa reproduce una escala musical (DO, RE, MI, FA, SOL, LA, SI, DO) conectando un buzzer o parlante piezoeléctrico al pin digital 13 (PB5). Cada nota tiene una frecuencia y duración específicas, generando el tono correspondiente.

## Archivos involucrados

- `main.c`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Buzzer o parlante:** Conectar el positivo del buzzer al pin digital 13 (PB5) y el negativo a GND.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `sound`.

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

- Al cargar el programa y conectar el buzzer, se escuchará la escala musical DO-RE-MI-FA-SOL-LA-SI-DO, repitiéndose en bucle.

### Personalización

- Puedes modificar la función `sound` o cambiar las frecuencias y duraciones en el bucle principal para crear melodías personalizadas.

## Video

- Se puede ver un video del programa en ejecución mediante el siguiente enlace: https://drive.google.com/file/d/1n14VaDRapezmLa-QYcBFQic4TP0Jlzbw/view?usp=drive_link

## Notas adicionales

- El sonido se genera accionando directamente el pin PB5 con retardos precisos usando `_delay_us` y `_delay_ms`.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Se recomienda usar un buzzer pasivo para obtener mejores resultados, aunque también puede funcionar con un parlante piezoeléctrico pequeño.

2025 – Nicolás Iván Jacznik.