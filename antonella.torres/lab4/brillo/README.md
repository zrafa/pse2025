
Proyecto: Control automático del brillo con fotoresistencia
============================================================

Descripción:
------------
Este proyecto utiliza una fotoresistencia (LDR) conectada al microcontrolador ATmega328p para medir la luz ambiente. El valor analógico es enviado vía UART a una PC, que ajusta automáticamente el brillo de la pantalla usando `brightnessctl`.

1. CONFIGURACIÓN DEL HARDWARE
=============================

Componentes utilizados:
-----------------------
- ATmega328p (por ejemplo, Arduino Nano)
- Fotoresistencia (LDR)
- Resistencia fija de 10kΩ
- Adaptador USB-Serial (ej. CH340)
- PC con Linux

Conexiones:
-----------
- Fotoresistencia conectada entre VCC y A2 (PC2)
- Resistencia de 10kΩ conectada entre A2 (PC2) y GND
- TX del micro al RX del adaptador USB-Serial
- GND en común entre placa y adaptador


2. CÓMO COMPILAR, FLASHEAR Y EJECUTAR
-------------------------------------

El proyecto usa un Makefile. Para compilar y grabar el programa:

- Compilar:
  make

- Flashear (ajustar /dev/ttyUSB0 si es necesario):
  make flash

- Limpiar archivos intermedios:
  make clean

Ejecutar el script: 

./ajustar_brillo.sh


3.CONFIGURACIÓN DEL SOFTWARE
=============================

En main.c:

Se lee el canal 2 del ADC (A2 / PC2)

Se envía el valor por UART cada 100ms.

En adc.c y serial.c:

Se ocultan los detalles del hardware.

El ADC se configura con AVcc como referencia y prescaler 128.

UART se inicializa a 9600bps, 8N1.

