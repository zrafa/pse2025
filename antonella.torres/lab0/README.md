# Lab0 - Mastering

## Descripción
Este proyecto dibuja texto en pantalla utilizando caracteres ASCII y un buffer de resolución fija. El texto se renderiza en un área de 80 columnas por 24 filas, y utiliza una fuente intercambiable para representar los caracteres.

El proyecto tiene dos implementaciones:
1. **Implementación básica**: Usa índices para acceder al buffer.
2. **Implementación con punteros**: Usa punteros para manipular directamente el buffer, optimizando el acceso a memoria.

---

## 1. Configuración del hardware
Este proyecto no requiere hardware específico, ya que está diseñado para ejecutarse en un entorno de simulación o directamente en una computadora. No hay conexiones físicas entre dispositivos.

---

## 2. Cómo compilar, ejecutar y usar

### Compilación
Asegurese de tener instalado un compilador de C, como `gcc`.

#### Implementación básica
-Navega a la carpeta del proyecto: 
    cd pse2025/lab0/ej10arreglo
    o
    cd pse2025/lab0/ej10punteros

Compila el programa utilizando el Makefile:
    make

Si se desea eliminar los archivos generados utiliza el comando:
    make clean

#### Ejecución
Ejecuta el programa desde la terminal, proporcionando al menos un argumento de texto:
    ./lab0-mastering "Hola mundo"
También esta la opcion de agregar otro argumento 
    ./lab0-mastering "Hola mundo" "Texto adicional"

## 3. Configuración del software
Parámetros configurables
Texto a mostrar:
El texto se pasa como argumento al programa. Se puede cambiar en cada ejecución




