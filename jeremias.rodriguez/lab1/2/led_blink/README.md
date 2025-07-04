# Proyecto: Enciende y apaga un led

Este proyecto sirve como introduccion para comprender como funciona la programacion del atmega328.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/Q2NWJVp.jpeg)

Se conecta la pata corta del led a gnd, y la otra a una resistencia. Luego se coloca el cable azul a la otra pata de la resistencia. La otra parte del cable a un pin B 5 (D13).

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

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1vlPz9z_MZC13O_RIsEUpBdbQUEMTZcfn/view?usp=sharing)