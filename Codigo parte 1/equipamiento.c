#include "equipamiento.h"
#include "item_collection.h"

int inicializar_equipamiento(t_equipamiento* equipamiento)
{
    t_retorno_item resultado = devolver_item_por_id(ITEM_VACIO);
    if(resultado.estado_del_retorno == 0)
        return 1;

    equipamiento->cantidad = 0;
    for(int i = 0; i < TAM_MAXIMO_EQUIPAMIENTO; i++)
        equipamiento->items[i] = resultado.retorno;

    return 0;
}

t_item devolver_stats_acumulados(t_equipamiento* equipamiento)
{
    t_item total = { "",
        0, 0, 0, 0,
        1, 1, 1, 1, 0, 1
    };

    for(int i = 0; i < equipamiento->cantidad; i++){
        total.HP_extra += equipamiento->items[i].HP_extra;
        total.ATK_extra += equipamiento->items[i].ATK_extra;
        total.ENERGY_extra += equipamiento->items[i].ENERGY_extra;
        total.ARMOR_extra += equipamiento->items[i].ARMOR_extra;
        total.COMBAT_SPEED_extra += equipamiento->items[i].COMBAT_SPEED_extra;

        total.HP_mult *= equipamiento->items[i].HP_mult;
        total.ATK_mult *= equipamiento->items[i].ATK_mult;
        total.ENERGY_mult *= equipamiento->items[i].ENERGY_mult;
        total.ARMOR_mult *= equipamiento->items[i].ARMOR_mult;
        total.COMBAT_SPEED_mult *= equipamiento->items[i].COMBAT_SPEED_mult;
    }
    return total;
}
