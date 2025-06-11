#include "item_collection.h"

t_item item_collection[] =
{
    {
        "VACIO", ITEM_VACIO,
        0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    },
    {
        "BOTAS", BOTAS,
        0,0,0,1,
        0,0,0,0,0,0
    }
};

t_retorno_item devolver_item_por_id(unsigned int id)
{
    t_retorno_item retorno;
    if(id >= CANTIDAD_DE_ITEMS || id < 0)
        retorno.estado_del_retorno = 0;
    else{
        retorno.estado_del_retorno = 1;
        retorno.retorno = item_collection[id];
    }
    return retorno;
}
