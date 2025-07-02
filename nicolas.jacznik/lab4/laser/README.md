# Comunicación Óptica por Laser – Receptor con Fotoresistencia (ATmega328p)

## Descripción

Este proyecto implementa el **receptor** de un sistema de transmisión de datos por comunicación óptica utilizando un láser y una fotoresistencia (LDR), ambos basados en la plataforma Arduino Nano Pro (ATmega328p). El **programa emisor** (implementado y subido por Jeremías Rodriguez, también en un ATmega328p) utiliza un láser para enviar datos digitales modulando la luz, mientras que el receptor (este proyecto) emplea una fotoresistencia para recibir y decodificar los datos.

## Funcionamiento

- El receptor mide el nivel de luz sobre la LDR para detectar la presencia o ausencia del haz láser.
- Cuando el nivel de luz supera un umbral (`limite`), el receptor interpreta esto como el inicio de la transmisión de un byte.
- A continuación, el receptor toma 8 muestras de la LDR con retardos regulares para reconstruir cada bit del byte recibido.
- Si la señal de stop es válida, el byte se envía por puerto serie al PC.

---

### Comunicación UART asíncrona (imitación de protocolo)

Este proyecto **imita el funcionamiento de un protocolo UART asíncrono** (Universal Asynchronous Receiver-Transmitter):

- La transmisión se realiza sin reloj compartido, sincronizándose únicamente por los tiempos de muestreo acordados entre emisor y receptor.
- Cada byte transmitido consta de un bit de inicio (start), 8 bits de datos y un bit de parada (stop), siguiendo el esquema de UART clásico.
- El tiempo de transmisión de cada bit se define mediante retardos en el código (`_delay_ms(7)` para los bits y `_delay_ms(13)` para la espera entre bytes), que deben coincidir exactamente entre emisor y receptor.
- El canal físico de transmisión es la luz del láser; el receptor detecta los datos interpretando los cambios de luminosidad en la LDR.

---

## Archivos involucrados

- `main.c`
- `adc.c`
- `adc.h`
- `serial.c`
- `serial.h`
- `Makefile`
- `pc.c` (programa de ejemplo para recibir y guardar los datos en la PC)

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Fotoresistencia (LDR):**
  - Un extremo a 5V
  - El otro extremo a A0 (ADC0)
  - Entre A0 y GND, colocar una resistencia fija (por ejemplo 10 kΩ) formando un divisor resistivo.
- **Puerto serie:** Adaptador USB-TTL para comunicación con la PC.
- **Láser emisor:** Apuntado directamente sobre la LDR para máxima fiabilidad.

## Ajuste de parámetros importantes

- **Variable `limite` (en `main.c`):**
  - Define el umbral de luz para detectar el inicio de una transmisión.
  - **Debe ajustarse según la luz ambiente**: si hay mucha luz ambiente, aumentar el valor; si hay poca luz, disminuirlo.
  - Se recomienda probar y ajustar manualmente para máxima confiabilidad según el entorno de uso.

- **Velocidad de transmisión (`_delay_ms(7)` y `_delay_ms(13)` en `main.c`):**
  - Estos retardos controlan el tiempo de muestreo de cada bit y la espera entre bytes.
  - **Deben coincidir exactamente con los valores usados en el programa emisor** para asegurar que los bits sean leídos en el momento correcto.
  - Si se cambia la velocidad en el emisor, debe modificarse aquí también.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** Un programa de terminal serie (como `cutecom`) o el programa `pc.c` para capturar y guardar los datos.

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `laser`.

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

### Uso en la PC

- Puedes usar el programa incluido `pc.c` para leer los datos recibidos por el puerto serie y guardarlos en un archivo (por ejemplo, para transferir imágenes u otros archivos binarios).
- Alternativamente, puedes usar cualquier programa de terminal serie a 9600 bps, 8N1 para monitorear los datos recibidos.

## Video

- Se puede ver una serie de videos del proyecto en ejecución mediante el siguiente enlace: https://drive.google.com/drive/folders/1Q49asss6XuVzDi_paeKP4AYkEDh89DL0?usp=sharing

## Notas adicionales

- La confiabilidad de la recepción depende de la alineación del láser, el umbral de luz (`limite`) y la sincronización de retardos.
- El driver ADC está configurado para referencia AVcc, alineación a la izquierda y prescaler 128.
- El driver serie (`serial.c` y `serial.h`) opera a 9600 bps, 8 bits de datos y 1 bit de stop.
- **Este proyecto solo implementa el receptor. El emisor también está implementado sobre un ATmega328p y debes asegurarte de que ambos programas usen los mismos parámetros de tiempo.**
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`.

2025 – Nicolás Iván Jacznik.