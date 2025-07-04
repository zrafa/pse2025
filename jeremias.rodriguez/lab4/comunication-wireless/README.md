# Proyecto: Comunicacion wireless

Este proyecto consiste en crear un transmisor de señal para enviar un texto a otro arduino no conectado. A partir del uso de un laser y un receptor. Esta parte es el transmisor.

## Configuracion de Hardware

En la siguiente imagen puede observar las conexiones del hardware:

![Imagen de las conexiones](https://i.imgur.com/S8aSYfg.jpeg)

Se conecta el cable azul a GND. Y el cable rojo al pin con el que enviaremos la señal, en este caso D12.

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

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1bOI1zSsFJ6ERJX9toYF9puQF94milxNu/view?usp=drive_link)