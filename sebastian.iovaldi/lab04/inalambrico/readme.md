## Serial inalambrico 

Recibe por serial bytes.
Emite los bytes por el parpadeo de un laser, siguiendo un procolo de comunicación similar al uart. Calibrado para enviar bytes al arduino de Joaquin. Envia un bit cada 75ms.

### Configuracion hardware:
Conectar un laser al puerto B0, apuntar el laser al dispositvo receptor.

### Compilar:
> $ make

### Flashear: 
> $ make flash