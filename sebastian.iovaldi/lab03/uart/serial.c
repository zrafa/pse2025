
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


 /* Completar la estructura de datos para que se superponga a los registros
    del periferico de hardware del USART del atmega328, segun sugerido
    en el apunte */
 
 typedef struct
 {
    uint8_t status_control_a;
    uint8_t status_control_b;
    uint8_t status_control_c;
    uint8_t reserved;
    uint8_t baud_rate_low;
    uint8_t baud_rate_high;
    uint8_t data_es;    
 }  uart_t;
 
 /* puntero a la estructura de los registros del periferico */
 volatile uart_t *puerto_serial = (uart_t *) (0xc0);
 
 #define F_CPU 4000000UL
 #define USART_BAUDRATE 2400UL
 #define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
 
void serial_init()
{
    /* Escribir una rutina de inicializacion */

    /* El manual del atmega328p tiene un ejemplo. Adecuarla a C y
        la estructura de datos */

    /* Configurar los registros High y Low con BAUD_PRESCALE */
    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
    /* Activar la recepcion y transmicion */
 
    puerto_serial->status_control_b |= 0x08;    /* enables tx */
    puerto_serial->status_control_b |= 0x10;    /* enables rx */

    puerto_serial->status_control_b &= ~0x04;   /* 8 bits per frame */
    puerto_serial->status_control_c |= 0x06;    /* 8 bits per frame */

    puerto_serial->status_control_c &= ~0xC0;   /* Asynchronous USART */
    puerto_serial->status_control_c &= ~0x08;   /* 1 stop bit */
    puerto_serial->status_control_c &= ~0x48;   /* parity bit - disabled */
    puerto_serial->status_control_c &= ~0x01;   /* clock polarity (not async)*/

    puerto_serial->baud_rate_high = (unsigned char)BAUD_PRESCALE >> 8;
    puerto_serial->baud_rate_low  = (unsigned char)BAUD_PRESCALE & 0xFF;
}

 
 /* enviar un byte a traves del del dispositivo inicializado */
 void serial_put_char (char c)
{
    /* Wait until the transmitter is ready for the next character. */

    /* completar con E/S programada */
    /* Se debe esperar verificando el bit UDREn del registro UCSRnA,
    hasta que el buffer esté listo para recibir un dato a transmitir */

    // while ( /* completar con E/S programada */ )
    //     ;
    while(!(puerto_serial->status_control_a & 0x20));

    /* Send the character via the serial port. */
    /* (escribir el dato al registro de datos de E/S */

    puerto_serial->data_es = c;
}
 
 
 char serial_get_char(void)
 {
     /* Wait for the next character to arrive. */
     /* Completar con E/S programada similar a serial_put_char pero 
        utilizando el bit correcto */
     
    while ( !(puerto_serial->status_control_a & 0b10000000 ));
 
    return puerto_serial->data_es;
 }
 
 
 
 