#include "character.h"

#define MOVIMIENTO_INEXISTENTE 10
#define MOVIMIENTO_NO_DESBLOQUEADO 11
#define AUN_ESPERANDO_CD 12
#define ENERGIA_INSUFICIENTE 13


#define MAX_HP_NO_HEAL 0
#define CHAR_HEALED 1


#define ID_INVALIDO 1

//Interacciones
unsigned int recibir_ataque(t_character* personaje,
                            unsigned int damage)
{
    if ((damage - personaje->ARMOR) < 0){
        if(personaje->HP_actual <= (damage - personaje->ARMOR))
            personaje->HP_actual = 0;
        else
            personaje->HP_actual -= damage - personaje->ARMOR;
    }
    return personaje->HP_actual;
}

unsigned int atacar_enemigo(t_character* personaje)
{
    return personaje->ATK_max;
}

unsigned int utilizar_movimiento(t_character* personaje,
                                 unsigned int mov)
{
    if(!((mov + 1)<= personaje->personaje_template.cantidad_de_movimientos))
        return MOVIMIENTO_INEXISTENTE;
    if(!(personaje->status.movement_unlocked_flag[mov]))
        return MOVIMIENTO_NO_DESBLOQUEADO;
    if(!personaje->status.CD_counter[mov])
        return AUN_ESPERANDO_CD;

    t_movements movimiento = devolver_movimiento(&personaje->personaje_template, mov);
    if(movimiento.ENERGY_REQUIREMENTS > personaje->ENERGY_actual)
        return ENERGIA_INSUFICIENTE;

    personaje->status.CD_counter[mov] = movimiento.CD;
    return movimiento.DAMAGE + personaje->ATK_max;
}

unsigned int curar_personaje (t_character* personaje,
                              unsigned int HEAL)
{
    if(personaje->HP_actual == personaje->HP_max)
        return MAX_HP_NO_HEAL;

    personaje->HP_actual = (personaje->HP_actual + HEAL) > personaje->HP_max ? personaje->HP_max: personaje->HP_actual + HEAL;
    return CHAR_HEALED;
}

void resucitar_personaje(t_character* personaje)
{
    personaje->HP_actual = personaje->HP_max * (10 / 100);
}

//inicializacion
unsigned int inicializar_personaje(t_character* personaje,
                                   unsigned int id)
{
    t_retorno_template resultado;
    resultado                       = devolver_template_por_id(id);
    if(resultado.estado_del_retorno == 0)
        return 1;
    personaje->status.ID            = id;
    personaje->status.XP            = 0;
    personaje->status.LVL           = 1;
    personaje->personaje_template   = resultado.retorno;

    inicializar_equipamiento(&personaje->equipo);
    calcular_stats_actuales(personaje);
    descansar(personaje);

    return 0;
}

//Manejo de stats
void calcular_stats_actuales(t_character* personaje)
{
    t_item total_de_item = devolver_stats_acumulados(&(personaje->equipo));
    t_character_stats stats = devolver_stats(&personaje->personaje_template);

    personaje->HP_max       = ( stats.HP            + total_de_item.HP_extra )              * total_de_item.HP_mult;
    personaje->ATK_max      = ( stats.ATK           + total_de_item.ATK_extra )             * total_de_item.ATK_mult;
    personaje->ENERGY_max   = ( stats.ENERGY        + total_de_item.ENERGY_extra )          * total_de_item.ENERGY_mult;
    personaje->ARMOR        = ( stats.ARMOR         + total_de_item.ARMOR_extra )           * total_de_item.ARMOR_mult;
    personaje->COMBAT_SPEED = ( stats.COMBAT_SPEED  + total_de_item.COMBAT_SPEED_extra )    * total_de_item.COMBAT_SPEED_mult;
}

// Manejo de stats actuales
void descansar (t_character* personaje)
{
    personaje->HP_actual = personaje->HP_max;
    personaje->ENERGY_actual = personaje->ENERGY_max;
    reiniciar_todos_los_cd(personaje);
}

void desbloquear_movimiento(t_character* personaje, unsigned int movement_id)
{
    t_movements movimiento;
    for(int i = 0; i < personaje->personaje_template.cantidad_de_movimientos; i++){
        movimiento = devolver_movimiento(&personaje->personaje_template, i);
        if(movimiento.ID == movement_id){
            personaje->status.CD_counter[i] = 0;
            personaje->status.movement_unlocked_flag[i] = 1;
        }
    }
}


void reducir_cd(t_character* personaje)
{
    for(int i = 0; i < personaje->personaje_template.cantidad_de_movimientos; i++)
        if(personaje->status.movement_unlocked_flag[i])
            if(personaje->status.CD_counter[i] > 0)
                personaje->status.CD_counter[i]--;

}
void reiniciar_todos_los_cd(t_character* personaje)
{
    for(int i = 0; i < personaje->personaje_template.cantidad_de_movimientos; i++)
        if(personaje->status.movement_unlocked_flag[i])
                personaje->status.CD_counter[i] = 0;
}

//Utils

unsigned int devolver_id_personaje (t_character* personaje)
{
    return personaje->personaje_template.id;
}
