# Controlador Analógico para SDL-Ball – Integración de Arduino como Gamepad

## Descripción

Este proyecto consiste en utilizar un **knob (potenciómetro) conectado a un Arduino** como un gamepad analógico para controlar la paleta en el juego SDL-Ball (un clon de Breakout/DX-Ball para Linux). El Arduino envía valores en el rango 0–255 a través de puerto serie (por ejemplo, `/dev/ttyUSB0`), y el juego SDL-Ball ha sido modificado para leer estos valores y mover la paleta en tiempo real.

El juego original se proporciona en un archivo ZIP ("sdl-ball original"), y este README explica **qué partes del código fueron modificadas y con qué propósito** para permitir el control mediante el hardware externo.

---

## Conexión del knob (potenciómetro) al Arduino

Se usó la misma conexión que en proyectos anteriores:

- **Potenciómetro (Knob):**
  - Un extremo a **5V**
  - El otro extremo a **GND**
  - Pin central (wiper) a **A0** (entrada analógica del Arduino)

El Arduino lee el valor analógico (0–1023, escalado a 0–255) y lo envía por serial.

---

## Modificaciones realizadas en `main.cpp`

### 1. Inclusión de librerías para hilos y entrada serial

Se añadieron las siguientes líneas al inicio del archivo para habilitar el uso de hilos (`std::thread`), temporizadores (`std::chrono`), strings y flujos de texto:

```cpp
// para pse
#include <thread>
#include <chrono>
//agrego yo
#include <string>
#include <sstream>
```

**Propósito:**  
Permitir la ejecución de un hilo separado que lee continuamente los datos provenientes del Arduino por el puerto serie, sin bloquear el ciclo principal del juego.

---

### 2. Implementación de la función `thread_pse`

Se agregó la siguiente función en `main.cpp`:

```cpp
void thread_pse(controllerClass &control) { // & es para referenciar
    std::ifstream usb("/dev/ttyUSB0");
    std::string linea;

    if (!usb.is_open()) {
        std::cerr << "No se pudo abrir /dev/ttyUSB0" << std::endl;
        return;
    }

    while (true) {
        if (std::getline(usb, linea)) {
            try {
                int valor = std::stoi(linea);

                if (valor >= 0 && valor <= 255) {
                    // Escalamos de 0–255 a -1.66–1.66
                    float p = ((valor / 255.0f) * 3.32f) - 1.66f;

                    std::cout << "Valor recibido: " << valor << " => p: " << p << std::endl;
                    control.movePaddle(p);
                }
            } catch (std::exception &e) {
                // Línea no válida, se ignora
            }
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}
```

**Propósito:**  
- Leer continuamente el valor enviado por el Arduino por el puerto serie (`/dev/ttyUSB0`).
- Convertir el valor de 0–255 a la posición horizontal del paddle en el rango usado por SDL-Ball (aproximadamente -1.66 a +1.66).
- Llamar a `control.movePaddle(p)` para actualizar la posición de la paleta en el juego según el valor leído.
- Permitir un control analógico fluido y en tiempo real usando el hardware externo.

---

### 3. Lanzamiento del hilo en el `main`

Se añadió dentro del `main` (antes del bucle principal del juego):

```cpp
controllerClass control(&paddle, &bullet, &bMan);

// para pse
std::thread t(thread_pse, std::ref(control));
```

**Propósito:**  
- Instanciar y lanzar el hilo que ejecuta `thread_pse`, el cual se mantiene escuchando el puerto serie mientras el juego está corriendo.
- Mantener la compatibilidad con el resto de los controles del juego (mouse, teclado, joystick), permitiendo que el paddle también pueda controlarse por el knob del Arduino.

---

## Resumen de la integración

- **Hardware:** Arduino con un potenciómetro (knob) conectado, envía valores por puerto serie según la posición del potenciómetro.
- **Conexión:**  
  - Un extremo del potenciómetro a 5V, otro a GND, y el central a A0 del Arduino.
- **Software:**  
  - SDL-Ball modificado para leer valores del puerto serie y mapearlos directamente a la posición de la paleta en el juego.
  - El control tradicional por teclado/mouse sigue funcionando, pero ahora es posible jugar de forma analógica con el knob.
- **Propósito:**  
  - Experimentar con la integración de hardware externo y videojuegos open source.
  - Usar un dispositivo físico casero como gamepad para un juego clásico en Linux.

---

## Video

- Se puede ver un video del programa en ejecución mediante el siguiente enlace: https://drive.google.com/file/d/13Y5ZWgReZ_MfFtQEOYbrjQwGB67-zJm6/view?usp=sharing

**Créditos:**  
- Juego original: *SDL-Ball* por Jimmy Christensen  
- Modificaciones para control analógico con Arduino: Nicolás Iván Jacznik  
2025
