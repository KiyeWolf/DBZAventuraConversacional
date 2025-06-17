#include "item_collection.h"

t_item item_collection[] =
{
    {
        "VACIO",
        0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    },
    {
        "POSION DE SALUD",
        20,0,0,0,
        0,0,0,0,0,0
    },
    {
        "POSION DE PODER",
        0,20,0,0,
        0,0,0,0,0,0
    },
    {
        "POSION DE VIGOR",
        0,0,20,0,
        0,0,0,0,0,0
    },
    {
        "TRAJE REFORZADO",
        0,0,0,10,
        0,0,0,0,0,0
    },
    {
        "GEMA DE SALUD",
        0,0,0,0,
        1.2,0,0,0,0,0
    },
    {
        "GEMA DE PODER",
        0,0,0,0,
        0,1.2,0,0,0,0
    },
    {
        "GEMA DE VIGOR",
        0,0,0,0,
        0,0,1.3,0,0,0
    },
    {
        "TRAJE ENCANTADO",
        0,0,0,0,
        0,0,0,1.15,0,0
    },
    {
        "BOTAS ENCANTADAS",
        0,0,0,0,
        0,0,0,0,1.3,0
    },
    {
        "BOTAS ANTIGUAS",
        0,0,0,0,
        0,0,0,0,0,8
    },
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
