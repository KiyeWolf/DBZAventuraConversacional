#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include "character.h"
#include "party.h"
#include "enemy.h"

#define JUGADOR 0
#define ENEMIGO 1

typedef struct
{
    int tipo;
    int id;
    float velocidad;
    int hp_actual;
    float contador_turno;
}t_combatiente

typedef struct
{
    t_party* party;
    t_enemy_stats enemigos[3];
    int cantidad_enemigos;
}t_combate;

void inicializar_combatientes(t_combatiente combatientes[], t_combate* combate, int* total);//Funcion para determinar el rol de los combatientes y hacer una copia temporal de ellos.

void ciclo_combate(t_combatiente combatientes[], int total, t_combate* combate);//Funcion para calcular constantemente los turnos del combate

void ejecutar_turno(t_combatiente* c, t_combate* combate);//Funcion para realizar el turno del jugador o de la IA.

#endif // COMBAT_MANAGER_H
