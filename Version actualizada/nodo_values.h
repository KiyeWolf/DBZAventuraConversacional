#ifndef NODO_VALUES_H_INCLUDED
#define NODO_VALUES_H_INCLUDED

#include "party.h"
#define CANT_MAX_RECOMPENSAS 10
#define MAX_ENEMY 4

typedef struct {
    unsigned int id_del_archivo_de_texto[2], branchea;
    unsigned int repetible;
    unsigned int enemy_ids[MAX_ENEMY], cantidad_de_enemigos;
    unsigned int party_habilitados_ids[PARTY_MAX], tam_party;
    unsigned int items_ids[CANT_MAX_RECOMPENSAS];
}t_nodo_values;


#endif // NODO_VALUES_H_INCLUDED
