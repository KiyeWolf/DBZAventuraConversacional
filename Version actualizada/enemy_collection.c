#include "enemy_collection.h"

t_enemy_stats enemy_collection[CANTIDAD_DE_ENEMIGOS] = {
    {
       "ENEMIGO VACIO",
        0,
        0, 0, 0, 0, 0,
        {}
    },
    {
        "SOLDADO BASICO",
        4.0f,
        50, 20, 5, 0, 2,
        {
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "BANDIDOS",
        5.0f,
        50, 20, 5, 0, 2,
        {
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "BESTIAS DE LA NIEBLA",
        5.0f,
        60, 20, 5, 0, 2,
        {
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "GUARDIAN",
        5.0f,
        100, 30, 8, 1, 2,
        {
            { "Onda de energia", 30, 1, 1 },
            { "Carga agresiva", 40, 2, 1 }
        }
    },
    {
       "GUARDIAN FASE DOS",
        5.0f,
        100, 35, 8, 1, 2,
        {
            { "Onda de energia", 30, 1, 1 },
            { "Carga agresiva", 40, 2, 1 }
        }
    },
    {
       "SOLDADO FREEZER ELITE",
        5.0f,
        100, 40, 8, 2, 2,
        {
            { "Onda de energia", 30, 1, 1 },
            { "Ataque desde arriba", 60, 3, 1 }
        }
    },
    {
       "GOLEM NAMEKIANO",
        7.0f,
        120, 40, 8, 4, 2,
        {
            { "Finta", 20, 1, 1 },
            { "Ataque fuerte", 60, 5, 1 }
        }
    },
    {
       "SOLDADOS INTERMEDIOS",
        8.0f,
        80, 25, 5, 1, 2,
        {
            { "Ataque rapido", 30, 1, 1 },
            { "Carga", 40, 2, 1 }
        }
    },
    {
       "HOLOGRAMA_DE_FREEZER",
        8.0f,
        120, 40, 10, 4, 2,
        {
            { "Bola de energia", 45, 1, 1 },
            { "Onda de choque", 60, 2, 1 }
        }
    },
    {
       "SOLDADOS_SAIYAJIN",
        9.0f,
        100, 40, 8, 4, 2,
        {
            { "Ataque Sayajin", 80, 5, 1 },
            { "Carga", 40, 2, 1 }
        }
    },
    {
       "VEGETA ENEMIGO",
        9.0f,
        200, 40, 8, 10, 3,
        {
            { "Garlic Ho", 50, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "GHURD",
        10.0f,
        80, 15, 10, 8, 1,
        {
            { "Telequinesis", 35, 2, 2 }
        }
    },
    {
       "JHEESE",
        10.0f,
        120, 40, 8, 10, 3,
        {
            { "Rush", 50, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "BULTA",
        10.0f,
        120, 40, 8, 10, 3,
        {
            { "Rush", 50, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "RACOOM",
        10.0f,
        120, 40, 8, 10, 3,
        {
            { "Rayo rojo", 50, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "GINEW",
        12.0f,
        300, 40, 8, 10, 3,
        {
            { "Posesion", 70, 2, 2 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },
    {
       "FREEZER",
        12.0f,
        1200, 80, 20, 10, 3,
        {
            { "Bola de energia", 100, 8, 3 },
            { "Ataque rapido", 20, 1, 1 },
            { "Carga", 30, 2, 1 }
        }
    },

};

t_retorno_enemigo devolver_enemigo_por_id(unsigned int id)
{
    t_retorno_enemigo retorno;
    if(id >= CANTIDAD_DE_ENEMIGOS){
        retorno.estado = 0;
        return retorno;
    }
    retorno.estado = 1;
    retorno.retorno = enemy_collection[id];
    return retorno;
}
