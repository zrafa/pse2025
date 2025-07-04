# Proyecto: Medir distancia con sensor ultrasonido

Este proyecto consiste en medir la distancia desde el sensor hacia un objeto. Para ello se usa el tiempo de viaje (ida y vuelta) de la onda de ultrasonido.

![Imagen de las conexiones](https://i.imgur.com/6eTfHD7.jpeg)

![Imagen de las conexiones](https://i.imgur.com/iqJEIxu.jpeg)

El dispositivo de ultrasonido HC-SR04 (Utilizado) indica que pines son Vcc GND, Echo y Trig. En este caso conectamos un cable rojo del 5v al pin Vcc. Cable marron de GND al pin GND. Cable amarillo del pin D9 al pin Echos. Cable azul del pin D8 al pin Trig.

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

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1DUhfNGxCaUoLyCXEuqqAmlVnfQbmLsA-/view?usp=drive_link)