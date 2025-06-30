# Medición de Distancias con Sensor Ultrasónico HC-SR04 y Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto permite medir distancias utilizando un sensor ultrasónico HC-SR04 conectado a una placa Arduino Nano Pro (ATmega328p). El sistema calcula y muestra la distancia en centímetros del objeto más cercano, enviando los resultados por el puerto serie a 9600 bps para su visualización en una terminal.

## Archivos involucrados

- `main.c`
- `ultrasound.c`
- `ultrasound.h`
- `serial.c`
- `serial.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Sensor HC-SR04:**
  - Echo: Pin digital 10 (PB2)
  - Trigger: Pin digital 11 (PB3)
  - VCC y GND: a 5V y GND del Arduino
- **Puerto serie:** Utilizar un adaptador USB-TTL para la salida en terminal serie (9600 bps, 8N1).

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `ultrasound`.

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

- Tras programar el Arduino, el sistema medirá cada dos segundos la distancia al objeto más cercano que detecte el sensor ultrasónico y enviará la información por puerto serie en el formato:  
  ```
  La distancia es de XXXX cm.
  ```
- Si no se detecta ningún objeto o está fuera de rango, se enviará `-1` como distancia.

### Personalización

- Puedes modificar el intervalo de medición cambiando la constante en `_delay_ms(2000)` en el archivo `main.c`.

## Notas adicionales

- El sensor HC-SR04 es controlado directamente mediante acceso a los registros PORTB.
- El driver serie (`serial.c` y `serial.h`) configura el UART a 9600 bps, 8 bits de datos y 1 bit de stop.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- El código es fácilmente extensible para otras funciones o sensores adicionales.

2025 – Nicolás Iván Jacznik.