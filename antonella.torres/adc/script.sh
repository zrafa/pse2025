

cat /dev/ttyUSB0 | while read linea; do
    # Filtra líneas que sean solo números
    if [[ "$linea" =~ ^[0-9]+$ ]]; then
        valor=$linea

        # Asegúrate de que el valor esté entre 600 y 1000
        if [[ $valor -ge 600 && $valor -le 1000 ]]; then
            # Mapeo lineal de 600-1000 a 0-255
            brillo=$(( (valor - 600) * 255 / 400 ))
            
            echo "Valor: $valor -> Brillo: $brillo"
            
            # Ajusta el brillo usando brightnessctl
            brightnessctl s $brillo
        fi
    fi
done
