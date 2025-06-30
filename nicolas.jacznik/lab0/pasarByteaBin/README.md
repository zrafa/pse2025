# Visualización de un Byte en Binario

## Descripción

Este proyecto presenta un programa en C que muestra la representación binaria de un byte en consola. Es útil para comprender la manipulación de bits y cómo se puede visualizar el contenido de variables a nivel binario, lo que resulta relevante en sistemas embebidos y programación de bajo nivel.

## Archivos involucrados

- `program.c`

## Compilación y ejecución

### Usando gcc

1. Abre una terminal en la carpeta del proyecto.
2. Compila el programa:

   ```sh
   gcc program.c -o program
   ```

3. Ejecuta el programa:

   ```sh
   ./program
   ```

## Uso

- El programa define un byte de ejemplo (`0b10111110`) y lo imprime por consola en su representación binaria.
- Puedes modificar el valor de la variable `byte` en el código para visualizar otros valores.

### Ejemplo de salida

```
Representación binaria: 10111110
```

## Notas adicionales

- La función `printBinary` recorre cada bit, del más significativo al menos significativo, e imprime su valor.

2025 – Nicolás Iván Jacznik.