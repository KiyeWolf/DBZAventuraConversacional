#ifndef EQUIPAMIENTO_H_INCLUDED
#define EQUIPAMIENTO_H_INCLUDED

#define TAM_MAXIMO_EQUIPAMIENTO 6
#include "item.h"

typedef struct equipamiento {
    unsigned int cantidad;
    t_item items[TAM_MAXIMO_EQUIPAMIENTO];
}t_equipamiento;

int inicializar_equipamiento(t_equipamiento* equipamiento);
t_item devolver_stats_acumulados(t_equipamiento* equipamiento);

#endif // EQUIPAMIENTO_H_INCLUDED
