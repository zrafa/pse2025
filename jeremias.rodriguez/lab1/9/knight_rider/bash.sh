#!/bin/bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o utils.o utils.c
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
avr-gcc -mmcu=atmega328p utils.o main.o -o utils.elf
avr-objcopy -O ihex -R .eeprom utils.elf utils.hex
avrdude -c arduino -p atmega328p -U flash:w:./utils.hex:i -P /dev/ttyUSB0
