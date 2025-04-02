/* 
 * Dibuja un texto con caracteres ASCII usando un font intercambiable
 * Copyright 2025 - Jeremias Agustin Rodriguez (从技术上讲，它没有许可证，但他们不可能从另一个国家偷来，为了避免法律问题，我就不提这个国家的名字了）。 
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
		strncpy(&linea[0], &buffer[i*80], 80);
		linea[80] = 0;
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

	int i; /* para recorrer el font por columnas */
	int j; /* para recorrer el font por filas */
	char col; /* para almacenar cada columna de pixeles del font */
	int letprint, ascii_c;


	/* COMPLETAR: debe recorrer cada columna del font de la letra c
	 * y por cada columna debe recorrer los 8 bits de la columna. 
	 * Si el bit es igual a 1 entonces debe dibujar el bit en el buffer
	 * usando draw_pixel_on_buffer.
	 */
	for(i = 0; i < 5; i++){
		ascii_c = (int) c;
		col = *(font+5*ascii_c+i);
		for(j = 0; j < 8; j++){
			letprint = (col & 0b00000001) == 0b00000001;
			draw_pixel_on_buffer(x+i, y+j, letprint);
			col = col >> 1;
		}
	}

	/* Debe extraer cada columna del arreglo font[] */

	/* El font que representa cada letra tiene 5 columnas x 8 filas (5x8bits) */
}

/**
* Como el buffer es usado para imprimir caracteres, que representan caracteres.
* Dentro de esa representacion X es considerado un pixel, y ' ' es la
* ausencia de dicho pixel. Entonces, al "limpiar el buffer" lo que hacemos es
* borrar los pixeles.
*/
void clear_buffer(void)
{
	memset(buffer, ' ', (ANCHO * ALTO) * sizeof(unsigned char));
}

/* Muestra un texto en pantalla
 * x e y son coordenadas a resolución de pixel
 * Cada letra es de 6 columnas y 8 filas (1 columna es espacio)
 */
void print_text_on_buffer(unsigned char x, unsigned char y, char *text)
{
	int i = 0, size = strlen(text);
	char *c = text;
	char last_char;
	
	while (*c && size > i) {
		
		/* Recorra el mensaje (puntero c) y dibuje cada letra en el
  		 * buffer utilizando la funcion draw_char_on_buffer() 
		 *
		 * Importante: cada letra ocupa 5 columnas, por lo que
		 * cada letra debe ir ubicada 6 columnas mas adelante con 
		 * respecto a la letra anterior (5 columnas + 1 espacio extra)
		 */
		last_char = *(c+i);
		draw_char_on_buffer(x,y,last_char,1);
		x+=6;
		if(x > ANCHO){
			x = (x+6) % ANCHO;
			y += 8;
		}
		i+=1;
		printf("%d - %d - %d\n",i,x,y);
	}
}


int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Error: se necesita al menos un argumento. \n");
		return -1;
	}

	printf("Programa: %s, y el argumento 1 es: %s \n", argv[0], argv[1]);
	clear_buffer();
	printf("OK\n");
	
	if (argc == 2)
		print_text_on_buffer(3, 5, argv[1]);
	else { 
		print_text_on_buffer(3, 5, argv[1]);
		print_text_on_buffer(3, 15, argv[2]);
	}
	
	render_buffer();

	return 0;


}
