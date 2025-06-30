# Theremin Digital con Sensor Ultrasónico y Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto implementa un "theremin digital" utilizando un Arduino Nano Pro (ATmega328p) y un sensor ultrasónico HC-SR04. El sistema mide la distancia de un objeto (por ejemplo, la mano del usuario) frente al sensor y reproduce un sonido cuya frecuencia depende de esa distancia, generando un efecto musical similar al de un theremin tradicional. Además, la distancia medida se muestra por puerto serie en centímetros.

## Archivos involucrados

- `main.c`
- `ultrasound.c`
- `ultrasound.h`
- `serial.c`
- `serial.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Sensor HC-SR04:**
  - Echo: Pin digital 10 (PB2)
  - Trigger: Pin digital 11 (PB3)
  - VCC y GND: a 5V y GND del Arduino
- **Buzzer o parlante:** Positivo al pin digital 13 (PB5), negativo a GND.
- **Puerto serie:** Utilizar adaptador USB-TTL si se desea visualizar la distancia por terminal serie.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `theremin`.

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

- Al cargar el programa, acerca o aleja tu mano frente al sensor ultrasónico. El buzzer emitirá un tono cuya frecuencia varía según la distancia detectada.
- La distancia detectada se envía por puerto serie en centímetros para monitoreo en una terminal.
- Si no hay objeto detectado, la función retorna -1 y no suena el buzzer.

### Personalización

- Puedes modificar la función `sound()` para cambiar la relación entre distancia y frecuencia, o ajustar la duración de las notas.
- El sistema puede adaptarse para diferentes rangos o efectos musicales editando los parámetros en el código.

## Notas adicionales

- El sensor ultrasónico HC-SR04 se controla directamente accediendo a los registros de PORTB.
- El driver de comunicación serie (`serial.c` y `serial.h`) configura el UART para 9600 bps, 8 bits de datos y 1 bit de stop, permitiendo el envío de texto a una terminal serie estándar.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- El código es fácilmente extensible para agregar más funcionalidades o adaptar a otros microcontroladores AVR.

2025 – Nicolás Iván Jacznik.