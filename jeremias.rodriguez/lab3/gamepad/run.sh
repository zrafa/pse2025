#!/bin/bash

stty -F /dev/ttyUSB0 speed 9600 # o 2400 la que necesiten
cat /dev/ttyUSB0 | while read -n 1 tecla; do
    xdotool keydown $tecla
done