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

void HistoriaCompleta();
char* devolverNombreDeArchSegunCodigo(int codigo_linea);
void leerPreguntaBooleana(int* res);
int preguntarYLeerSegunTexto(char* texto);
int tutorial();
int aceptarAyudarAnimales();
int cinematica(char* nombreTxt);
void Altar();
int acertijo();
void leerRespuestaMultiples(int* res, int li, int ls);

void aceptarAyudaEsqueleto(int* esqueleto);
int investigarRuidos();
int ayudarAVegeta();
int rodearGolem();
int perdonarAfreezer();


#endif // NARRATIVE_HEADER_H
