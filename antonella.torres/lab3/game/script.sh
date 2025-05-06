#!/bin/bash

# Configurar el puerto serie
stty -F /dev/ttyUSB0 speed 9600 raw -echo

# El archivo de dispositivo virtual donde enviaremos los eventos
DEV_INPUT="/dev/input/event0"  # Ahora usamos 'event0' para el teclado

# Revisa si el dispositivo está disponible
if [[ ! -e "$DEV_INPUT" ]]; then
  echo "Dispositivo de entrada virtual no encontrado en $DEV_INPUT"
  exit 1
fi

cat /dev/ttyUSB0 | while read -n 1 tecla; do
    # Convertir la tecla a minúsculas para garantizar que no importe si es mayúscula o minúscula
    tecla=$(echo "$tecla" | tr '[:upper:]' '[:lower:]')

    echo "Tecla recibida: $tecla"
    
    # Obtener ID de la ventana activa
    ventana_id=$(xdotool getactivewindow)

    # Obtener nombre de la ventana (puede fallar si la ventana no existe)
    ventana_nombre=$(xdotool getwindowname "$ventana_id" 2>/dev/null)

    # Mostrar información
    echo "ID de ventana activa: $ventana_id"
    echo "Nombre de la ventana: $ventana_nombre"

    echo "Ventana activa: $ventana_id"

    # Simular la tecla presionada con evemu
    if [[ "$tecla" == "d" ]]; then
        echo "Simulando tecla Right"
        sudo evemu-event "$DEV_INPUT" --type EV_KEY --code KEY_RIGHT --value 1  # key down
        sudo evemu-event "$DEV_INPUT" --type EV_KEY --code KEY_RIGHT --value 0  # key up
        sudo evemu-event "$DEV_INPUT" --type EV_SYN --code SYN_REPORT --value 0  # sincronización
    elif [[ "$tecla" == "a" ]]; then
        echo "Simulando tecla Left"
        sudo evemu-event "$DEV_INPUT" --type EV_KEY --code KEY_LEFT --value 1  # key down
        sudo evemu-event "$DEV_INPUT" --type EV_KEY --code KEY_LEFT --value 0  # key up
        sudo evemu-event "$DEV_INPUT" --type EV_SYN --code SYN_REPORT --value 0  # sincronización
    fi
done
