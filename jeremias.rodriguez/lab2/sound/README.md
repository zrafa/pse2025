# Proyecto: Generar sonido

Este proyecto consiste en desarrollar un programa que genere un sonido con una frecuencia y una duracion a traves de un piezo speaker.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/8tvUrW2.jpeg)

![Imagen de las conexiones](https://i.imgur.com/Xingvsu.jpeg)

Se conecta el cable negativo (marron, en mi caso) al GND. Mientras que el positivo a alguno de los pines en este caso al D12.

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

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1rvnf2R8l1VB0nn0iGoA8GzR8f3QPIRl5/view?usp=drive_link)