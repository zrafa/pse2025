#!/bin/bash

# Puerto serie a usar (modificá si no es ttyUSB0)
PUERTO="/dev/ttyUSB0"

# Configuración del puerto: 9600 bps, 8N1, sin control de flujo
BAUD="9600"

echo "Abriendo $PUERTO a $BAUD bps con configuración 8N1, sin control de flujo..."
echo "Para salir y liberar el puerto: Ctrl + A, luego Ctrl + Q"

picocom -b $BAUD -d 8 -p e -f n $PUERTO
