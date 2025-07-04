# Proyecto: Gamepad con pulsadores

Este proyecto consiste en crear un gamepad utilizando dos pulsadores. Con ello se debe poder mover a un personaje a izquierda y derecha, mediante la inyeccion de caracteres a un programa intermedio. El cual los debe transferir al programa principal.

## Configuracion de Hardware

![Imagen de las conexiones](https://i.imgur.com/ZKsPScc.jpeg)

Para cada pin se conecta una pata al GND y la otra algun pin. En este caso el pulsador para desplazar a izquierda se conecto con un cable en el pin D10. El pulsador para desplazar a derecha se conecto con un cable al pin D9. El pulsador para saltar se conecto al pin D8.

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
