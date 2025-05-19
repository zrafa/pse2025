sudo cat /dev/ttyUSB0 | while read linea; do
if [[ "$linea" =~ ^[0-9]+$ ]]; then
        valor=$linea

  echo "Valor recibido: $valor"
  brightnessctl s $((255 - valor))
fi
done

