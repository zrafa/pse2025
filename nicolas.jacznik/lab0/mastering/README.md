# Renderizado de Texto ASCII con Font Intercambiable

## Descripción

Este proyecto implementa una rutina para renderizar texto usando caracteres ASCII sobre un buffer de memoria, utilizando un font intercambiable. El objetivo es practicar el manejo de arreglos, memoria y presentación de información, como parte de la materia de Sistemas Embebidos.  
El código permite imprimir texto en posiciones arbitrarias dentro de un "frame buffer" simulado y visualizarlo por consola. Se incluyen dos variantes de implementación del mismo concepto (`lab0-mastering.c` y `lab0-mastering-arreglos.c`).

## Archivos involucrados

- `lab0-mastering.c`
- `lab0-mastering-arreglos.c`
- `font.h`
- `Makefile`

## Compilación y ejecución

### Usando Make

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto compilará `lab0-mastering.c` y generará el ejecutable `lab0-mastering`.

3. Para limpiar los archivos generados:

   ```sh
   make clean
   ```

### Compilación manual

Si prefieres compilar alguno de los archivos manualmente:

```sh
gcc lab0-mastering.c -o lab0-mastering
gcc lab0-mastering-arreglos.c -o lab0-mastering-arreglos
```

### Ejecución

Ejecuta el programa pasando el texto a renderizar como argumento:

```sh
./lab0-mastering "Texto a mostrar"
# o con dos líneas:
./lab0-mastering "Linea 1" "Linea 2"
```

## Uso

- El programa toma uno o dos argumentos de línea de comando (el texto a renderizar).
- Renderiza el texto en el buffer y lo muestra en consola usando caracteres ASCII.
- Cada letra ocupa un área de 6x8 "píxeles" (5x7 más un espacio).
- Puedes modificar el font en `font.h` para cambiar la apariencia de los caracteres.

### Ejemplo de uso

```sh
./lab0-mastering "Hola Mundo"
```
Esto imprimirá en la consola el texto "Hola Mundo" usando el font definido.

## Notas adicionales

- Los archivos `lab0-mastering.c` y `lab0-mastering-arreglos.c` son variantes funcionales, prueba ambos para comparar diferencias en la implementación.
- El archivo `font.h` contiene una tabla de font tipo 5x7, fácilmente editable o reemplazable por otro font compatible.

2025 – Nicolás Iván Jacznik.