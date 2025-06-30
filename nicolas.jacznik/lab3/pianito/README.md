# Pianito Serial – Mini Piano Serial por Teclado en Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto implementa un mini piano digital ("pianito") usando un Arduino Nano Pro (ATmega328p). El sistema espera caracteres enviados por puerto serie desde una PC. Al recibir una tecla de la fila central del teclado ('a', 's', 'd', 'f', 'g', 'h', 'j', 'k'), el Arduino reproduce la nota musical correspondiente a través de un buzzer o parlante piezoeléctrico conectado al pin digital 13 (PB5).

La comunicación se realiza a 9600 bps, y la ejecución finaliza solo cuando se recibe el carácter 'q'.

## Archivos involucrados

- `main.c`
- `serial.c`
- `serial.h`
- `sound.c`
- `sound.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Buzzer o parlante:** Conectar el positivo al pin digital 13 (PB5) y el negativo a GND.
- **Puerto serie:** Utilizar un adaptador USB-TTL para la comunicación serie con la PC.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** Un programa de terminal serie (por ejemplo, `minicom`, `screen`, `PuTTY`) configurado a 9600 bps, 8N1.

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `pianito`.

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
2. Al iniciar, el Arduino enviará el mensaje "start".
3. Pulsa desde la PC las teclas 'a', 's', 'd', 'f', 'g', 'h', 'j', o 'k' para escuchar las notas DO, RE, MI, FA, SOL, LA, SI y DO (octava siguiente) respectivamente.
4. Enviar 'q' por serie detendrá el bucle principal (aunque el microcontrolador seguirá en un bucle infinito sin más acción).

## Notas adicionales

- El driver serie (`serial.c` y `serial.h`) configura el UART a 9600 bps, 8 bits de datos y 1 bit de stop.
- La generación de tonos se realiza en `sound.c` utilizando retardos precisos para controlar la frecuencia.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Puedes modificar el código para agregar más notas o cambiar la duración/frecuencias a gusto.

2025 – Nicolás Iván Jacznik.