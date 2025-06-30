# Knob Digital – Síntesis de Frecuencia Controlada por Potenciómetro (ATmega328p)

## Descripción

Este proyecto implementa un "knob digital" usando un Arduino Nano Pro (ATmega328p). Utiliza el ADC para leer la posición de un potenciómetro (o cualquier entrada analógica) conectado al pin A0 y genera una señal sonora en un buzzer o parlante piezoeléctrico conectado al pin digital 13 (PB5). La frecuencia del tono varía en tiempo real según la posición del potenciómetro, simulando el comportamiento de un generador de tonos controlado por perilla.

## Archivos involucrados

- `main.c`
- `adc.c`
- `adc.h`
- `serial.c`
- `serial.h`
- `sound.c`
- `sound.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Potenciómetro:**
  - Un extremo a 5V
  - El otro extremo a GND
  - Pin central (wiper) a A0 (ADC0)
- **Buzzer o parlante:** Positivo a pin digital 13 (PB5), negativo a GND.
- **Puerto serie:** No se utiliza activamente en este ejemplo, pero el driver está disponible para pruebas.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `knob`.

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

- Ajusta la posición del potenciómetro. El tono emitido por el buzzer variará en frecuencia de acuerdo a la lectura analógica.
- Si el valor leído es bajo (potenciómetro hacia GND), se emite un tono grave; si es alto (hacia 5V), se emite un tono agudo.
- El sistema lee el valor y actualiza la frecuencia de forma continua.

## Notas adicionales

- El ADC está configurado con referencia AVcc, alineación a la izquierda, y prescaler 128 para mayor precisión.
- La función `sound()` genera un tono cuadrado usando retardos de microsegundos.
- Puedes ajustar la fórmula de mapeo entre el valor analógico y la frecuencia para obtener diferentes rangos o efectos.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.

2025 – Nicolás Iván Jacznik.