#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MENU.h"

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
    printf("Nueva partida");
}


void nueva_partida(void *ptr){

}



void quit(void *ptr){
    printf("\nGracias por usar el programa\n");
    getchar();
    exit(0);
}
