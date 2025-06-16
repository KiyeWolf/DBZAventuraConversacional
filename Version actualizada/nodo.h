#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "party.h"
#include "enemy_collection.h"

#define CANT_MAX_NODOS 100
#define MAX_CUSTCENE_BUFF 1024

#define CANT_MAX_RECOMPENSAS 10
#define MAX_ENEMY 4

typedef struct {
    unsigned int id_del_archivo_de_texto[2], branchea, es_hoguera;
    unsigned int hay_pelea, enemy_ids[MAX_ENEMY], cantidad_de_enemigos;
    unsigned int party_habilitados_ids[PARTY_MAX], tam_party;
    unsigned int items_ids[CANT_MAX_RECOMPENSAS], cantidad_de_items;
}t_nodo;

extern t_nodo nodos[];

unsigned int cargar_nodos(t_nodo* nodo);

#endif // NODO_H_INCLUDED
