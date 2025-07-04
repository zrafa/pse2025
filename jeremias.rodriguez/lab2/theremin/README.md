# Proyecto: Thermin

Este proyecto consiste en recrear el instrumento musical thermin. Para ello, se debe combinar la funcionalidad del piezo speaker con la del sensor de ultrasonido. Como resultado se obtiene un instrumento con el cual el usuario al acercar o alejar la mano del sensor, genera un sonido por el speaker.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/XXXpUIO.jpeg)

![Imagen de las conexiones](https://i.imgur.com/6eTfHD7.jpeg)

![Imagen de las conexiones](https://i.imgur.com/iqJEIxu.jpeg)

Del speaker se conecta el cable negativo (marron, en mi caso) al GND. Mientras que el positivo a alguno de los pines en este caso al D12.
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

Puede ver en los siguientes videos

[VIDEO 1](https://drive.google.com/file/d/1pyHTXG-lZ5gRpm51Qin4oUEvy5V56BAi/view?usp=drive_link)

[VIDEO 2](https://drive.google.com/file/d/1c51ECtmYSt4E88meAyiSAJqCj6gZgnNW/view?usp=drive_link)

[VIDEO 3](https://drive.google.com/file/d/1ezvSEg9h9q9GFavs2sDauQC-8Jd2Corj/view?usp=drive_link)