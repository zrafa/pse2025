## Descripción

En este laboratorio se utilizó un **speaker** para generar sonido mediante vibraciones, y un **sensor de ultrasonido** para 
medir distancias. La distancia medida se envía por **comunicación serial**.

Además, se utilizó un **delay personalizado**, el cual fue calibrado utilizando un **osciloscopio** para ajustar
con precisión los tiempos de espera. Es importante tener en cuenta que los valores de calibración
pueden variar dependiendo del microcontrolador utilizado.

## Conexiones

- Speaker conectado al pin **PB2**.
- Sensor de ultrasonido conectado a los pines **PB0** y **PB1**.

## Uso

1. Requisitos:
   - Herramientas necesarias:
     - make
     - avr-gcc
     - avrdude
     - picocom
   - Conectar el Arduino al puerto serie y asegurarse de que esté **libre y sin uso por otras aplicaciones**.

2. Compilar y flashear el firmware:
   make && make flash


3. Dar permisos de ejecución al script de apertura serial y ejecutarlo:
   chmod +x abrir_serial.sh
   ./abrir_serial.sh
   

## Videos

https://drive.google.com/file/d/15KAyrdvVb37lqUzJetfWaarT1HvtJnSn/view?usp=drive_link  
https://drive.google.com/file/d/1-w4-qLsxRpSc6vp7sEya3d5_uQ1_rtXM/view?usp=drive_link
