/**********************************************************************
 *
 * Filename:    serial.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _SERIAL_H
#define _SERIAL_H


void serial_init(void);
void serial_put_char(char c);
char serial_get_char(void);
void serial_put_escape_sequence(const char* seq);


#endif /* _SERIAL_H */
