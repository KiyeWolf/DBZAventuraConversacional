#ifndef GAME_MANAGER_H_INCLUDED
#define GAME_MANAGER_H_INCLUDED

#include "nodo.h"
#include "character_manager.h"
#include "inventario.h"

typedef struct {
    unsigned int nodo_actual;
    t_character_manager character_manager;
    t_inventory inventario;
}t_gameState;

void game_loop(t_gameState* game_state);
void llega_a_hoguera(t_inventory* inventario, t_party_manager* party);
void mostrar_todos_los_items(t_inventory* inventario);
void intercambiar_item(t_inventory* inventario, t_party_manager* party, int opcion);
int mostrar_items_party (t_party_manager* party, int personaje);
void guardar_partida(t_gameState* game_state);
#endif // GAME_MANAGER_H_INCLUDED
