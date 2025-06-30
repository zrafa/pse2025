# Control de LED con Pulsador en Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto permite encender y apagar un LED mediante un pulsador utilizando una placa Arduino Nano Pro basada en el microcontrolador ATmega328p. El programa configura el pin PB4 (pin digital 12) como entrada con pull-up interno activado, y el pin PB5 (pin digital 13) como salida para controlar el LED. Cada vez que se presiona el pulsador conectado al pin 12, el LED conectado al pin 13 cambia de estado (enciende o apaga). El código incluye una rutina sencilla de debounce por software.

## Archivos involucrados

- `main.c`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **LED:** Conectar el ánodo del LED al pin digital 13 (PB5) a través de una resistencia de 220 Ω; el cátodo a GND.
- **Pulsador:** Conectar un extremo del pulsador al pin digital 12 (PB4) y el otro extremo a GND.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `contador-binario`.

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

- Al cargar el programa, el LED conectado al pin 13 se encenderá o apagará cada vez que se presione el pulsador conectado al pin 12.
- El programa utiliza un retardo por software para evitar el efecto rebote (debounce) del pulsador.

## Notas adicionales

- Se accede a los registros de control y datos de PORTB directamente para manipular la entrada y salida de los pines.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Puedes modificar el código para usar otros pines cambiando los números de bit correspondientes.

2025 – Nicolás Iván Jacznik.