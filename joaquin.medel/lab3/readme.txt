## Descripción

En este laboratorio se trabajó con la comunicación **serial**, configurando el driver para enviar un solo byte desde el microcontrolador.

## Conexiones

- Conectar el **speaker** al pin **PB2**.
- Conectar el **botón derecho** al pin **PC0**.
- Conectar el **botón izquierdo** al pin **PC1**.

## Uso

1. Requisitos:
   - Tener instaladas las siguientes herramientas:
     - make
     - avr-gcc
     - avrdude
     - xdotool
   - Conectar el Arduino al puerto serie y asegurarse de que esté **libre y sin uso por otras aplicaciones**.

2. Compilar y flashear el firmware:
   ```
   make && make flash
   ```

3. Compilar y ejecutar el lector serial ubicado en la carpeta `gplinux/lectorserial`, con el Arduino conectado.

## Videos

https://drive.google.com/file/d/18hfN5rMxzCJY-7pxvHEETky7a7s2so7e/view?usp=drive_link
