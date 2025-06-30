# Game Controller Serial – Controlador de Juego por Puerto Serie con Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto implementa un "game controller" básico utilizando un Arduino Nano Pro (ATmega328p). Permite simular la pulsación de teclas en una PC mediante botones conectados a los pines digitales 10, 11 y 12 del Arduino. Cuando se presiona un botón, el sistema envía por puerto serie los caracteres 'a', 's' o 'd', que pueden ser interpretados por un script en la PC para simular pulsaciones de teclado reales, facilitando así la creación de interfaces físicas personalizadas para juegos o automatizaciones.

## Archivos involucrados

- `main.c`
- `serial.c`
- `serial.h`
- `Makefile`
- `script.sh` (script de ejemplo para la PC, utilizando xdotool en Linux)

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Botones:**  
  - Pin digital 12 (PB4): Botón para enviar 'a'
  - Pin digital 11 (PB3): Botón para enviar 's'
  - Pin digital 10 (PB2): Botón para enviar 'd'
  - Cada botón debe conectarse entre el pin correspondiente y GND. El pull-up interno está activado por software en el código.
- **Puerto serie:** Utilizar adaptador USB-TTL para la comunicación con la PC.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** `xdotool`, `stty`, bash (para el script)

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `game_controller`.

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

### Configuración y uso en la PC

1. Asegúrate de tener instalado `xdotool` y permisos para leer del dispositivo serie.
2. Ejecuta el script `script.sh` en la PC para traducir los caracteres recibidos por serie en pulsaciones de teclado:

   ```sh
   chmod +x script.sh
   ./script.sh
   ```

   El script configura la velocidad y modo del puerto serie y, por cada carácter recibido ('a', 's' o 'd'), simula la pulsación de la tecla correspondiente en el entorno gráfico.

## Uso

- Cada vez que se presiona un botón conectado a los pines 10, 11 o 12, el Arduino envía repetidamente el carácter asociado por puerto serie mientras el botón esté presionado.
- El script en la PC recibe estos caracteres y simula pulsaciones de teclado, permitiendo controlar juegos u otras aplicaciones con hardware físico personalizado.

## Notas adicionales

- Los pines de botón usan pull-ups internos, por lo que sólo se requiere un botón entre el pin y GND.
- El driver serie (`serial.c` y `serial.h`) configura el UART a 9600 bps, 8 bits de datos y 1 bit de stop.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- El script es un ejemplo para sistemas Linux, pero la idea puede adaptarse a otros sistemas operativos o herramientas de automatización.

2025 – Nicolás Iván Jacznik.