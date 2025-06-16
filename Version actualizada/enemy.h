#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "movement.h"
#define CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_ENEMIGO 5

typedef struct enemy_stats {
    char* NAME;
    float COMBAT_SPEED;
    unsigned int HP, ATK, ENERGY, ARMOR, cantidad_de_movimientos;
    t_movements movs[CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_ENEMIGO];
}t_enemy_stats;

unsigned int utilizar_movimiento_enemigo(t_enemy_stats* personaje, unsigned int mov);
unsigned int recibir_ataque_enemigo(t_enemy_stats* personaje, unsigned int damage);
unsigned int atacar_personaje(t_enemy_stats* personaje);
unsigned int devolver_cantidad_de_movimientos (t_enemy_stats* enemigo);
unsigned int devolver_experiencia (t_enemy_stats* enemigo);
#endif // ENEMY_H_INCLUDED
