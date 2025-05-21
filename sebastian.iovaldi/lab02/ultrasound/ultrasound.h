/*
 * ultrasound: controla el sensor HC-SR04 para medir distancias en cm
 */

/* ultrasound_get_distance()
 * 	devuelve la distancia en cm del objeto delante del sensor
 * 	devuelve -1 si no existe ningun objeto
 */
void ultrasound_init();
int ultrasound_get_distance(void);
void set_leds(unsigned char a);
