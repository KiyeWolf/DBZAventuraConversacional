#include "character_collection.h"

t_character_template character_collection_array[CANTIDAD_DE_PERSONAJES] =
{
    {
        GOKU,
        "GOKU",
        {
            300, 40, 40, 15, 9.0f
        },
        4,
        {
            { "Kame Hame Ha", 60, 2, 2 },
            { "Genki Dama", 100, 20, 10 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
        GOHAN,
        "GOHAN",
        {
            70, 10, 10, 5, 5.0f
        },
        3,
        {
            { "Masenko", 30, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
        KRILLIN,
        "KRILLIN",
        {
            70, 10, 10, 5, 5.0f
        },
        3,
        {
            { "Disco", 30, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
        VEGETA,
        "VEGETA",
        {
            200, 30, 30, 10, 7.0f
        },
        4,
        {
            { "Garlic Ho", 50, 2, 2 },
            { "Resplandor final", 70, 20, 10 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
        PICCOLO,
        "PICCOLO",
        {
            200, 30, 30, 10, 7.0f
        },
        4,
        {
            { "Makouhou", 50, 2, 2 },
            { "Makankosappo", 70, 20, 10 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
        GOKU_SSJ,
        "GOKU SSJ",
        {
            900, 100, 70, 30, 13.0f
        },
        4,
        {
            { "Kame Hame Ha", 170, 2, 2 },
            { "Genki Dama", 300, 20, 10 },
            { "Ataque rapido", 80, 1, 1 },
            { "Carga", 100, 2, 1 }
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


