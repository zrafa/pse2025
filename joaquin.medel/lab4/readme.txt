## Descripción

En este laboratorio se utiliza el **ADC** (Convertidor Analógico a Digital) del ATmega328 para leer señales analógicas
provenientes de un **knob** (potenciómetro) y una **fotoresistencia**.

## Conexiones

- Conectar la salida del knob al pin **PC3** (canal ADC3).
- Conectar la salida de la fotoresistencia al pin **PC4** (canal ADC4).
- Conectar el **speaker** al pin **PB2**.

## Uso

1. Ejecutar:
   make && make flash
      
2. Requisitos:
   - Herramientas necesarias instaladas:
     - make
     - avr-gcc
     - avrdude
   - Conectar el Arduino al puerto serie y asegurarse de que esté **libre y sin uso por otras aplicaciones**.

## Videos

https://drive.google.com/file/d/1ehGyoFbKf8mhNHrUZf4VM5YODiK6bN0F/view?usp=drive_link  
https://drive.google.com/file/d/1IN4hWXZUzaU4BLlTHaruqsqqDlZ3l_Ec/view?usp=drive_link
