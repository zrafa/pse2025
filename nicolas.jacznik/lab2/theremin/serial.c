
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
    uint8_t status_control_a;    /* ucsr0a USART Control and Status A */
    uint8_t status_control_b; /* ucsr0b USART Control and Status B */
    uint8_t status_control_c; /* ucsr0c USART Control and Status C */
    uint8_t _reserved; /* espacio sin utilizar */
    uint8_t baud_rate_l; /* ubrr0l baud rate low */;
    uint8_t baud_rate_h; /* ubrr0h baud rate high */
    uint8_t data_es;    /* udr0 i/o data */

} volatile uart_t;

/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *) (0xc0);

#define RECEIVER_ENABLE 0x10 /* RXEN0 Habilitar la recepcion */
#define TRANSMITTER_ENABLE 0x08 /* TXEN0 Habilitar la transmicion */
#define CHARACTER_SIZE_0 0x02 /* UCSZ00 Numero de bits del dato de e/s */
#define CHARACTER_SIZE_1 0x04 /* UCSZ01 Numero de bits del dato de e/s */
#define READY_TO_READ 0x80 /* RXC0 Dato listo para leer */
#define READY_TO_WRITE 0x20 /* UDRE0 Buffer vacio listo para escribir */

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)


void serial_init() {

	/* El manual del atmega328p tiene un ejemplo. Adecuarla a C y
           la estructura de datos */

	/* Configurar los registros High y Low con BAUD_PRESCALE */
	/* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
	/* Activar la recepcion y transmicion */

/*Set baud rate */
puerto_serial->baud_rate_h = (unsigned char)(BAUD_PRESCALE>>8);
puerto_serial->baud_rate_l = (unsigned char)BAUD_PRESCALE;
/* Enable receiver and transmitter */
puerto_serial->status_control_b = (RECEIVER_ENABLE)|(TRANSMITTER_ENABLE);
/* Set frame format: 8data, 1stop bit */
puerto_serial->status_control_c = (CHARACTER_SIZE_1 | CHARACTER_SIZE_0);
}


/* enviar un byte a traves del del dispositivo inicializado */
void serial_put_char (char c)
{
    /* Se debe esperar verificando el bit UDREn del registro UCSRnA,
       hasta que el buffer esté listo para recibir un dato a transmitir */
       
       /* Wait for empty transmit buffer */
       while (!(puerto_serial->status_control_a & READY_TO_WRITE))
       ;
       /* Put data into buffer, sends the data */
       puerto_serial->data_es = c;
}


char serial_get_char(void)
{
    /* Wait for the next character to arrive. */
       while (!(puerto_serial->status_control_a & READY_TO_READ))
       ;
       /* Get and return received data from buffer */
       return puerto_serial->data_es;

}



