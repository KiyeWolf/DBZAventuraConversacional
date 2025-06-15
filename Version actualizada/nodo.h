#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "nodo_values.h"
#include "cutscene.h"

#define CANT_MAX_NODOS 100

typedef struct {
    t_nodo_values values;
    t_texto_cutscene texto;
}t_nodo;

t_nodo nodos[CANT_MAX_NODOS];

unsigned int cargar_nodos(t_nodo* nodo);

#endif // NODO_H_INCLUDED
