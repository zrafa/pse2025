## Piano 

Aplicación que envia por uart las teclas pulsadas, para que el hardware conectado emita sonido. 

### Dependencias:
- SDL3
- Hardware del piano.

### Compilar:
```bash
$ gcc -lSDL3 main.c input.c render.c serial.c -o piano
```
### Ejecutar:
```bash
$ stty -F /dev/ttyUSBX 2400 cs8 -cstopb -parenb
$ ./piano
