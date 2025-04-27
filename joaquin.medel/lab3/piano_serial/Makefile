F_CPU?=16000000UL
USART_BAUDRATE?=9600
CC=avr-gcc
OBJETOS=utils.o speaker_driver.o serial.o  main.o 
APP=app
CFLAGS=-Os -mmcu=atmega328p -DF_CPU=$(F_CPU) -DUSART_BAUDRATE=$(USART_BAUDRATE)
LDFLAGS=-mmcu=atmega328p
FIRMWARE=imagen.hex

# $@:Se sustituye por el nombre del objetivo de la presente regla.
# $*:Se sustituye por la raíz de un nombre de fichero.
# $<:Se sustituye por la primera dependencia de la presente regla.
# $^:Se sustituye por una lista separada por espacios de cada una de las dependencias de la presente regla.

all: $(APP)


$(APP): $(OBJETOS)
	$(CC) $(LDFLAGS) -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

flash:
	avr-objcopy -O ihex -R .eeprom $(APP) $(FIRMWARE)
	avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 -D -U flash:w:$(FIRMWARE):i
	
clean:
	rm $(OBJETOS) $(APP) $(FIRMWARE)
