#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include "character.h"
#include "party.h"
#include "enemy.h"

#define JUGADOR 0
#define ENEMIGO 1
#define CICLO_TURNO 100.0f

typedef struct
{
    int tipo;
    int id;
    float contador_turno;
}t_combatiente;

typedef struct
{
    t_party_manager* party;
    t_enemy_stats enemigos[3];
    int cantidad_enemigos;
}t_combate;

void iniciar_combate(t_party_manager* party, t_enemy_stats enemigos[], int cantidad_enemigos);//Solo se necesita de esta fucion para comenzar los combates.

void ciclo_combate(t_combatiente combatientes[], int total, t_combate* combate);//Funcion para calcular constantemente los turnos del combate

void ejecutar_turno(t_combatiente* c, t_combate* combate);//Funcion para realizar el turno del jugador o de la IA.

int fin_combate(t_combate* combate, t_combatiente combatientes[], int total_combatientes);

#endif // COMBAT_MANAGER_H
