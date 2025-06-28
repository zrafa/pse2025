sudo cat /dev/ttyUSB0 | while read -n 3 num; do
    brightnessctl s $num
done