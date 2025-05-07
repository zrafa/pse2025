/* 
 * Dibuja un texto con caracteres ASCII usando un font intercambiable
 * Copyright 2025 - Nicolás Iván Jacznik
 *
 */
#include <string.h>
#include <stdio.h>

#include "font.h"

#define ANCHO 80
#define ALTO 24

unsigned char buffer[ANCHO * ALTO];
unsigned char addr;


void render_buffer(void)
{
	int i = 0;
	char linea[81];
	char *text =  "hola";

	for (i=0; i<ALTO; i++) {
		strncpy(&linea[0], &buffer[i*80], 80); //guardamos la dirección de la linea i del buffer en la dirección de "linea"
		linea[80] = 0; //ultimo valor en 0 para el string
		printf("%s\n", linea);	
	}
}


void draw_pixel_on_buffer(unsigned char x, unsigned char y, int color)
{
	switch(color) {
	case 0:
		buffer[y*80+x] = ' ';
		break;
	case 1:
		buffer[y*80+x] = 'X';
		break;
	default:		
		break;
	}

}

/* Dibuja una letra en el buffer, comenzando con la columna [x,y]
 * para el primer pixel de la letra 
 */
void draw_char_on_buffer(unsigned char x, unsigned char y, char c,
                            unsigned char color)
{

	int i=0; /* para recorrer el font por columnas */
	int j=0; /* para recorrer el font por filas */
	char col; /* para almacenar cada columna de pixeles del font */
	while(i<8){
		while(j < 5){
			col = font[(5*c)+j];
			if((col >> i) & 1){
				draw_pixel_on_buffer(x+j, y+i, 1);
			}else{
				draw_pixel_on_buffer(x+j, y+i, 0);
			}
			j++;
		}
		i++;
		j=0;
	}
}


void clear_buffer(void)
{
	memset(buffer, ' ', (ANCHO * ALTO) * sizeof(unsigned char));
	/*Memset es una función que reserva un espacio en memoria y se puede inicializar el mismo con un valor.
	El primer parámetro es la dirección de memoria donde iniciará el espacio reservado, en este caso la dirección del arreglo buffer.
	El segundo parámetro es el valor con el que se incializará, de esta forma al asignarle ' ' se estará "vaciando" el arreglo.
	Por último, el tercer parámetro indica el tamaño del espacio a reservar. En este caso se reserva una cantidad de ANCHO*ALTO bytes. */
}

/* Muestra un texto en pantalla
 * x e y son coordenadas a resolución de pixel
 * Cada letra es de 6 columnas y 8 filas (1 columna es espacio)
 */
void print_text_on_buffer(unsigned char x, unsigned char y, char *text)
{
	int i = 0;
	int j = 0;
	char *c = text;
	size_t longitud = strlen(text);

	for(j=0;j< longitud; j++){ //
		draw_char_on_buffer(x + j*6, y, (char) c[j], y);
	}
}


int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Error: se necesita al menos un argumento. \n");
		return -1;
	}

	clear_buffer();

	if (argc == 2){
		printf("Programa: %s, y el argumento 1 es: %s .\n", argv[0], argv[1]);
		print_text_on_buffer(3, 5, argv[1]);
	}else { 
		printf("Programa: %s, el argumento 1 es: %s y el argumento 2 es: %s.\n", argv[0], argv[1], argv[2]);
		print_text_on_buffer(3, 5, argv[1]);
		print_text_on_buffer(3, 15, argv[2]);
	}
	render_buffer();

	return 0;


}