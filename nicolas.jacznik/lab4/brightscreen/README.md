# Fotoresistencia – Lectura de Sensor Analógico y Control de Brillo por Serial en Arduino Nano Pro (ATmega328p)

## Descripción

Este proyecto permite medir el valor de una fotorresistencia (sensor LDR) conectada al pin analógico 0 (ADC0) de un Arduino Nano Pro (ATmega328p). El valor leído se envía por puerto serie a la PC cada 500 ms. En la PC, un script en bash lee el valor recibido y lo utiliza para ajustar automáticamente el brillo de la pantalla mediante `brightnessctl`, creando así un control de brillo ambiental automático y sencillo.

## Archivos involucrados

- `main.c`
- `adc.c`
- `adc.h`
- `serial.c`
- `serial.h`
- `Makefile`
- `script.sh` (lector y controlador de brillo en la PC)

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Fotorresistencia (LDR):** 
  - Un extremo al pin A0 (ADC0)
  - El otro extremo a 5V
  - Entre A0 y GND, colocar una resistencia fija (por ejemplo, 10 kΩ) para formar un divisor resistivo.
- **Puerto serie:** Utiliza un adaptador USB-TTL para la comunicación serie con la PC.

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** bash, `brightnessctl` y permisos para modificar el brillo de la pantalla.

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable `brightscreen`.

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

### Uso del script en la PC

1. Conecta el Arduino y asegúrate de que el puerto serie esté disponible (por ejemplo, `/dev/ttyUSB0`).
2. Da permisos de ejecución al script:

   ```sh
   chmod +x script.sh
   ```

3. Ejecuta el script con privilegios (necesario para controlar brillo y leer el puerto):

   ```sh
   sudo ./script.sh
   ```

   El script leerá los valores enviados por el Arduino y ajustará el brillo de pantalla de forma inversa (a mayor luz, menor brillo).

## Uso

- El sistema mide el valor analógico del pin A0 cada 500 ms y lo envía por serie en formato numérico.
- El script de la PC lee el valor y ajusta el brillo automáticamente.
- Puedes observar en la terminal el valor recibido y el cambio de brillo reportado por `brightnessctl`.

## Video

- Se puede ver un video del programa en ejecución mediante el siguiente enlace: https://drive.google.com/file/d/1dtPZTfkGgeHKJ96C1lcWHb1FY_EZ3EVs/view?usp=sharing

## Notas adicionales

- El ADC está configurado para trabajar con referencia AVcc y alineación a la izquierda, facilitando la transmisión de 8 bits más significativos.
- El driver serie (`serial.c` y `serial.h`) configura el UART a 9600 bps, 8 bits de datos y 1 bit de stop.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Puedes modificar el script para invertir la lógica de brillo, escalar valores, o agregar más acciones automáticas según el sensor.

2025 – Nicolás Iván Jacznik.