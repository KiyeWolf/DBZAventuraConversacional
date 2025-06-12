#include <stdio.h>
#include "Combat_Manager.h"

void inicializar_combatientes(t_combatiente combatientes[], t_combate* combate, int* total)
{
    int num=0;

    for (int i = 0; i < combate->party->cantidad; i++)
    {
        combatientes[num].tipo = JUGADOR;
        combatientes[num].id = i;
        combatientes[num].velocidad = combate->party->miembros[i].personaje_template.stats.COMBAT_SPEED;
        combatientes[num].hp_actual = combate->party->miembros[i].HP_actual;
        combatientes[num].contador_turno = 0;
        num++;
    }

    for (int i = 0; i < combate->cantidad_enemigos; i++)
    {
        combatientes[num].tipo = ENEMIGO;
        combatientes[num].id = i;
        combatientes[num].velocidad = combate->enemigos[i].COMBAT_SPEED;
        combatientes[num].hp_actual = combate->enemigos[i].HP;
        combatientes[num].contador_turno = 0;
        num++;
    }

    *total=num;
}

void ciclo_combate(t_combatiente combatientes[], int total, t_combate* combate)
{
    int combate_terminado=0;

    while (!combate_terminado)
    {
        for (int i=0; i<total; i++)
        {
            if (combatientes[i].hp_actual > 0)
            {
                combatientes[i].contador_turno += combatientes[i].velocidad;
            }
        }

        for (int i=0; i<total; i++)
        {
            if (combatientes[i].hp_actual > 0 && combatientes[i].contador_turno >= 100)
            {
                ejecutar_turno(&combatientes[i], combate);
                combatientes[i].contador_turno = 0;
                break;//salimos para que se ejecute solo una accion
            }
        }
        // Me falta hacer la funcion para verificar el fin combate
    }
}

void ejecutar_turno(t_combatiente* c, t_combate* combate)
{
    int opcion, objetivo=-1, danio=0;

    if (c->tipo == JUGADOR)
    {
        t_character* pj = &combate->party->miembros[c->id];

        printf("\n-Turno de %s\n", pj->nombre);

        do {
            printf("1. Ataque básico\n");
            printf("2. Ataque especial (-10 ENERGY)\n");
            scanf("%d", &opcion);
        } while (opcion != 1 && opcion != 2);

        for (int i = 0; i < combate->cantidad_enemigos; i++)
        {
            if (combate->enemigos[i].HP > 0)
            {
                objetivo = i;
                break;                       //Por ahora elige automaticamente al primer enemigo con vida.
            }
        }

        if (objetivo == -1)
        {
            printf("No hay enemigos vivos.\n");
            return;
        }

        t_enemy_stats* enemigo = &combate->enemigos[objetivo];

        if(opcion == 1)
        {
            danio = pj->ATK_max - enemigo->ARMOR;
        }else if (opcion == 2 && pj->ENERGY_actual >= 10)
        {
            danio = pj->ATK_max * 2 - enemigo->ARMOR;  //Formula provisoria hasta que haya habilidades
            pj->ENERGY_actual -= 10;
        }else {
            printf("No tenés energía suficiente.\n");
            return;
        }

        if (danio < 0)
            danio = 0;

        enemigo->HP -= danio;
        printf("%s hizo %d de daño a %s.\n", pj->nombre, danio, enemigo->NAME);

    }else if (c->tipo == ENEMIGO)
    {
        t_enemy_stats* enemigo = &combate->enemigos[c->id];

        if (enemigo->HP <= 0)
            return;

        objetivo = -1;
        for (int i=0; i < combate->party->cantidad; i++) {
            if (combate->party->miembros[i].HP_actual > 0) {
                objetivo = i;                                //Por ahora elige automaticamente al primer jugador con vida
                break;
            }
        }

        if (objetivo==-1)
            return;

        t_character* pj = &combate->party->miembros[objetivo];
        danio = enemigo->ATK - pj->personaje_template.stats.ARMOR;
        if(danio < 0)
            danio = 0;
        pj->HP_actual -= danio;

        printf("%s atacó a %s e hizo %d de daño.\n", enemigo->NAME, pj->nombre, danio);
    }
}
