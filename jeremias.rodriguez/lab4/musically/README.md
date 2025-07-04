# Proyecto: Musically

Este proyecto consiste en crear mediante el uso de un knob y un piezo speaker, un dispositivo que reproduzca distintas frecuencias de sonido.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/8tvUrW2.jpeg)

![Imagen de las conexiones](https://i.imgur.com/RKsdgRR.jpeg)

B10k es un potenciometro capaz de generar señales que especifican una posicion particular del mismo. Como se ve en la segunda imagen, el pin izquirdo va a GND, el pin derecho a 5v (Vcc), y el pin central es el que genera la señal. Mediante un cable amarillo se conecta dicho pin con el pin A3 del arduino nano.
Del speaker el cable marron (GND) se conecta al GND y el verde a alguno de los pines GPIO, en este caso D12.

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

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1Z7sLeQU-3TjogVQoIyVJN6225-qUcSiK/view?usp=drive_link)