#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#define PARTY_MAX 5
#include "character.h"


typedef struct {
    unsigned int cantidad;
    unsigned int id[PARTY_MAX];
    t_character* personajes_arr[PARTY_MAX];
}t_party_manager;



#endif // PARTY_H_INCLUDED
