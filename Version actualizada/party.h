#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#define PARTY_MAX 3
#include "character.h"


typedef struct {
    unsigned int cantidad;
    t_character personajes_arr[PARTY_MAX];
}t_party_manager;



#endif // PARTY_H_INCLUDED
