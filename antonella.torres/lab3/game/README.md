

Proyecto: Simulación de Teclas por UART + Botones físicos
==========================================================

Este proyecto permite que un sistema embebido (basado en ATmega328P) detecte botones físicos conectados al microcontrolador y envíe caracteres por UART. Luego, un script en Bash toma esos caracteres y simula teclas (izquierda/derecha) en el sistema operativo usando evemu.

1. CONFIGURACIÓN DE HARDWARE
============================

Dispositivos:
-------------
- Microcontrolador ATmega328P (ej. Arduino Uno, Nano, etc.)
- 2 botones conectados a:
  - D9 (PB1) → botón para simular tecla derecha ('D')
  - D10 (PB2) → botón para simular tecla izquierda ('A')

Conexiones:
-----------
- Ambos pines con resistencias pull-up activadas por software
- GND común para ambos botones
- UART:
  - TX del ATmega328P → RX de un adaptador USB-TTL conectado al puerto serie del host (ej. /dev/ttyUSB0)

2. CÓMO COMPILAR, FLASHEAR Y EJECUTAR
=====================================

En el microcontrolador:
-----------------------
- Usar `make` para compilar (Makefile no incluido aquí)
- Usar `make flash` o `avrdude` para flashear el binario al ATmega328P

En el host (Linux):
-------------------
1. Dar permisos o usar sudo para acceder a `/dev/input/event0` y `/dev/ttyUSB0`
2. Ejecutar el script de escucha:
   ```bash
   ./teclas.sh


Este script:
Lee caracteres por UART desde /dev/ttyUSB0

Si recibe 'a', simula tecla LEFT con evemu

Si recibe 'd', simula tecla RIGHT con evemu

Si recibe ambos botones al mismo tiempo, envía 'A' y 'D'

Configuración previa requerida:
Instalar evemu-tools y xdotool

Identificar el nombre correcto del dispositivo de entrada (/dev/input/eventX) usando evemu-describe o lsinput

CONFIGURACIÓN DEL SOFTWARE
=============================

En C (ATmega328P):
Usa registros directos (PORTB, DDRB, PINB) para leer entradas de botones

Usa serial_put_char para enviar caracteres por UART

init() configura PB1 y PB2 como entradas con pull-up

Usa un pequeño delay software con esperar(ms)

En Bash (teclas.sh):
Configura el puerto serial con stty

Usa xdotool para detectar la ventana activa

Usa evemu-event para simular teclas KEY_LEFT y KEY_RIGHT
