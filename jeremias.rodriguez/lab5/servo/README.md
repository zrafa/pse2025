# Proyecto: Control de servo

Este proyecto consiste en controlar un servo mediante un knob, para que se coloque en la posicion deseada.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/6onB6o4.jpeg)

![Imagen de las conexiones](https://i.imgur.com/BsvonBL.jpeg)

![Imagen de las conexiones](https://i.imgur.com/EUJpwT3.jpeg)

Se conecta el B10K al pin analogico A3. Del servo los cables rojo y negro, van al 5v y GND respectivamente. Mientras que el cable blanco se conecta a la salida D9, la misma transmite la señal con PWM.

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
