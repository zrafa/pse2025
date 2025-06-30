# Secuencia de LEDs estilo Knight Rider con Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto controla una secuencia de encendido y apagado de LEDs conectados al puerto B del microcontrolador ATmega328p, presente en la placa Arduino Nano Pro. El objetivo es imitar la animación luminosa de la serie "Knight Rider" (El Auto Fantástico), donde una luz se desplaza de un lado a otro, creando un efecto visual dinámico sobre los LEDs conectados a los pines digitales 8 a 13 del Arduino (bits 0-5 de PORTB).

## Archivos involucrados

- `main.c`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **LEDs:** Conectar hasta 6 LEDs (con resistencias de 220 Ω) a los pines digitales 8–13 del Arduino Nano Pro. El otro extremo de cada resistencia debe ir a GND.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `knight-rider`.

### Generar archivo HEX y grabar en el Arduino Nano Pro

1. Conecta la placa Arduino Nano Pro a la PC (ajusta `/dev/ttyUSB0` si es necesario).
2. Ejecuta:

   ```sh
   make flash
   ```

   Esto convertirá el binario a formato Intel HEX y lo grabará en la placa usando `avrdude`.

3. Para limpiar los archivos generados:

   ```sh
   make clean
   ```

## Uso

- Una vez cargado el programa, los LEDs conectados a los pines 8–13 del Arduino Nano Pro se encenderán y apagarán siguiendo una secuencia que simula el efecto de la luz de Knight Rider, desplazándose de un extremo al otro y volviendo.
- El retardo entre pasos se realiza por software usando un bucle vacío.

### Personalización

- Puedes modificar el arreglo `ledPos` en el código para experimentar con diferentes patrones de animación y velocidad.

## Notas adicionales

- Se accede a los registros de control y datos de PORTB directamente para manipular la salida de los pines.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- El retardo de la animación puede ajustarse cambiando el valor del bucle en el código.

2025 – Nicolás Iván Jacznik.