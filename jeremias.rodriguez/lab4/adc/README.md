# Proyecto: ADC

Este proyecto consiste en crear un driver para el controlador ADC.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/q4XNqqX.jpeg)

![Imagen de las conexiones](https://i.imgur.com/RKsdgRR.jpeg)

B10k es un potenciometro capaz de generar señales que especifican una posicion particular del mismo. Como se ve en la segunda imagen, el pin izquirdo va a GND, el pin derecho a 5v (Vcc), y el pin central es el que genera la señal. Mediante un cable amarillo se conecta dicho pin con el pin A3 del arduino nano.

## Como compilar, flashear y ejecutar

Para compilar este ejercicio debe hacer

```bash
make

make flash
```

Luego, debe correr minicom o cutecom para el USB correspondiente. Con ello poder visualizar la salida.

```bash
minicom
```

Si desea limpiar el programa debe hacer:

```bash
make clean
```

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/19Q8rqPukq3-b9FJbhKTsFk88AbAoDXMe/view?usp=drive_link)