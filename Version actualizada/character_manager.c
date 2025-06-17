#include "character_manager.h"
#include <stdio.h>

t_retorno_character devolver_personaje_manager_id (t_character_manager* personajes,
                                                   unsigned int id)
{
    t_retorno_character retorno;
    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++)
        if(devolver_id_personaje(&personajes->personajes_arr[i]) == id){
            retorno.estado_retorno = 1;
            retorno.retorno = &personajes->personajes_arr[i];
            return retorno;
        }
    retorno.estado_retorno = 0;
    return retorno;
}

unsigned int desbloquear_personajes_array_ids(t_character_manager* personajes,
                                              unsigned int* ids,
                                              unsigned int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        cambiar_estado_por_id(personajes, ids[i], 1);
    }
}

unsigned int cambiar_estado_por_id (t_character_manager* personajes,
                                    unsigned int id,
                                    unsigned int estado)
{
    if(estado != 1 && estado != 0)
        return 1;


    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++)
        if(devolver_id_personaje(&personajes->personajes_arr[i]) == id){
            personajes->flags_de_personajes_desbloqueados[i] = estado;
            return 0;
        }
    return 2;
}

unsigned int comprobar_estado (t_character_manager* personajes,
                                    unsigned int id)
{
    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++)
        if(devolver_id_personaje(&personajes->personajes_arr[i]) == id){
            return personajes->flags_de_personajes_desbloqueados[i];
        }
    return 2;
}

void descansar_manager(t_character_manager* personajes)
{
    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++)
        descansar(&personajes->personajes_arr[i]);
}

unsigned int inicializar_personajes(t_character_manager* personajes)
{
    unsigned int result = 0;
    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++){
        result = inicializar_personaje(&personajes->personajes_arr[i], i);
        personajes->flags_de_personajes_desbloqueados[i] = 0;
        if(result != 0)
            return result;
    }
    return 0;
}

int agregar_item_manager(t_character_manager* personajes,
                 unsigned int id_personaje,
                 unsigned int id)
{
    t_retorno_character resultado = devolver_personaje_manager_id(personajes, id_personaje);

    if(resultado.estado_retorno == 0){
        return 4;
    }

    return agregar_item_personaje(resultado.retorno, id);
}

int remover_item_manager(t_character_manager* personajes,
                 unsigned int id_personaje,
                 unsigned int id)
{
    t_retorno_character resultado = devolver_personaje_manager_id(personajes, id_personaje);

    if(resultado.estado_retorno == 0){
        return 4;
    }

    return remover_item_personaje(resultado.retorno, id);
}
void calcular_stats_actuales_manager(t_character_manager* personajes)
{
    for(int i = 0; i < CANTIDAD_DE_PERSONAJES; i++)
    {
        calcular_stats_actuales(&personajes->personajes_arr[i]);
    }
}
