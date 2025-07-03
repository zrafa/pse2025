Proyecto: Driver UART para ATmega328P 
---------------------------------------------------------------------

Este proyecto implementa un driver UART para microcontroladores ATmega328P en lenguaje C, sin dependencias de bibliotecas externas como Arduino. Se utiliza un programa de prueba (main.c) que envía un mensaje inicial por UART y luego hace eco de los caracteres recibidos hasta que se recibe la letra q.

1. CONFIGURACIÓN DE HARDWARE
----------------------------

- Microcontrolador: ATmega328P (ej. en Arduino Uno, Nano, Pro Mini)
- Conexiones UART:
    - TX del microcontrolador → RX de un adaptador USB-TTL o PC
    - RX del microcontrolador ← TX del adaptador USB-TTL o PC
    - GND compartido entre el microcontrolador y el adaptador

- Alimentación: 5V estable
- Baud rate: 9600 bps
- Configuración de UART: 8 bits de datos, 1 bit de stop, sin paridad (8N1)

2. CÓMO COMPILAR, FLASHEAR Y EJECUTAR
-------------------------------------

El proyecto usa un Makefile. Para compilar y grabar el programa:

- Compilar:
  make

- Flashear (ajustar /dev/ttyUSB0 si es necesario):
  make flash

- Limpiar archivos intermedios:
  make clean

3. CONFIGURACIÓN DE SOFTWARE
----------------------------

- serial.c implementa el controlador UART accediendo directamente a los registros del periférico en la dirección 0xC0.
- serial.h expone las funciones:
    - serial_init() — inicializa UART a 9600 bps
    - serial_put_char(char c) — envía un carácter
    - serial_get_char() — espera y recibe un carácter

- main.c realiza una prueba:
    - Envía "start" al iniciar
    - Espera caracteres desde el puerto serie
    - Hace eco del carácter recibido seguido de nueva línea
    - Finaliza si se recibe q
