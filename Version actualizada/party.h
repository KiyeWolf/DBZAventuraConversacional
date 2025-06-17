#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#define PARTY_MAX 5
#include "character_manager.h"


typedef struct {
    unsigned int cantidad;
    unsigned int id[PARTY_MAX];
    t_character* personajes_arr[PARTY_MAX];
}t_party_manager;

unsigned int agregar_personaje_party(t_party_manager* party, t_character_manager* manager,  unsigned int* ids, unsigned int cantidad_de_personajes_party);

#endif // PARTY_H_INCLUDED
