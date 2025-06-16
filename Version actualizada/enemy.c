#include "enemy.h"

unsigned int devolver_cantidad_de_movimientos (t_enemy_stats* enemigo)
{
    return enemigo->cantidad_de_movimientos;
}

unsigned int utilizar_movimiento_enemigo(t_enemy_stats* enemigo,
                                         unsigned int mov)
{
    if((int)(enemigo->ENERGY - enemigo->movs[mov].ENERGY_REQUIREMENTS) >= 0){
        enemigo->ENERGY -= enemigo->movs[mov].ENERGY_REQUIREMENTS;
        return enemigo->movs[mov].DAMAGE + enemigo->ATK;
    }
    return 0;
}

unsigned int recibir_ataque_enemigo(t_enemy_stats* enemigo,
                                    unsigned int damage)
{
    if ((int)(damage - enemigo->ARMOR) > 0){
        if(enemigo->HP <= (damage - enemigo->ARMOR))
            enemigo->HP = 0;
        else
            enemigo->HP -= damage - enemigo->ARMOR;
    }
    return enemigo->HP;
}

unsigned int atacar_personaje(t_enemy_stats* enemigo)
{
    return enemigo->ATK;
}
