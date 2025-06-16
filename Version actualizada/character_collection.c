#include "character_collection.h"

t_character_template character_collection_array[CANTIDAD_DE_PERSONAJES] =
{
    {
        GOKU,
        "GOKU",
        {
            150, 30, 30, 10, 9.0f
        },
        4,
        {
            { "Kame Hame Ha", 10, 2, 2 },
            { "Genki Dama", 50, 20, 10 },
            { "Ataque rapido", 5, 1, 1 },
            { "Carga", 8, 2, 1 }
        }
    }
    {
        GOHAN,
        "GOHAN",
        {
            70, 10, 10, 5, 5.0f
        },
        4,
        {
            { "Masenko", 30, 2, 2 },
            { "Kame Hame Ha", 70, 20, 10 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    }
};
t_retorno_template devolver_template_por_id(unsigned int id)
{
    t_retorno_template retorno;
    if(id >= CANTIDAD_DE_PERSONAJES || id < 0)
        retorno.estado_del_retorno = 0;
    else{
        retorno.estado_del_retorno = 1;
        retorno.retorno = character_collection_array[id];
    }
    return retorno;
}


