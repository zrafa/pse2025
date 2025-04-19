
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

 #ifndef _UTILS_H
 #define _UTILS_H
 
 
 void esperar();
 void init();
 void contador_binario();
 
 
 #endif	/* _UTILS_H */