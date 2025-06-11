#ifndef CHARACTER_TEMPLATE_H_INCLUDED
#define CHARACTER_TEMPLATE_H_INCLUDED

#include "movement.h"
#include "character_stats.h"

#define CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_PERSONAJE 10


typedef struct character_template {
    unsigned int id;
    char NAME[32];
    t_character_stats stats;
    unsigned int cantidad_de_movimientos;
    t_movements MOVS[CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_PERSONAJE];
} t_character_template;

t_character_stats devolver_stats (t_character_template* personaje);
t_movements devolver_movimiento (t_character_template* personaje, int indice);

#endif // CHARACTER_TEMPLATE_H_INCLUDED
