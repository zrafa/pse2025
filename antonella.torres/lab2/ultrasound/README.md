# Proyecto: Medición de distancia con sensor ultrasónico HC-SR04 y comunicación serial con ATmega328P

Este proyecto utiliza el sensor ultrasónico HC-SR04 para medir distancias en centímetros y comunica las mediciones vía serial al computador o dispositivo receptor.

## 1. Configuración de hardware

- Microcontrolador: ATmega328P  
- Sensor HC-SR04:  
  - Pin TRIG conectado a PB0 (pin digital 8 de Arduino)  
  - Pin ECHO conectado a PB1 (pin digital 9 de Arduino)  
- VCC y GND: a 5V y GND del Arduino 
- Conexión a la computadora mediante programador USB.

## 2. Cómo compilar, flashear y ejecutar

- Compilar usando avr-gcc con las opciones adecuadas para ATmega328P y frecuencia 16 MHz.  
- Usar Makefile con comandos:  
  make  
  make flash  
  make clean  

- Flashear con avrdude en el puerto serie adecuado (/dev/ttyUSB0 u otro), con programador tipo arduino.  
- Para monitorear las mediciones, conectar un monitor serial en la computadora a 9600 baudios (o la velocidad configurada en serial_init).
- Cada un segundo mide la distancia al objeto mas cercano y 
enviará la información por puerto serie en el formato: Distancia : xxx

## 3. Configuración de software

- Inicializar el sensor con init_ultrasound().  
- Obtener distancia en cm con ultrasound_get_distance(), que devuelve -1 si no detecta objeto.  
- El programa principal envía por serial la distancia medida cada segundo.  
- La función serial_init() debe configurarse para la velocidad y parámetros de UART correctos.  
- Se puede modificar la función esperar() o los tiempos en el código para ajustar la precisión.

## 4. Video demostración

[Enlace al video de demostración]

---

