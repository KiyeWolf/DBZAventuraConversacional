#include <stdio.h>
#include <stdlib.h>

#include "character_manager.h"
#include "MENU.h"

#include "lector_de_texto.h"
#include "texto_condicionales.h"

#include "Combat_Manager.h"
#include "party.h"
#include "nodo.h"

#include "enemy_collection.h"

int main()
{
    int cantidad;

    //OPCIONES DE MENU
    t_instruccion MENU[] = {
        { "Nueva Partida", NULL, nueva_partida },
        { "Continuar", NULL, continuar },
        { "Salir", NULL, quit }
    };
    cantidad = (int)(sizeof(MENU)/sizeof(t_instruccion));

    // LOOP DE MENU
    for(;;)
        menu_generator("MAIN_MENU", MENU, cantidad);

    return 0;
}
