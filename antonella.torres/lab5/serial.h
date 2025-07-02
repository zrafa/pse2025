/**********************************************************************
 *
 * Filename:    serial.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/
 #include <stdint.h>

#ifndef _SERIAL_H
#define _SERIAL_H


void serial_init(void);
void serial_put_char(char c);
char serial_get_char(void);
void serial_put_escape_sequence(const char* seq);
void serial_put_number(uint16_t number);


#endif /* _SERIAL_H */
