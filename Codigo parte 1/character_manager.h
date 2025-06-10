#ifndef CHARACTER_MANAGER_H_INCLUDED
#define CHARACTER_MANAGER_H_INCLUDED

#include "character.h"

typedef struct {
    char flags_de_personajes_desbloqueados[CANTIDAD_DE_PERSONAJES];
    t_character personajes_arr[CANTIDAD_DE_PERSONAJES];
}t_character_manager;

typedef struct {
    unsigned int estado_retorno;
    t_character* retorno;
}t_retorno_character;

t_retorno_character devolver_personaje_manager_id (t_character_manager* personajes, unsigned int id);
unsigned int cambiar_estado_por_id (t_character_manager* personajes, unsigned int id, unsigned int estado);
unsigned int comprobar_estado (t_character_manager* personajes, unsigned int id);
void descansar_manager(t_character_manager* personajes);
#endif // CHARACTER_MANAGER_H_INCLUDED
