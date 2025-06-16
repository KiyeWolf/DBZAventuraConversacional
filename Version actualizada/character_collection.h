#ifndef CHARACTER_COLLECTION_H_INCLUDED
#define CHARACTER_COLLECTION_H_INCLUDED

#include "character_template.h"

enum e_character_id{
    GOKU,
    GOHAN,
    KRILLIN,
    VEGETA,
    PICCOLO,
    CANTIDAD_DE_PERSONAJES
};

typedef struct {
    unsigned int estado_del_retorno;
    t_character_template retorno;
} t_retorno_template;

extern t_character_template character_collection_array[];
t_retorno_template devolver_template_por_id(unsigned int id);



#endif // CHARACTER_COLLECTION_H_INCLUDED
