# Proyecto: Piano

Este proyecto consiste en crear un piano utilizando el piezo speaker al presionar una tecla del teclado.

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

Luego, debe correr minicom o cutecom para el USB correspondiente.

```bash
minicom
```

Una vez hecho, pulsando las teclas de A, S, D, F, G, H, J. Obtendra una nota de un piano.

Si desea limpiar el programa debe hacer:

```bash
make clean
```

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1MUNGd7Shmk0w_4-49sPK0lx3rJwtVjeH/view?usp=drive_link)