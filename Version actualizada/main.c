#include <stdio.h>
#include <stdlib.h>

#include "character_manager.h"
#include "MENU.h"

int main()
{
   system("chcp 65001 <nul");
    int final=0;
   int esqueleto=0;
    char *secuencias[] = {
        "./ArchivosDeTexto/introduccion.txt",
        "./ArchivosDeTexto/caminoANamek.txt",
        "./ArchivosDeTexto/barNamek.txt",
        "./ArchivosDeTexto/caminoAGranja.txt",
        "./ArchivosDeTexto/siBatallaBandidos.txt",
        "./ArchivosDeTexto/granjaNamek.txt",
        "./ArchivosDeTexto/caminoABosqueRojo.txt",
        "./ArchivosDeTexto/bosqueRojoPreAcertijo.txt",
        "./ArchivosDeTexto/acertijoRtaCorrecta.txt",
        "./ArchivosDeTexto/acertijoRtaIncorrecta.txt",
        "./ArchivosDeTexto/caminoPorBosqueRojo.txt",
        "./ArchivosDeTexto/esqueletoAyuda.txt",
        "./ArchivosDeTexto/esqueletoNoAyuda.txt",
        "./ArchivosDeTexto/temploBosqueRojo.txt",
        "./ArchivosDeTexto/temploBosqueRojoGuardianPrimerFase.txt",
        "./ArchivosDeTexto/temploBosqueRojoGuardianSegundaFase.txt",
        "./ArchivosDeTexto/segundaEsfera.txt",
        "./ArchivosDeTexto/postTemploBosqueRojo.txt",
        "./ArchivosDeTexto/postSoldadosBosqueRojo.txt",
        "./ArchivosDeTexto/ruidosInvestigados.txt",
        "./ArchivosDeTexto/caminoEsferaBrillante.txt",
        "./ArchivosDeTexto/tercerEsferaOPiccolo.txt",
        "./ArchivosDeTexto/seUnePiccolo.txt",
        "./ArchivosDeTexto/llanurasPrePiccolo.txt",
        "./ArchivosDeTexto/llanurasPostPiccolo.txt",
        "./ArchivosDeTexto/camaraDeFreezer.txt",
        "./ArchivosDeTexto/introLlanuraDeKihel.txt",
        "./ArchivosDeTexto/cobrarFavor.txt",
        "./ArchivosDeTexto/cobrarFavorNo.txt",
        "./ArchivosDeTexto/llanuraDeKihel.txt",
        "./ArchivosDeTexto/preVeggeta.txt",
        "./ArchivosDeTexto/postVeggeta.txt",
        "./ArchivosDeTexto/postGolemBatalla.txt",
        "./ArchivosDeTexto/encuentroFuerzasGyu.txt",
        "./ArchivosDeTexto/llegadaGoku.txt",
        "./ArchivosDeTexto/freezerMataADende.txt",
        "./ArchivosDeTexto/freezerPidePerdon.txt",
        "./ArchivosDeTexto/freezerNoPerdonado.txt",
        "./ArchivosDeTexto/freezerEsPerdonado.txt",
        "./ArchivosDeTexto/diosesJuzgando.txt",
        "./ArchivosDeTexto/finalBueno.txt",
        "./ArchivosDeTexto/finalMalo.txt"
    };
    IniciarSecuencia(0, secuencias);
    IniciarSecuencia(1, secuencias);
    // Si el tutorial es necesario, se puede descomentar la siguiente l�nea
        //if (tutorial())
        //el combate es con tutorial [LADRONES NAMEK]
        //Puede o no haber combate
    IniciarSecuencia(2, secuencias);
    //Altar
    IniciarSecuencia(3, secuencias);
    if(aceptarAyudarAnimales())
    {
        //se inicia un combate [BANDIDOS NAMEK]
        final++;
        IniciarSecuencia(4, secuencias);
    }

    IniciarSecuencia(5, secuencias);
//    se inicia un combate [SOLDADOS BASICOS]
    IniciarSecuencia(6, secuencias);

    IniciarSecuencia(7, secuencias);
    if (acertijo())
    {
        IniciarSecuencia(8, secuencias);
    }
    else
    {
        IniciarSecuencia(9, secuencias);
        //combate [BESTIAS DE LA NIEBLA]
    }
    IniciarSecuencia(10, secuencias);
   aceptarAyudaEsqueleto(&esqueleto);
    if(esqueleto)
    {
        IniciarSecuencia(11, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(12, secuencias);
        //combate [BESTIAS DE LA NIEBLA]
    }
    IniciarSecuencia(13, secuencias);


    //Dende se Une a la Party


    //Altar();
    IniciarSecuencia(14, secuencias);
    //combate [GUARDIAN DEL TEMPLO PRIMER FASE]
    IniciarSecuencia(15, secuencias);
    //combate [GUARDIAN DEL TEMPLO SEGUNDA FASE]
   IniciarSecuencia(16, secuencias);
    IniciarSecuencia(17, secuencias);
   // combate [SOLDADOS NORMALES]
    IniciarSecuencia(18, secuencias);
    //combate [SOLDADOS ELITE]
    IniciarSecuencia(19, secuencias);
    //combate [GOLEMS]
    IniciarSecuencia(20, secuencias);
    IniciarSecuencia(21, secuencias);
    IniciarSecuencia(22, secuencias);


    //Piccolo se une a la Party


   // Altar();
   if (investigarRuidos())
    {
        IniciarSecuencia(23, secuencias);
        //combate [GOLEMS]
    }
    IniciarSecuencia(24, secuencias);
    //MECANICA DE BOTONES

    sonidista();

    IniciarSecuencia(25, secuencias);



    IniciarSecuencia(26, secuencias);
    IniciarSecuencia(27, secuencias);
    //batalla [SOLDADOS ELITE]
    IniciarSecuencia(28, secuencias);
    Altar();
    IniciarSecuencia(29, secuencias);
    IniciarSecuencia(30, secuencias);
    if(esqueleto)
    {
        IniciarSecuencia(31, secuencias);
        //combate []
    }
    else{
        IniciarSecuencia(32, secuencias);
    }
    IniciarSecuencia(33, secuencias);
    //combate [SOLDADOS DE VEGGETA]
    IniciarSecuencia(34, secuencias);
    IniciarSecuencia(35, secuencias);
    if(!rodearGolem())
    {
        IniciarSecuencia(36, secuencias);
        //combate [GOLEM]
    }
    else
    {
        final++;
    }
    //Altar();

    IniciarSecuencia(37, secuencias);

    //Se unio Veggeta a la Party

    //combate [Fuerzas Gyu]
    IniciarSecuencia(38, secuencias);
    //comabate [Frezer]

    IniciarSecuencia(39, secuencias);

    //Ya estamos con Gok�
    //combate [FreezerGoku]
    IniciarSecuencia(40, secuencias);

    if(!perdonarAfreezer())
    {
        IniciarSecuencia(41, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(42, secuencias);
    }
    IniciarSecuencia(43, secuencias);
    if(final>1)
    {
        IniciarSecuencia(44, secuencias);
    }
    else
    {
        IniciarSecuencia(45, secuencias);
    }
    puts("FIN DEL JUEGO");
    return 0;
}





    /*
    t_character_manager personajes;

    inicializar_personajes(&personajes);

    printf("NOMBRE %s\n", personajes.personajes_arr[0].personaje_template.NAME);
    printf("HP ACUTAL %d\n", personajes.personajes_arr[0].HP_actual);
    printf("TIENE ARMADURA %d\n", personajes.personajes_arr[0].ARMOR);
    recibir_ataque(&personajes.personajes_arr[0], 15);
    printf("RECIBE DA�O %d\n", personajes.personajes_arr[0].HP_actual);

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
    */
