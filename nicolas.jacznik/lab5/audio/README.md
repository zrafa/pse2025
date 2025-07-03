# Audio Digital por PWM – Reproducción de Audio WAV vía ATmega328p

## Descripción

Este proyecto implementa la reproducción de audio digital (archivos WAV) usando un Arduino Nano Pro (ATmega328p) y modulación por ancho de pulso (PWM). El audio es enviado desde una PC por el puerto serie (UART) a alta velocidad y el microcontrolador lo reproduce usando Timer1 en modo Fast PWM. El sistema permite escuchar archivos WAV de 8 bits, mono, a frecuencias como 8000 Hz u 11025 Hz, utilizando un simple filtro RC y un pequeño altavoz o auricular.

## Funcionamiento

- **En la PC**  
  Se ejecuta un programa (`emisorPC.c` o `pc.c`) que lee un archivo WAV, ignora la cabecera y envía los datos de audio byte a byte por el puerto serie (por ejemplo, `/dev/ttyUSB0`) a **115200 baudios**.
- **En el Arduino**  
  El microcontrolador recibe cada byte por UART y lo carga a Timer1, que genera una señal PWM proporcional a la muestra recibida. El PWM se filtra analógicamente (filtro RC) y se conecta a un parlante.
- El ciclo de audio se mantiene a la frecuencia de muestreo seleccionada (por ejemplo, 8000 Hz o 11025 Hz; configurable en el código de la PC y del micro).

## Archivos involucrados

- `main.c`: Código principal para ATmega328p (receptor y reproductor de audio).
- `timer1.c`/`timer1.h`: Configuración de Timer1 y actualización de muestras PWM.
- `serial.c`/`serial.h`: Comunicación UART a 115200 baudios.
- `emisorPC.c` y `pc.c`: Programas en C para enviar archivos WAV desde la PC al Arduino.
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Salida de audio:**  
  - Pin D9 (PB1/OC1A) → Filtro RC pasa bajos → Amplificador o parlante/auricular.
- **PC ↔ Arduino:**  
  - Adaptador USB-TTL a 115200 baudios, 8N1.
- **Alimentación:**  
  - 5V y GND según Arduino y parlante.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** GCC (para compilar los programas emisores), archivo WAV de 8 bits (mono), y permisos para acceder al puerto serie.

### Compilar el programa para Arduino

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `audio`.

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

### Compilar y usar el emisor de audio en la PC

1. Compila el emisor:

   ```sh
   gcc emisorPC.c -o emisorPC
   ```

   o

   ```sh
   gcc pc.c -o pc
   ```

2. Prepara tu archivo WAV (mono, 8 bits, por ejemplo, `ratatouille.wav` o `salida.wav`).
3. Ejecuta el emisor (ajusta el nombre del archivo y el puerto si es necesario):

   ```sh
   ./emisorPC
   ```

   o

   ```sh
   ./pc
   ```

   El programa enviará el audio por el puerto serie al Arduino, que lo reproducirá.

## Detalles de implementación

- **Baudios:** 115200 (se debe ajustar igual en la PC y el Arduino).
- **Frecuencia de muestreo:** Determinada por el retardo en el emisor (por ejemplo, `usleep(125)` ≈ 8000 Hz).
- **PWM:** Timer1, modo Fast PWM, frecuencia de actualización 11025 Hz por defecto (ajustable).
- **Mapeo de muestra:** Cada byte recibido se escala al rango del PWM para obtener la amplitud correspondiente.
- **Filtro RC:** Recomendado para suavizar la señal PWM antes del parlante.

## Video

- Se puede ver un video del programa en ejecución mediante el siguiente enlace: https://drive.google.com/file/d/1qZqGPI0hGk5XLXNKTk9zMRkC2Gol4z8m/view?usp=sharing

## Notas adicionales

- El audio debe estar en formato WAV, mono, 8 bits sin compresión.
- El archivo de audio se transmite sin la cabecera WAV (los primeros 44 bytes se descartan en el emisor).
- Puedes modificar el código para soportar diferentes frecuencias de muestreo, aumentar la resolución del PWM, o mejorar la calidad del audio.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.

2025 – Nicolás Iván Jacznik.