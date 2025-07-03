# Control de Motor y LED por PWM usando Timer2 y ADC
Descripción
Este proyecto permite controlar la velocidad de un motor DC y el brillo de un LED utilizando un potenciómetro (knob) conectado a una entrada analógica del ATmega328P. El valor leído por el ADC se convierte a un valor de ciclo de trabajo (duty cycle) PWM, que se aplica a las salidas OC2A (PB3) y OC2B (PD3) mediante Timer2. Además, los valores de ADC y PWM se envían por UART para monitoreo.

## 1. . Configuración del hardware
Microcontrolador: ATmega328P (Arduino Nano, Uno, etc.)
Potenciómetro (knob):
Un extremo a 5V
El otro extremo a GND
Pin central (wiper) a ADC2 (pin PC2)
Motor DC:
Controlado por PB3 (OC2A, pin digital 11 Arduino) mediante un transistor o puente H.
LED:
Conectado a PD3 (OC2B, pin digital 3 Arduino) con resistencia limitadora.
UART:
TX del microcontrolador a RX del conversor USB-Serial o PC
GND común


## 2. Cómo compilar, flashear y ejecutar
Compilación
Asegúrate de tener instalado avr-gcc y make.
Navega a la carpeta del proyecto.
Compila el proyecto: make
Flasheo
Conecta tu placa al puerto USB.
Flashea el microcontrolador: make flash 
(Asegúrate de que el Makefile tenga configurado el puerto y programador correctos.)

Ejecución
El programa comenzará a ejecutarse automáticamente después de flashear.
El duty cycle de las salidas PWM puede ser ajustado desde el software llamando a timer2_set_duty_a(valor) o timer2_set_duty_b(valor).

## 3. Configuración del software
ADC: Lee el valor del potenciómetro en el canal ADC2 (PC2).
PWM: Timer2 genera señales PWM de 8 bits (~976 Hz) en OC2A (PB3) y OC2B (PD3).
UART: Muestra el valor del ADC y el duty actual cada 100 ms.


## 4. Salida
Se podra observar como al mover el knob tanto el led como el motor aumentan o disminuyen su potencia