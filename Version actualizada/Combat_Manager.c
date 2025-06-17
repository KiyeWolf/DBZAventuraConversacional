#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Combat_Manager.h"

int iniciar_combate(t_party_manager* party, t_enemy_stats enemigos[], int cantidad_enemigos)
{
    srand(time(NULL));
    t_combate combate;
    combate.party = party;
    for(int i = 0; i < CANT_MAX_ENEMY; i++)
        combate.enemigos[i] = enemigos[i];
    combate.cantidad_enemigos = cantidad_enemigos;

    t_combatiente combatientes[CANT_MAX_ENEMY + PARTY_MAX];

    int total=0;
    for (int i = 0; i < combate.party->cantidad; i++)//necesito que party tenga una variable cantidad.
    {
        combatientes[total++] = (t_combatiente){JUGADOR, i, 0};
    }


    for (int i = 0; i < combate.cantidad_enemigos; i++)
    {
        combatientes[total++] = (t_combatiente){ENEMIGO, i, 0};
    }

    return ciclo_combate(combatientes, total, &combate);
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void mostrar_vida_combatientes(t_combatiente combatientes[], int total, t_combate* combate){
    int contador_party=0;
    int contador_enemigo=0;
    char buff_e_t[512]= "Enemigos:\n", buff_p_t[512] = "Personajes liados:\n", buff[100];

    for(int i = 0; i < total; i++){
        if(combatientes[i].tipo == ENEMIGO){
            if(combate->enemigos[contador_enemigo].HP > 0){
                sprintf(buff,"Nombre: %s, Vida:%d, ATK: %d\n",
                        combate->enemigos[contador_enemigo].NAME,
                        combate->enemigos[contador_enemigo].HP,
                        combate->enemigos[contador_enemigo].ATK);
                strcat(buff_e_t,buff);
            }
            contador_enemigo++;
        }


        else if(combatientes[i].tipo == JUGADOR){
            if(combate->party->personajes_arr[contador_party]->HP_actual > 0){
                sprintf(buff,"Nombre: %s, Vida:%d, ATK: %d\n",
                        combate->party->personajes_arr[contador_party]->personaje_template.NAME,
                        combate->party->personajes_arr[contador_party]->HP_actual,
                        combate->party->personajes_arr[contador_party]->ATK_max);
                strcat(buff_p_t,buff);
            }
            contador_party++;
        }

    }
    printf("%s%s\n\n", buff_p_t, buff_e_t);
}
int ciclo_combate(t_combatiente combatientes[], int total, t_combate* combate)
{
    int combate_terminado=0;
    int contador_party;
    int contador_enemigo;

    while (!combate_terminado)
    {
        contador_enemigo = 0;
        contador_party = 0;
        for (int i=0; i<total; i++)
        {
            if(combatientes[i].tipo == ENEMIGO){
                if(!(combate->enemigos[contador_enemigo].HP > 0)){
                    contador_enemigo++;
                    continue;
                } else {
                    combatientes[i].contador_turno += combate->enemigos[contador_enemigo].COMBAT_SPEED;
                    contador_enemigo++;
                }
            }
            else if(combatientes[i].tipo == JUGADOR){
                if(!(combate->party->personajes_arr[contador_party]->HP_actual > 0)){
                    contador_party++;
                    continue;

                }   else {
                    combatientes[i].contador_turno += combate->party->personajes_arr[contador_party]->COMBAT_SPEED;
                    contador_party++;
                }
            }
            if (combatientes[i].contador_turno >= CICLO_TURNO)
            {
                mostrar_vida_combatientes(combatientes, total, combate);
                ejecutar_turno(&combatientes[i], combate);
                combatientes[i].contador_turno = 0;
                printf("\n\nToque enter para continuar al siguiente turno\n\n");
                getchar();
                system("cls");
                break;//salimos para que se ejecute solo una accion.
            }
        }
        combate_terminado = fin_combate(combate, combatientes, total);

    }
    return combate_terminado;
}

void ejecutar_turno(t_combatiente* c, t_combate* combate) {
    int opcion1, opcion2, objetivos[combate->cantidad_enemigos], band=0, todo_correcto, cantidad_de_enemigos_vivos;
    unsigned int danio = 0;
    t_enemy_stats* enemigo;

    if (c->tipo == JUGADOR)
    {
        t_character* pj = combate->party->personajes_arr[c->id];
        reducir_cd(pj);
        do{


            for(int i = 0, cantidad_de_enemigos_vivos = 0; i < combate->cantidad_enemigos; i++)
            {
                if (combate->enemigos[i].HP > 0)
                {
                    objetivos[i] = 1;
                    band=1;
                }
                else{
                    objetivos[i] = 0;
                }
            }

            if(band=0)
            {
                printf("No hay enemigos vivos.\n");
                return;
            }

            do
            {
                printf("\n--Turno de %s--\n", pj->personaje_template.NAME);//estaria bueno agregar "nombre" a la estructura t_character
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
                    printf("Elija un objetivo.\n");

                    for(int i=0; i < combate->cantidad_enemigos; i++)
                    {
                        if(objetivos[i]==1)
                        {
                            printf("Ingrese %d: %s.\n", i+1, combate->enemigos[i].NAME);
                        }
                    }
                    for(;;){
                        scanf("%d", &opcion2);
                        if(objetivos[ opcion2 - 1 ] == 1){
                            break;
                        }
                        printf("Error, ingrese un numero valido\n");
                    }

                    if(opcion2<1 || opcion2>combate->cantidad_enemigos)
                        printf("Enemigo invalido. Intente otra vez.\n");

                }while(opcion2<1 || opcion2>combate->cantidad_enemigos);

                enemigo = &combate->enemigos[opcion2-1];
            }
            int input;

                switch(opcion1)
                {
                case 1:
                    danio = atacar_enemigo(pj);
                    enemigo->HP = recibir_ataque_enemigo(enemigo, danio); //Hay que definir esta función
                    printf("%s inflige %d de daño a %s\n", pj->personaje_template.NAME, danio, enemigo->NAME);
                    break;

                case 2:
                    printf("Elije el movimiento a utilizar\n");
                    for(int i = 0; i < pj->personaje_template.cantidad_de_movimientos; i++){
                        printf("%d. %s\n",i, pj->personaje_template.MOVS[i].NAME);
                    }
                    scanf("%d", &input);
                    danio = utilizar_movimiento(pj, input); //usar primer movimiento por ahora.
                    if(danio == ENERGIA_INSUFICIENTE)
                        printf("Energia insuficiente\nElija otra opcion\n");
                    if(danio == AUN_ESPERANDO_CD)
                        printf("Aun esperando CD\nElija otra opcion\n");
                    if(((int)danio) > 0){
                        enemigo->HP = recibir_ataque_enemigo(enemigo, danio); //Hay que definir esta función
                        printf("%s inflige %d de daño a %s\n", pj->personaje_template.NAME, danio, enemigo->NAME);
                    }
                    todo_correcto = danio;
                    break;

                case 3:
                    curar_personaje(pj, pj->HP_max/7);//que pongo en el parametro HEAL?
                    break;

                default:
                    printf("Opcion invalida.\n");
                }
        } while(todo_correcto < 0);
    }

    else if (c->tipo == ENEMIGO)
    {
        t_enemy_stats* enemigo = &combate->enemigos[c->id];

        // Elegir personaje aleatorio con vida
        int objetivo = -1;
        do
        {
            objetivo = random_int(0, combate->party->cantidad - 1);
        }while(combate->party->personajes_arr[objetivo]->HP_actual <= 0);

        t_character* pj = combate->party->personajes_arr[objetivo];

        if(random_int(0, 3) > 2){
            int movimiento = random_int(0, enemigo->cantidad_de_movimientos - 1);
            danio = enemigo->movs[movimiento].DAMAGE + enemigo->ATK;
            printf("%s ataca con movimiento %s a %s y hace %d de daño\n",enemigo->NAME, enemigo->movs[movimiento].NAME, pj->personaje_template.NAME, danio - pj->ARMOR);
        }
        else{
            danio = enemigo->ATK;
            printf("%s ataca a %s y hace %d de daño\n",enemigo->NAME, pj->personaje_template.NAME, danio - pj->ARMOR);
        }

        pj->HP_actual = recibir_ataque(pj, danio);

    }
}

int fin_combate(t_combate* combate, t_combatiente combatientes[], int total_combatientes)
{
    int jugadores_vivos = 0;
    int enemigos_vivos = 0;

    for (int i = 0, e = 0, j = 0; i < total_combatientes; i++)
    {
        if (combatientes[i].tipo == JUGADOR){
            if (combate->party->personajes_arr[j]->HP_actual > 0)
            {
                jugadores_vivos++;
            }
            j++;
        }
        else if (combatientes[i].tipo == ENEMIGO){
            if(combate->enemigos[e].HP > 0){
                enemigos_vivos++;
            }
            e++;
        }
    }

    if (jugadores_vivos == 0)
    {
        printf("Todos los personajes fueron derrotados. Combate fallido.\n");
        return PERSONAJES_DERROTADOS;
    }

    if (enemigos_vivos == 0)
    {
        printf("Todos los enemigos fueron derrotados. Combate exitoso!\n");
        return ENEMIGOS_DERROTADOS;
    }

    return CONTINUA;
}
