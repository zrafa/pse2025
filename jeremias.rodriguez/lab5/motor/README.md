# Proyecto: Motor de corriente continua

Este proyecto consiste en controlar un motor mediante una señal PWM.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/eA3Zxmn.jpeg)

![Imagen de las conexiones](https://i.imgur.com/6rVMkJA.jpeg)

![Imagen de las conexiones](https://i.imgur.com/EoSqQmr.jpeg)

Se conecta la placa L293 al centro de la protoboard, la misma permitira convertir señales de un pin GPIO a voltages de 4.5v. 
Teniendo en cuenta la marca que semicircular que tiene a la izquierda el L293 en la primera imagen, esa entrada es la 1. La entrada 1 se conecta al 5v. La entrada 8 se conecta a un pin GPIO que controle el start o stop del motor. Las entradas 2 y 7 controlan las input de señal depende de si es 01 o 10, se envia el motor gira a izquierda o derecha. Las entradas 3 y 6 controlan la salida. Las entradas 4 y 5 son para conectar un GND.
Ademas, se agrega un pulsador para hacer que el motor gire a izquierda, derecha o se detenga.

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

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1zAII-XUGuvgzr4LclapGcaEKC4Z3XjBh/view?usp=drive_link)
