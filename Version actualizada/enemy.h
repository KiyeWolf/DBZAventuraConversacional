#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "movement.h"
#define CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_ENEMIGO

typedef struct enemy_stats {
    char* NAME;
    float COMBAT_SPEED;
    unsigned int HP, ATK, ENERGY, ARMOR, XP, cantidad_de_movimientos;
    t_movements movs[CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_ENEMIGO];
}t_enemy_stats;
/*
unsigned int utilizar_movimiento_enemigo(t_character* personaje, unsigned int mov);
unsigned int recibir_ataque_enemigo(t_character* personaje, unsigned int damage);
unsigned int atacar_personaje(t_character* personaje);
*/
#endif // ENEMY_H_INCLUDED
