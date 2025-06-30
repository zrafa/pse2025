# Parpadeo de LED con Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto consiste en encender y apagar un LED conectado al pin digital 13 de una placa Arduino Nano Pro (ATmega328p). El objetivo es mostrar cómo manipular directamente los registros del microcontrolador para controlar un pin de salida, una práctica fundamental en sistemas embebidos.

## Archivos involucrados

- `main.c`
- `utils.c`
- `utils.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **LED:** Conectar el ánodo del LED al pin digital 13 (corresponde a PORTB bit 5) y el cátodo a una resistencia de 220 Ω, luego a GND.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `led-test`.

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

- Luego de cargar el programa, el LED conectado al pin 13 parpadeará con un período aproximado de 1 segundo encendido y 1 segundo apagado.
- El retardo se implementa por software utilizando un bucle vacío.

## Notas adicionales

- Se accede a los registros de control y datos de PORTB de forma directa para configurar y manipular el pin.
- Puedes adaptar el código para controlar otros pines modificando los números de bit correspondientes.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador utilizando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.

2025 – Nicolás Iván Jacznik.