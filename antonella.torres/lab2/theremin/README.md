# Proyecto: Medición de distancia con sensor ultrasónico HC-SR04 y generación de sonido con ATmega328P

Este proyecto utiliza un sensor ultrasónico HC-SR04 para medir distancias en centímetros y, según la distancia medida, genera un tono audible en un buzzer piezoeléctrico conectado a un pin digital del microcontrolador ATmega328P. Además, transmite la distancia medida vía comunicación serial UART para monitoreo.

## 1. Configuración de hardware

- Microcontrolador: ATmega328P  
- Sensor HC-SR04:  
  - Pin TRIG conectado a PB3 (pin digital 11 de Arduino)  
  - Pin ECHO conectado a PB2 (pin digital 10 de Arduino)  
- Buzzer piezoeléctrico conectado a PB5 (pin digital 13 de Arduino) para la generación de sonido.  
- Comunicación serial UART conectada a los pines TX y RX según configuración.  
- Alimentación estable a 5V para el microcontrolador, sensor y buzzer.  
- Conexión a computadora mediante programador USB o adaptador serial USB-TTL.

## 2. Descripción funcional

- El sensor HC-SR04 emite pulsos ultrasónicos y mide el tiempo que tarda el eco en regresar para calcular la distancia en centímetros.  
- La función `ultrasound_get_distance()` devuelve la distancia en cm o -1 si no se detecta objeto.  
- El microcontrolador genera un tono cuyo frecuencia está relacionada con la distancia medida.  
- La función `sound(frecuencia, duración)` genera la señal PWM manualmente para el buzzer usando retardos basados en la frecuencia deseada.  
- La distancia medida se envía periódicamente por UART, en formato legible para un monitor serial.

## 3. Software y compilación

- Código desarrollado en C, para compilación con toolchain AVR (`avr-gcc`).  
- Makefile disponible para compilar, generar archivo HEX y flashear el microcontrolador usando `avrdude`.  
- Configuración UART: 9600 baudios, 8 bits de datos, 1 bit de parada, sin paridad.  
- Se usan accesos directos a registros de puerto B para control de pines y generación de señal PWM.  
- El main realiza un ciclo infinito midiendo distancia, enviando por serial y reproduciendo tono.

## 4. Uso

- Conectar y alimentar el hardware según la configuración.  
- Compilar y flashear el programa al ATmega328P.  
- Abrir monitor serial a 9600 baudios para ver las distancias medidas.  
- Escuchar los tonos emitidos por el buzzer: la frecuencia está directamente relacionada con la distancia medida (distancia * 100 Hz).  
- Si no se detecta objeto, el programa continúa esperando y enviando mensajes.

## 5. Notas y recomendaciones

- La precisión del sensor depende del tiempo y calibración de retardos. Se recomienda usar un osciloscopio para verificar señales TRIG y ECHO si es posible.  
- El buzzer debe estar conectado a un pin configurado como salida y capaz de manejar la corriente adecuada.  
- La función `sound()` genera la señal PWM con retardos en microsegundos calculados según la frecuencia deseada.  
- Es posible modificar el mapeo de pines y parámetros UART según hardware específico.  
- Asegurar conexiones firmes y alimentación estable para evitar lecturas erráticas.

---

