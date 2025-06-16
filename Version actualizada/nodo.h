#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "nodo_values.h"
#include "cutscene.h"

#define CANT_MAX_NODOS 100
#define MAX_CUSTCENE_BUFF 1024

typedef struct {
    char TEXTO_INICIAL[MAX_CUSTCENE_BUFF];
    t_texto_cutscene texto;
}t_nodo;

t_nodo nodos[CANT_MAX_NODOS];

typedef struct {
    unsigned int id_del_archivo_de_texto[2];
    unsigned int repetible;
    unsigned int enemy_ids[MAX_ENEMY], cantidad_de_enemigos;
    unsigned int party_habilitados_ids[PARTY_MAX], tam_party;
    unsigned int items_ids[CANT_MAX_RECOMPENSAS];
}t_nodo_values;


{
    0,
    1, GOHAN, KRILLIN,
    PELEA
    2, HOGUERA,
    3, GOHAN, KRILLIN,
    PELEA
    4,
    5, GOHAN, KRILLIN,
    PELEA
    6, HOGUERA
    7, BRANCH {
        8,
        9, GOHAN, KRILLIN
        PELEA
    },
    10,
    11,
    12, HOGUERA
    13, GOHAN, KRILLIN
    PELEA,
    14, GOHAN, KRILLIN,
    PELEA
    15, HOGUERA
    16, GOHAN KRILLIN
}

unsigned int cargar_nodos(t_nodo* nodo);

#endif // NODO_H_INCLUDED
