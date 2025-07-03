
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
#define RECEIVER_ENABLE     (1 << 4)  // RXEN0
#define TRANSMITTER_ENABLE  (1 << 3)  // TXEN0
#define CHARACTER_SIZE_0    (1 << 1)  // UCSZ00
#define CHARACTER_SIZE_1    (1 << 2)  // UCSZ01
#define READY_TO_READ       (1 << 7)  // RXC0
#define READY_TO_WRITE      (1 << 5)  // UDRE0


#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)




void serial_init() {

	/* Escribir una rutina de inicializacion */

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
/* Set frame format: 8data, 2stop bit */
puerto_serial->status_control_c = (CHARACTER_SIZE_1 | CHARACTER_SIZE_0);
}


/* enviar un byte a traves del del dispositivo inicializado */
void serial_put_char (char c)
{
    //espero que haya algo para leer
    while (!(puerto_serial->status_control_a & READY_TO_WRITE)){
      }
   
    puerto_serial->data_es = c; /* escribir el dato al registro de datos de E/S */
   

}

void serial_put_escape_sequence(const char* seq) {
    while (*seq) {
        serial_put_char(*seq++);
    }
}

char serial_get_char(void)
{    
    while (!(puerto_serial->status_control_a & READY_TO_READ)){
    }

    return puerto_serial->data_es; /* devolver el dato leido */

}

void serial_put_number(uint16_t num) {
    char buffer[6]; // Hasta 5 dígitos + null terminator
    int i = 0;

    if (num == 0) {
        serial_put_char('0');
        return;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    // Enviar los dígitos en orden correcto
    while (i--) {
        serial_put_char(buffer[i]);
    }
    serial_put_char('\n'); // Separador para que el script en PC lo lea fácil
}


