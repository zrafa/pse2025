#!/bin/bash
make clean
make
make flash
picocom /dev/ttyUSB0 -b 9600 -l
