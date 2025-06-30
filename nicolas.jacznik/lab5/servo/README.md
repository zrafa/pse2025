# Control de Servo con Potenciómetro (ATmega328p)

## Descripción

Este proyecto implementa el control de un servo motor mediante un potenciómetro utilizando un Arduino Nano Pro (ATmega328p). El usuario puede girar el potenciómetro y el ángulo del servo se ajusta proporcionalmente. El proyecto utiliza el Timer1 en modo Fast PWM para generar la señal adecuada para el servo y el ADC para leer el valor del potenciómetro. Además, se envía por UART el valor leído del ADC y el pulso de PWM generado, lo que facilita la depuración y visualización en una terminal serie.

## Funcionamiento

- El ADC lee el valor del potenciómetro conectado al pin A0 (rango 0-255).
- El valor leído se traduce a un pulso PWM (entre aproximadamente 700 y 3500 ticks para un servo típico, configurable).
- El PWM es generado por el Timer1 en modo Fast PWM, canal OC1A (pin PB1, Arduino Nano: D9).
- El valor del ADC y el ciclo de trabajo PWM se envían por UART para monitoreo en PC.
- El ciclo se repite continuamente con un retardo de 50 ms.

## Archivos involucrados

- `main.c`
- `adc.c`
- `adc.h`
- `serial.c`
- `serial.h`
- `timer1_pwm.c`
- `timer1_pwm.h`
- `Makefile`

## Conexiones

- **Placa:** Arduino Nano Pro (ATmega328p, 16 MHz)
- **Potenciómetro:**
  - Un extremo a 5V
  - El otro extremo a GND
  - Pin central (wiper) a A0 (ADC0)
- **Servo motor:**
  - Cable de señal a D9 (PB1/OC1A)
  - Vcc y GND según especificación del servo (normalmente 5V y GND)
- **Puerto serie:** Adaptador USB-TTL para comunicación con la PC (por ejemplo, `/dev/ttyUSB0`).

## Compilación, carga y ejecución

### Requisitos

- **Toolchain AVR:** `avr-gcc`, `avr-objcopy`, `avrdude`
- **En la PC:** Un programa de terminal serie (por ejemplo, `cutecom`, `minicom`, `screen`, `PuTTY`) configurado a 9600 bps, 8N1.

### Compilar el programa

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:

   ```sh
   make
   ```

   Esto generará el archivo ejecutable (por ejemplo, `servo` o `main` según el Makefile).

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

1. Alimenta el Arduino y conecta el servo y el potenciómetro según el esquema.
2. Gira el potenciómetro y observa cómo el ángulo del servo varía suavemente conforme al valor leído.
3. Abre una terminal serie a 9600 bps para observar los valores de ADC y PWM que el programa envía, útil para calibración o depuración.

## Detalles de implementación

- **Timer1 en modo Fast PWM:** Se configura con un TOP de 39999 para obtener una frecuencia de 50 Hz, adecuada para servos estándar.
- **Mapeo de ADC a PWM:** El valor de ADC (0-255) se mapea linealmente a un rango de pulsos (700-3500 ticks, ajustable según el servo).
- **Salida UART:** Permite ver en la PC los valores en tiempo real para facilitar el ajuste del rango de PWM.
- **Drivers modulares:** El ADC, PWM y comunicación serie están implementados como módulos independientes y reutilizables.

## Notas adicionales

- Puedes ajustar el rango de PWM (`duty`) en el código para adaptarlo a diferentes modelos de servos.
- El archivo `Makefile` incluye reglas para compilar, generar el archivo HEX y programar el microcontrolador usando `avrdude`. Verifica que el puerto y la velocidad sean correctos para tu sistema.
- Si el servo vibra o no responde bien, verifica la alimentación y el rango de ticks en la fórmula del duty.

2025 – Nicolás Iván Jacznik.