#include <stdio.h>
#include <stdlib.h>

#include "character_manager.h"


int main()
{

    t_character_manager personajes;

    inicializar_personajes(&personajes);

    printf("NOMBRE %s\n", personajes.personajes_arr[0].personaje_template.NAME);
    printf("HP ACUTAL %d\n", personajes.personajes_arr[0].HP_actual);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    recibir_ataque(&personajes.personajes_arr[0], 15);
    printf("RECIBE DAÑO %d\n", personajes.personajes_arr[0].HP_actual);

    curar_personaje(&personajes.personajes_arr[0], 13);
    printf("SE CURA %d\n", personajes.personajes_arr[0].HP_actual);

    personajes.personajes_arr[0].HP_actual = 0;
    resucitar_personaje(&personajes.personajes_arr[0]);
    printf("RESUCITA %d\n", personajes.personajes_arr[0].HP_actual);

    printf("ATACA %d\n", atacar_enemigo(&personajes.personajes_arr[0]));

    printf("TIENE ENERGIA %d\n", personajes.personajes_arr[0].ENERGY_actual);
    printf("CD %d\n", personajes.personajes_arr[0].personaje_template.MOVS[0].CD);
    printf("CD COUNTER %d\n", personajes.personajes_arr[0].status.CD_counter[0]);
    printf("ESTA DESBLOQUEADO %d\n", personajes.personajes_arr[0].status.movement_unlocked_flag[0]);
    printf("UTILIZA MOVIMIENTO %s %d\n", personajes.personajes_arr[0].personaje_template.MOVS[0].NAME ,utilizar_movimiento(&personajes.personajes_arr[0], 0));

    desbloquear_movimiento(&personajes.personajes_arr[0], 0);
    printf("ESTA DESBLOQUEADO %d\n", personajes.personajes_arr[0].status.movement_unlocked_flag[0]);
    printf("CD %d\n", personajes.personajes_arr[0].personaje_template.MOVS[0].CD);
    printf("CD COUNTER %d\n", personajes.personajes_arr[0].status.CD_counter[0]);
    printf("UTILIZA MOVIMIENTO %s %d\n", personajes.personajes_arr[0].personaje_template.MOVS[0].NAME ,utilizar_movimiento(&personajes.personajes_arr[0], 0));
    printf("TIENE ENERGIA %d\n", personajes.personajes_arr[0].ENERGY_actual);

    printf("ACTIVACION %d\n", cambiar_estado_por_id(&personajes, GOKU, 1));
    printf("ACTIVADO %d\n", personajes.flags_de_personajes_desbloqueados[0]);
    printf("ITEM 0 ID %d NOMBRE %s\n", personajes.personajes_arr[0].equipo.items[0].id, personajes.personajes_arr[0].equipo.items[0].NAME);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d\n", agregar_item_manager(&personajes, GOKU, BOTAS));
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);

    printf("ITEM 0 ID %d NOMBRE %s\n", personajes.personajes_arr[0].equipo.items[0].id, personajes.personajes_arr[0].equipo.items[0].NAME);


    printf("ITEM 0 ID %d NOMBRE %s\n", personajes.personajes_arr[0].equipo.items[0].id, personajes.personajes_arr[0].equipo.items[0].NAME);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d, CANTIDAD %d\n", remover_item_manager(&personajes, GOKU, BOTAS), personajes.personajes_arr[0].equipo.cantidad);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d, CANTIDAD %d\n", remover_item_manager(&personajes, GOKU, BOTAS), personajes.personajes_arr[0].equipo.cantidad);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d, CANTIDAD %d\n", remover_item_manager(&personajes, GOKU, BOTAS), personajes.personajes_arr[0].equipo.cantidad);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    printf("RESULTADO %d, CANTIDAD %d\n", remover_item_manager(&personajes, GOKU, BOTAS), personajes.personajes_arr[0].equipo.cantidad);

    descansar_manager(&personajes);

    getchar();
    return 0;
}
