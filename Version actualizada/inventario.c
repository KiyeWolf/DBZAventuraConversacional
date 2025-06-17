#include "inventario.h"


void inicializar_inventario(t_inventory* inventario)
{
    inventario->cantidad_de_ocupados_inventario = 0;
    for(int i = 0; i < TAM_INVENTARIO_SLOTS; i++)
        inventario->id[i] = ITEM_VACIO;
}

unsigned int guardar_item (t_inventory* inventario,
                           unsigned int id)
{
    if(inventario->cantidad_de_ocupados_inventario >= TAM_INVENTARIO_SLOTS)
        return 1;
    inventario->cantidad_de_ocupados_inventario++;
    for(int i = 0; i < TAM_INVENTARIO_SLOTS; i++)
        if(inventario->id[i] == ITEM_VACIO){
            inventario->id[i] = id;
            return 0;
        }
    return 2;

}

unsigned int remover_item_inventario (t_inventory* inventario,
                           unsigned int pos)
{
    if(inventario->cantidad_de_ocupados_inventario <= 0)
        return ITEM_VACIO;

    unsigned int retorno = inventario->id[pos];

    if(retorno == 0)
        return ITEM_VACIO;

    inventario->cantidad_de_ocupados_inventario--;
    inventario->id[pos] = ITEM_VACIO;

    return retorno;
}
unsigned int devolver_item_id (t_inventory* inventario,
                               unsigned int pos)
{
    return inventario->id[pos];
}
