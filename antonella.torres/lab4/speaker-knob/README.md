# Speaker Knob - Lab4
## Descripción
Este proyecto permite controlar la frecuencia de un sonido generado por un buzzer o parlante piezoeléctrico usando un potenciómetro conectado a una entrada analógica del microcontrolador ATmega328P. El valor leído por el ADC ajusta la frecuencia del sonido, permitiendo usar el potenciómetro como un "knob" de control.

## 1. Configuración del hardware
Microcontrolador: ATmega328P (Arduino Nano, Uno, etc.)
Potenciómetro:
Un extremo a 5V
El otro extremo a GND
El pin central (wiper) a ADC0 (pin PC0)
Buzzer o parlante piezoeléctrico:
Un pin a PB5 (pin digital 13 en Arduino)
El otro pin a GND

## 2. Cómo compilar, flashear y ejecutar
Compilación
Asegúrate de tener instalado avr-gcc y make.
Navega a la carpeta del proyecto
Compila el proyecto:
make
Flasheo
Conecta tu placa al puerto USB.
Flashea el microcontrolador:
make flash
(Asegúrate de que el Makefile tenga configurado el puerto y programador correctos.)

Ejecución
El programa comenzará a ejecutarse automáticamente después de flashear.
Gira el potenciómetro y escucha cómo cambia la frecuencia del sonido en el buzzer.

## 3. Configuración del software
Canal ADC: El potenciómetro debe estar conectado a ADC0 (PC0).
Pin de salida: El buzzer está conectado a PB5.
Rango de valores: El valor leído del ADC se invierte (val = 255 - val) para que al girar el potenciómetro en una dirección aumente la frecuencia y en la otra la disminuya.
Función de sonido: Si el valor es mayor a 3, la frecuencia es proporcional al valor del ADC; si es menor o igual a 3, se usa una frecuencia mínima.

## 4. Ejemplo de uso
Gira el potenciómetro.
El buzzer cambiará la frecuencia del tono según la posición del potenciómetro.
Si el potenciómetro está al mínimo, se genera un tono bajo constante.
