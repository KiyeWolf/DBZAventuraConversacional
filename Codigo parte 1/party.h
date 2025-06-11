#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#define PARTY_MAX 3
#include "character.h"

typedef struct {
    char flags_de_personajes[CANTIDAD_DE_PERSONAJES];
    t_character personajes_arr[CANTIDAD_DE_PERSONAJES];
}t_party_manager;



unsigned int inicializar_personajes();
unsigned int traductor_de_indice(t_party_manager* party, int indice);
unsigned int cantidad_de_personajes_habilitados_party(t_party_manager* party);


#endif // PARTY_H_INCLUDED
