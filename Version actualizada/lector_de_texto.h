#ifndef LECTOR_DE_TEXTO_H_INCLUDED
#define LECTOR_DE_TEXTO_H_INCLUDED

#define MAX_LINEA 4096
#define TODO_OK 0
#define ERR_LECTURA_ARCH 1
#define ACEPTADO 1
#define RECHAZADO 0

int cinematica(char* nombreTxt);
char* devolverNombreDeArchSegunCodigo(int codigo_linea);

#endif // LECTOR_DE_TEXTO_H_INCLUDED
