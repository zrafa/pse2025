# Compilador
CC = avr-gcc

# Flags
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
LDFLAGS = -mmcu=atmega328p

# Archivos
APP = adc
OBJETOS = main.o adc.o timer2_pwm.o serial.o
FIRMWARE = $(APP).hex

# Objetivo por defecto
all: $(APP)

# Enlazado
$(APP): $(OBJETOS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compilación individual de .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Generar archivo HEX e instalar en el microcontrolador
flash: $(APP)
	avr-objcopy -O ihex -R .eeprom $< $(FIRMWARE)
	avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 -D -U flash:w:$(FIRMWARE):i

# Limpiar archivos generados
clean:
	rm -f $(OBJETOS) $(APP) $(FIRMWARE)
