# Proyecto: Contador binario con leds

Este proyecto consiste en crear un contador binario mediando luces leds. El mismo debe detenerse cuando se presiona un pulsador, y debe continuar cuando vuelve a presionarse.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/eeqtYig.jpeg)

![Imagen de las conexiones](https://i.imgur.com/eF4pok4.jpeg)

![Imagen de las conexiones](https://i.imgur.com/NqsfsfL.jpeg)

Se conecta la pata corta del led a gnd, y la otra a una resistencia. Luego se coloca el cable azul a la otra pata de la resistencia. La otra parte del cable a un pin B 5 (D13). Ademas, se conecta un pulsador al pin D9 y su segunda pata a GND.

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

Puede ver en el siguiente [VIDEO](
https://drive.google.com/file/d/1jgjxhd4m-wsh-DNO-zi5_3AYDl93gmWp/view?usp=drive_link)