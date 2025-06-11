#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#define MAX_LEVEL 5

#include "character_collection.h"
#include "item_collection.h"
#include "equipamiento.h"


typedef struct character_status {
    unsigned int XP, LVL, ID;
    unsigned int CD_counter[CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_PERSONAJE];
    char movement_unlocked_flag[CANTIDAD_MAXIMA_DE_MOVIMIENTOS_POR_PERSONAJE];
}t_character_status;

typedef struct character {
    unsigned int HP_actual, ENERGY_actual;
    unsigned int HP_max, ATK_max, ENERGY_max, ARMOR;
    float COMBAT_SPEED;
    t_character_template personaje_template;
    t_character_status status;
    t_equipamiento equipo;
}t_character;

void desbloquear_movimiento(t_character* personaje, unsigned int movement_id);
void calcular_stats_actuales(t_character* personaje);
void reiniciar_todos_los_cd(t_character* personaje);
void resucitar_personaje(t_character* personaje);
void reducir_cd(t_character* personaje);
void descansar(t_character* personaje);
void inicializar_movimientos (t_character* personaje);
int utilizar_movimiento(t_character* personaje, unsigned int mov);
int agregar_item_personaje(t_character* personaje, unsigned int id);
int remover_item_personaje(t_character* personaje, unsigned int id);
unsigned int inicializar_personaje(t_character* personaje, unsigned int id);
unsigned int curar_personaje (t_character* personaje, unsigned int HEAL);
unsigned int recibir_ataque(t_character* personaje, unsigned int damage);
unsigned int devolver_id_personaje (t_character* personaje);
unsigned int atacar_enemigo(t_character* personaje);


#endif // CHARACTER_H_INCLUDED
