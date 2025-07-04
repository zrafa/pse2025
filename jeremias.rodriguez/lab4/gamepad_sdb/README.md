# Proyecto: Gamepad con knob y pulsador

Este proyecto consiste en crear un gamepad con un knob y un pulsador para controlar el juego sdl ball

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/tGHXqbR.jpeg)

![Imagen de las conexiones](https://i.imgur.com/RKsdgRR.jpeg)

B10k es un potenciometro capaz de generar señales que especifican una posicion particular del mismo. Como se ve en la segunda imagen, el pin izquirdo va a GND, el pin derecho a 5v (Vcc), y el pin central es el que genera la señal. Mediante un cable amarillo se conecta dicho pin con el pin A3 del arduino nano.
Se conecta el pulsador a un pin (D12 en este caso) y a GND.

## Como compilar, flashear y ejecutar

Para compilar este ejercicio debe hacer

```bash
make

make flash
```

Si desea limpiar el programa debe hacer:

```bash
make clean
```

Ejecute el sdl-ball que se encuentra en este mismo lab.

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/18vWfeZIXASVO6kgaO2Xho9cXHyo0x9ik/view?usp=sharing)