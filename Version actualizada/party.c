#include "party.h"
#include <stdio.h>
unsigned int agregar_personaje_party(t_party_manager* party,
                                     t_character_manager* manager,
                                     unsigned int* ids,
                                     unsigned int cantidad_de_personajes_party)
{
    t_retorno_character resultado;
    int i = 0;
    for(i; i < cantidad_de_personajes_party; i++)
    {
        resultado = devolver_personaje_manager_id(manager, ids[i]);
        if(resultado.estado_retorno == 1)
            party->personajes_arr[i] = resultado.retorno;
        else {
            return 1;
        }
    }
    party->cantidad = i;
    return 0;
}
