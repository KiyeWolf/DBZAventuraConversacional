#ifndef GAME_MANAGER_H_INCLUDED
#define GAME_MANAGER_H_INCLUDED

#include "nodo.h"
#include "character.h"

typedef struct {
    unsigned int nodo_actual;
    t_character_manager character_manager;
    t_inventory inventario;
}t_gameState;

#endif // GAME_MANAGER_H_INCLUDED
