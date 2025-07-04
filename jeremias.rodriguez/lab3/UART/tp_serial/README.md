# Proyecto: UART

Este proyecto consiste en definir un driver para el periferico UART. Ademas, incluye un test de la funcionalidad.

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

Una vez hecho, si pulsa teclas se enviaran mediante USB al atmega328. El cual respondera con la misma tecla.

Si desea limpiar el programa debe hacer:

```bash
make clean
```

## USO

Puede ver en el siguiente [VIDEO](https://drive.google.com/file/d/1K-okBaMUYg2pQgvsZgUKQ35KaB--FjE3/view?usp=drive_link)