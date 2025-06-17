#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MENU.h"
#include "game_manager.h"

void menu_generator(char *text,
     t_instruccion *instrucciones,
     int cantidad){
        int opcion;
        printf("\n\n%s\n", text);

        for(int i = 0; i < cantidad; i++)
            printf("||\t%d - %s. \n", (i + 1), instrucciones[i].name);

        printf("||\t");
        scanf("%d", &opcion);
        fflush(stdin);

        opcion -= 1;
        if(opcion < cantidad && opcion >= 0){
            printf("\n____________________________________________________________");
            instrucciones[opcion].funcion(instrucciones[opcion].argumento);
        }
        else{
            printf("||\tIngrese una opcion valida");
            printf("\n____________________________________________________________");
        }
}

void continuar(void *ptr){
    t_gameState* game_state = (t_gameState*)malloc(sizeof(t_gameState));
    if(game_state == NULL){
        printf("Error al reservar memoria");
        exit(3);
    }
    FILE* fp;
    fp = fopen("partida_guardada.save", "rb");
    if(fp == NULL){
        printf("Error al abrir el archivo de guardado NULL");
        exit(1);
    }
    if(fread(game_state, sizeof(t_gameState), 1, fp) == 0){
        printf("Error al abrir el archivo de guardado");
        exit(1);
    }
    system("cls");
    game_loop(game_state);
    free(game_state);
}


void nueva_partida(void *ptr){
    t_gameState* game_state = (t_gameState*)malloc(sizeof(t_gameState));
    if(game_state == NULL){
        printf("Error al reservar memoria");
        exit(3);
    }
    game_state->nodo_actual = 0;
    inicializar_inventario(&game_state->inventario);
    inicializar_personajes(&game_state->character_manager);
    system("cls");
    game_loop(game_state);
    free(game_state);
}



void quit(void *ptr){
    printf("\nGracias por usar el programa\n");
    getchar();
    exit(0);
}
