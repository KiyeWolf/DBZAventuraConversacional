#include "character_template.h"

t_character_stats devolver_stats (t_character_template* personaje)
{
    return personaje->stats;
}
t_movements devolver_movimiento (t_character_template* personaje,
                                 int indice)
{
    return personaje->MOVS[indice];
}
