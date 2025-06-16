#ifndef ENEMY_COLLECTION_H_INCLUDED
#define ENEMY_COLLECTION_H_INCLUDED

#include "enemy.h"

enum e_enemy_id{
    ENEMIGO_VACIO,
    SOLDADO_BASICO,
    BANDIDOS,
    BESTIAS_DE_LA_NIEBLA,
    GUARDIAN,
    GUARDIAN_FASE_DOS,
    SOLDADO_FREEZER_ELITE,
    GOLEM_NAMEKIANO,
    SOLDADOS_INTERMEDIOS,
    HOLOGRAMA_DE_FREEZER,
    SOLDADOS_SAIYAJIN,
    VEGETA_ENEMIGO,
    GHURD,
    JHEESE,
    BULTA,
    RACOOM,
    GINEW,
    FREEZER,
    CANTIDAD_DE_ENEMIGOS
};


extern t_enemy_stats enemy_collection[];
typedef struct {
    unsigned int estado;
    t_enemy_stats retorno;
}t_retorno_enemigo;

t_retorno_enemigo devolver_enemigo_por_id(unsigned int id);

#endif // ENEMY_COLLECTION_H_INCLUDED
