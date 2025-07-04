# Proyecto: Fotoresistencia

Este proyecto consiste en crear un receptor de luz de ambiente usando una fotoresistencia, y con ello modificar el brillo de la computadora.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/9T1aGrL.jpeg)

![Imagen de las conexiones](https://i.imgur.com/7Xrh4bZ.jpeg)

Se conecta la fotoresistencia en alguna parte de la protoboard. En la misma linea que una de las patas al 5v. La linea de la otra pata, tendra una resistencia en medio y luego una conexion a un pin de entrada analogica (En este caso A3). La otra pata de la resistencia debe estar conectada a GND.

## Como compilar, flashear y ejecutar

Para compilar este ejercicio debe hacer

```bash
make

make flash
```

Abra minicom o cutecom, y podra ver la entrada que recibe de la fotoresistencia.

Si desea limpiar el programa debe hacer:

```bash
make clean
```

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1oDoSJucBqXrfBYZRafLNGDYPNeYErdtD/view?usp=drive_link)