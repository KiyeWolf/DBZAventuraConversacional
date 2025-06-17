#include <stdio.h>
#include <stdlib.h>
#include "enemy_collection.h"
#include "game_manager.h"
#include "lector_de_texto.h"
#include "Combat_Manager.h"
#include "nodo.h"
#include "inventario.h"
#include "texto_condicionales.h"

void game_loop(t_gameState* game_state)
{
    t_nodo buffer_nodo;
    t_party_manager party;
    t_enemy_stats buffer_enemy[CANT_MAX_ENEMY];
    char* buffer_nombre;
    for(;;){
        buffer_nodo = retornar_nodo_por_id(game_state->nodo_actual);
        calcular_stats_actuales_manager(&game_state->character_manager);

        if(agregar_personaje_party(&party,
                                   &game_state->character_manager,
                                   buffer_nodo.party_habilitados_ids,
                                   buffer_nodo.tam_party))
        {
            printf("Error party");
            break;
        }

        if(buffer_nodo.es_hoguera == ES_HOGUERA){
            descansar_manager(&game_state->character_manager);
            llega_a_hoguera(&game_state->inventario, &party);
            guardar_partida(game_state);
            game_state->nodo_actual++;
            continue;
        }

        if(agregar_enemigos_ids(buffer_enemy,
                                buffer_nodo.enemy_ids,
                                buffer_nodo.cantidad_de_enemigos)){
            printf("Error enemigos");
            break;
        }

        buffer_nombre = devolverNombreDeArchSegunCodigo(buffer_nodo.id_del_archivo_de_texto[game_state->nodo_actual]);
        cinematica(buffer_nombre);

        if(buffer_nodo.hay_pelea == HAY_PELEA) {
            system("cls");
            printf("Comienza una pelea\nPresione una tecla para continuar");
            getchar();
            if(iniciar_combate(&party, buffer_enemy, buffer_nodo.cantidad_de_enemigos) == PERSONAJES_DERROTADOS){
                system("cls");
                printf("\nPersonajes derrotados, volviendo a inicio\n");
                break;
            }
        }
        for(int i = 0; i < buffer_nodo.cantidad_de_items; i++){
            guardar_item(&game_state->inventario, buffer_nodo.items_ids[i]);
        }

        if(buffer_nodo.branchea == HAY_BRANCH){
            if(buffer_nodo.id_del_archivo_de_texto[1] == 8){
                system("cls");
                if(acertijo() == 0){
                    game_state->nodo_actual++;
                }
            }
            if(buffer_nodo.id_del_archivo_de_texto[1] == 33){
                system("cls");
                if(ayudarAVegeta() == 0){
                    game_state->nodo_actual++;
                }
            }
            if(buffer_nodo.id_del_archivo_de_texto[1] == 39){
                system("cls");
                if(perdonarAfreezer() == 0){
                    game_state->nodo_actual++;
                }
            }
        }
        if(game_state->nodo_actual == 43 || game_state->nodo_actual == 44)
        {
            system("cls");
            printf("Fin del juego, gracias por jugar");
            getchar();
            exit(0);
        }
        game_state->nodo_actual++;

    }
}

void llega_a_hoguera(t_inventory* inventario, t_party_manager* party)
{
    int opcion;
    printf("Has llegado a una hoguera, te sientes descansado, aqui puedes equipar a tus personajes\nPresiona 1 para equipar items, presiona 0 para continuar\n");

    do{

        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > 2){
            printf("Error, Vuelve a ingresar un valor\n");
            continue;
        }
        if(opcion == 0)
            break;
        mostrar_todos_los_items(inventario);

        printf("Elige el item que quieres equipar, 0 para salir\n");

        fflush(stdin);
        scanf("%d", &opcion);

        if(opcion == 0 ){
            system("cls");
            break;
        }

        if((int)opcion > 0 && (int)opcion <= TAM_INVENTARIO_SLOTS)
            intercambiar_item(inventario, party, opcion);

        system("cls");
        printf("Elige 1 para intercambiar otro item 0 para salir\n");

    } while(opcion != 0);
}

void mostrar_todos_los_items(t_inventory* inventario)
{
    t_retorno_item item;
    for(int i = 0, c=0; i < TAM_INVENTARIO_SLOTS; i++){
        item = devolver_item_por_id(devolver_item_id(inventario, i));
        printf("%d, %s\t", i + 1, item.retorno.NAME);
        if(c == 5){
            printf("\n");
            c = -1;
        }
        c++;
    }
}
void intercambiar_item(t_inventory* inventario,
                       t_party_manager* party,
                       int opcion)
{
    int opcion_personaje, resultado;
    printf("Elige el personaje:\n");
    for(int i = 0; i < party->cantidad; i++)
    {
        printf("%d. %s\n", i, party->personajes_arr[i]->personaje_template.NAME);
    }
    for(;;){
        fflush(stdin);
        scanf("%d", &opcion_personaje);
        if(opcion_personaje < 0 || opcion_personaje > party->cantidad - 1){
            printf("Error, vuelva a intentar\n");
        }
        break;
    }
    resultado = mostrar_items_party (party, opcion_personaje);

    int id = devolver_item_id(inventario, opcion - 1);
    agregar_item_personaje(party->personajes_arr[opcion_personaje], id);
    remover_item_inventario(inventario, opcion - 1);

    remover_item_personaje(party->personajes_arr[opcion_personaje], resultado);
    guardar_item(inventario, resultado);
}

int mostrar_items_party (t_party_manager* party, int personaje)
{
    int opcion;
    system("cls");
    printf("Elija que item quiere reemplazar\n");
    for(int i = 0; i < TAM_MAXIMO_EQUIPAMIENTO; i++){
        printf("%d. %s\n", i, party->personajes_arr[personaje]->equipo.items[i]);
    }
    for(;;){
        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > TAM_MAXIMO_EQUIPAMIENTO){
            printf("Seleccione una opcion valida\n");
            continue;
        }
        break;
    }

    return party->personajes_arr[personaje]->equipo.items[opcion].id;
}
void guardar_partida(t_gameState* game_state)
{
    FILE* fp;
    fp = fopen("partida_guardada.save", "wb");
    if(fp == NULL){
        printf("Error al guardar la partida\n");
        exit(1);
    }
    if(fwrite(game_state, sizeof(t_gameState), 1, fp) == 0)
    {
        printf("Error al guardar la partida\n");
        exit(0);
    }
    fclose(fp);
}
