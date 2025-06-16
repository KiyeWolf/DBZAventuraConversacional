#ifndef NARRATIVE_HEADER_H
#define NARRATIVE_HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINEA 4096
#define TODO_OK 0
#define ERR_LECTURA_ARCH 1
#define ACEPTADO 1
#define RECHAZADO 0
#define RESPUESTA_CORRECTA 3
#define CANT_MINIMA_DE_OPCIONES 1
#define CANT_MAXIMA_DE_OPCIONES 4
#define ERR_ARCH NULL


char* devolverNombreDeArchSegunCodigo(int codigo_linea);

void leerPreguntaBooleana(int* res);
int preguntarYLeerSegunTexto(char* texto);
int cinematica(char* nombreTxt);
int acertijo();
void leerRespuestaMultiples(int* res, int li, int ls);

int ayudarAVegeta();
int perdonarAfreezer();


#endif // NARRATIVE_HEADER_H