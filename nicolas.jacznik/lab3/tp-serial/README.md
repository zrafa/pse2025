# TP Serial – Eco de Caracteres por Puerto Serie en Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto implementa un eco de caracteres utilizando el microcontrolador ATmega328p (como en un Arduino Nano Pro). El sistema inicializa el puerto serie a 9600 bps y espera la recepción de caracteres desde una PC. Cada carácter recibido es retransmitido (eco) seguido de un retorno de carro y un salto de línea. El programa finaliza cuando se recibe el carácter 'q', aunque el microcontrolador permanece en un bucle infinito.

## Archivos involucrados

- `main.c`
- `serial.c`
- `serial.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Puerto serie:** Utiliza un adaptador USB-TTL para la comunicación serie con la PC.

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

   Esto generará el archivo ejecutable `tp-serial`.

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

1. Abre **cutecom** (o cualquier otro programa de terminal serie) en la PC.
2. Configura el puerto serie correspondiente (por ejemplo, `/dev/ttyUSB0`) con los siguientes parámetros:
   - **Baudrate:** 9600
   - **Data bits:** 8
   - **Parity:** None (N)
   - **Stop bits:** 1
   - **Flow control:** None
3. Al iniciar, el Arduino enviará el mensaje "start".
4. Cada tecla que envíes desde la PC será devuelta (eco) junto con un salto de línea. Cuando envíes la tecla 'q', el programa dejará de responder (quedando en un bucle infinito).

## Notas adicionales

- El driver serie (`serial.c` y `serial.h`) configura el UART a 9600 bps, 8 bits de datos y 1 bit de stop.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Puedes modificar el código para cambiar el carácter de salida o extender su funcionalidad.
- Cutecom es una opción sencilla y multiplataforma para pruebas de comunicación serie.

2025 – Nicolás Iván Jacznik.