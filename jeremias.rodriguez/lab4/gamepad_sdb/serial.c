
/**********************************************************************
 *
 * serial.c - Driver del UART del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 * Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
 *
 **********************************************************************/

 #include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
 #include <string.h>
 #include <stdlib.h>
 
 /* Completar la estructura de datos para que se superponga a los registros
    del periferico de hardware del USART del atmega328, segun sugerido
    en el apunte */
 
 
    volatile unsigned char unpint = 0b00100000;
 typedef struct
 {
     uint8_t status_control_a;    /* ucsr0a USART Control and Status A */
     uint8_t status_control_b; /* ucsr0b USART Control and Status B */
     uint8_t status_control_c; /* ucsr0c USART Control and Status C */
     uint8_t _reserved;
     uint8_t baud_rate_l; /* ubrr0l baud rate low */
     uint8_t baud_rate_h; /* ubrr0h baud rate high */
 
     uint8_t data_es;    /* udr0 i/o data */
 
 } volatile uart_t;
 
 /* puntero a la estructura de los registros del periferico */
 volatile uart_t *puerto_serial = (uart_t *) (0xc0);
 
 #define USART_BAUDRATE 9600
 #define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
 
 #define RECEIVER_ENABLE 0x10    //0001 0000  /* RXEN0 Habilitar la recepcion */
 #define TRANSMITTER_ENABLE 0x08 //0000 1000  /* TXEN0 Habilitar la transmicion */
 #define CHARACTER_SIZE_0 0x02   //0000 0010  /* UCSZ00 Numero de bits del dato de e/s */
 #define CHARACTER_SIZE_1 0x04   //0000 0100  /* UCSZ01 Numero de bits del dato de e/s */
 #define READY_TO_READ 0x80      //1000 0000  /* RXC0 Dato listo para leer */
 #define READY_TO_WRITE 0x20     //0010 0000  /* UDRE0 Buffer vacio listo para escribir */
 
 /**
 1. Setear el baud rate
 2. Setear el frame format
 3. Habilitar el transmisor o receptor, depende el uso
 */
 void serial_init() {
 
     /* Escribir una rutina de inicializacion */
 
     /* El manual del atmega328p tiene un ejemplo. Adecuarla a C y
            la estructura de datos */
 
 
     
     /* Configurar los registros High y Low con BAUD_PRESCALE */
     puerto_serial->baud_rate_h = (unsigned char) (BAUD_PRESCALE >> 8);
     puerto_serial->baud_rate_l = (unsigned char) (BAUD_PRESCALE);
     
 
     /* Activar la recepcion y transmicion */
     puerto_serial->status_control_b = (unsigned char) (RECEIVER_ENABLE | TRANSMITTER_ENABLE);
 
     /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
     puerto_serial->status_control_c = (unsigned char) (CHARACTER_SIZE_0 | CHARACTER_SIZE_1);
 
 
 }
 
 
 /* enviar un byte a traves del dispositivo inicializado */
 void serial_put_char (char c)
 {
     /* Wait until the transmitter is ready for the next character. */
     
     /* completar con E/S programada */
     /* Se debe esperar verificando el bit UDREn del registro UCSRnA,
        hasta que el buffer esté listo para recibir un dato a transmitir */
 
     while (!(puerto_serial->status_control_a & READY_TO_WRITE));
 
     /* Send the character via the serial port. */
     /* (escribir el dato al registro de datos de E/S */
     puerto_serial->data_es = c;
 }
 
 void serial_put_str(char *c){
     int len = strlen(c);
     for(int i = 0; i < len; i++){
         serial_put_char(c[i]);
     }
 }
 
 char serial_get_char(void)
 {
     /* Wait for the next character to arrive. */
     /* Completar con E/S programada similar a serial_put_char pero 
        utilizando el bit correcto */
     
     while (!(puerto_serial->status_control_a & READY_TO_READ));
 
     /* DEBE devolver el valor que se encuentra en el registro de datos de E/S */
     return puerto_serial->data_es;
 }
 
 void serial_put_int(uint16_t value, uint16_t digits)
 {
     char numero[digits +2];
     char buffer[digits +2];
 
     itoa(value, numero, 10);
 
     uint16_t len = strlen(numero);
     uint16_t n = digits - len;
 
     for (uint16_t i = 0; i < n; i++) {
         buffer[i] = '0';
     }
 
     strcpy(buffer + n, numero);
 
     serial_put_str(buffer);
 }
 
 