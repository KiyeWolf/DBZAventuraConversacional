#include <stdio.h>
#include "Combat_Manager.h"

void iniciar_combate(t_party_manager* party, t_enemy_stats enemigos[], int cantidad_enemigos)
{
    srand(time(NULL));

    t_combate combate;
    combate.party = party;
    combate.enemigos[3] = enemigos[3];
    combate.cantidad_enemigos = cantidad_enemigos;

    t_combatiente combatientes[6]; // asumiendo 3 jugadores + 3 enemigos
    int total=0;

    for (int i = 0; i < party->cantidad; i++)//necesito que party tenga una variable cantidad.
    {
        combatientes[total++] = (t_combatiente){JUGADOR, i, 0};
    }

    for (int i = 0; i < cantidad_enemigos; i++)
    {
        combatientes[total++] = (t_combatiente){ENEMIGO, i, 0};
    }

    ciclo_combate(combatientes, total, &combate);
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void ciclo_combate(t_combatiente combatientes[], int total, t_combate* combate)
{
    int combate_terminado=0;

    while (!combate_terminado)
    {
        for (int i=0; i<total; i++)
        {
            if (combate->party->personajes_arr[i].HP_actual > 0)
            {
                combatientes[i].contador_turno += combate->party->personajes_arr[i].COMBAT_SPEED;
            }
        }

        for (int i=0; i<total; i++)
        {
            if (combate->party->personajes_arr[i].HP_actual > 0 && combatientes[i].contador_turno >= CICLO_TURNO)
            {
                ejecutar_turno(&combatientes[i], combate);
                combatientes[i].contador_turno = 0;
                break;//salimos para que se ejecute solo una accion.
            }
        }
        combate_terminado=fin_combate(combate, combatientes, total);
    }
}

void ejecutar_turno(t_combatiente* c, t_combate* combate) {
    int opcion1, opcion2, objetivos[combate->cantidad_enemigos], band=0;
    unsigned int danio = 0;

    if (c->tipo == JUGADOR)
    {
        t_character* pj = &combate->party->personajes_arr[c->id];

        for(int i = 0; i < combate->cantidad_enemigos; i++)
        {
            if (combate->enemigos[i].HP > 0)
            {
                objetivos[i] = 1;
                band=1;
            }
        }

        if(band=0)
        {
            printf("No hay enemigos vivos.\n");
            return;
        }

        do
        {
            printf("\n--Turno de %s--\n", pj->nombre);//estaria bueno agregar "nombre" a la estructura t_character
            printf("1. Ataque básico.\n");
            printf("2. Ataque especial.\n");
            printf("3. Curacion.\n");
            scanf("%d", &opcion1);
            if(opcion1<1 && opcion1>3)
                printf("Opcion invalida.\n");
        }while(opcion1<1 && opcion1>3);

        if(opcion1!=3)
        {
            do
            {
                printf("Elija un objetivo.");

                for(int i=0; i < combate->cantidad_enemigos; i++)
                {
                    if(objetivos[i]==1)
                    {
                        printf("Enemigo %d.\n", i+1);
                    }
                }
                scanf("%d", &opcion2);
                if(opcion2<1 || opcion2>combate->cantidad_enemigos)
                    printf("Enemigo invalido. Intente otra vez.\n");
            }while(opcion2<1 || opcion2>combate->cantidad_enemigos);

            t_enemy_stats* enemigo = &combate->enemigos[opcion2-1];
        }

        switch(opcion1)
        {
            case 1:
                danio = atacar_enemigo(pj);
                enemigo->HP = recibir_ataque_enemigo(enemigo, danio); //Hay que definir esta función
                printf("%s inflige %d de daño a %s\n", pj->nombre, danio, enemigo->NAME);
                break;

            case 2:
                danio = utilizar_movimiento(pj, 0); //usar primer movimiento por ahora.
                enemigo->HP = recibir_ataque_enemigo(enemigo, danio); //Hay que definir esta función
                printf("%s inflige %d de daño a %s\n", pj->nombre, danio, enemigo->NAME);
                break;

            case 3:
                curar_personaje(pj);//que pongo en el parametro HEAL?
                break;

            default:
                printf("Opcion invalida.\n");
        }
    }

    else if (c->tipo == ENEMIGO)
    {
        t_enemy_stats* enemigo = &combate->enemigos[c->id];

        // Elegir personaje aleatorio con vida
        int objetivo = -1;
        do
        {
            objetivo = random_int(0, combate->party->cantidad - 1);
        }while(combate->party->personajes_arr[objetivo].HP_actual <= 0);

        t_character* pj = &combate->party->personajes_arr[objetivo];

        int movimiento = random_int(0, enemigo->cantidad_de_movimientos - 1);
        danio = enemigo->ATK;

        pj->HP_actual = recibir_ataque(pj, danio);

        printf("%s ataca a %s y hace %d de daño\n",enemigo->NAME, pj->nombre, danio);
    }
}

int fin_combate(t_combate* combate, t_combatiente combatientes[], int total_combatientes)
{
    int jugadores_vivos = 0;
    int enemigos_vivos = 0;

    for (int i = 0; i < total_combatientes; i++)
    {
        if (combate->party->personajes_arr[i].HP_actual > 0)
        {
            if (combatientes[i].tipo == JUGADOR)
                jugadores_vivos++;
            else if (combatientes[i].tipo == ENEMIGO)
                enemigos_vivos++;
        }
    }

    if (jugadores_vivos == 0)
    {
        printf("Todos los personajes fueron derrotados. Combate fallido.\n");
        return 1;
    }

    if (enemigos_vivos == 0)
    {
        printf("Todos los enemigos fueron derrotados. Combate exitoso!\n");
        return 1;
    }

    return 0;
}
