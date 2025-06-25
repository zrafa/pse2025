
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
#define USART_BAUDRATE 9600
/* Completar la estructura de datos para que se superponga a los registros
   del periferico de hardware del USART del atmega328, segun sugerido
   en el apunte */

typedef struct
{
    uint8_t status_control_a; /* ucsr0a USART Control and Status A */
    uint8_t status_control_b; /* ucsr0b USART Control and Status B */
    uint8_t status_control_c; /* ucsr0c USART Control and Status C */
    uint8_t _reserved;        /* espacio sin utilizar */
    uint8_t baud_rate_l;      /* ubrr0l baud rate low */
    uint8_t baud_rate_h;      /* ubrr0h baud rate high */

    uint8_t data_es; /* udr0 i/o data */

} volatile uart_t;

/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *)(0xc0);

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void serial_init()
{
    /* Configurar los registros High y Low con BAUD_PRESCALE */
    puerto_serial->baud_rate_h = (unsigned char)(BAUD_PRESCALE >> 8);
    puerto_serial->baud_rate_l = (unsigned char)(BAUD_PRESCALE);
    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
    puerto_serial->status_control_c = 0b00100110; // 00 asincrono , 10 paridad par ,0 un bit de top, 11 tamaño de 8bits,0 polaridad solo para sincr
    /* Activar la recepcion y transmicion */
    puerto_serial->status_control_b = 0b00011000; // Encendemos la transmicion y recepcion
}

/* enviar un byte a traves del del dispositivo inicializado */
void serial_put_char(char c)
{
    /* Wait until the transmitter is ready for the next character. */

    /* completar con E/S programada */
    /* Se debe esperar verificando el bit UDREn del registro UCSRnA,
       hasta que el buffer esté listo para recibir un dato a transmitir */

    while ((puerto_serial->status_control_a & 0b00100000) != 0b00100000)
        ; // Leo UDRN esperando que esten 1 , osea que esta listo para recibir un dato
    puerto_serial->data_es = c;
    /* Send the character via the serial port. */
    /* (escribir el dato al registro de datos de E/S */
}

char serial_get_char(void)
{
    /* Wait for the next character to arrive. */
    /* Completar con E/S programada similar a serial_put_char pero
       utilizando el bit correcto */

    while ((puerto_serial->status_control_a & 0b10000000) != 0b10000000)
        ;
    return puerto_serial->data_es;
    // return /* DEBE devolver el valor que se encuentra en el registro de datos de E/S */
}
