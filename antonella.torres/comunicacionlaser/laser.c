#include "laser.h"

void laser_init() {
    LASER_DDR |= (1 << LASER_BIT);        // Pin como salida
    LASER_PORT |= (1 << LASER_BIT);       // Reposo: láser encendido
}

void sendBit(uint8_t bit) {
    if (bit) {
        LASER_PORT |= (1 << LASER_BIT);   // HIGH
    } else {
        LASER_PORT &= ~(1 << LASER_BIT);  // LOW
    }
    _delay_ms(BIT_DURATION);
}

void sendByte(uint8_t byte) {
    // Start bit (LOW)
    LASER_PORT &= ~(1 << LASER_BIT);
    _delay_ms(START_DELAY);

    for (uint8_t i = 0; i < 8; i++) {
        sendBit((byte >> i) & 0x01);
    }

    // Stop bit opcional (LOW)
    LASER_PORT &= ~(1 << LASER_BIT);
    _delay_ms(STOP_DELAY);

    // Volver al estado de reposo (HIGH)
    LASER_PORT |= (1 << LASER_BIT);
}
