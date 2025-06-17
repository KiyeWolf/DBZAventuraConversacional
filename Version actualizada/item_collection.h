#ifndef ITEM_COLLECTION_H_INCLUDED
#define ITEM_COLLECTION_H_INCLUDED

#include "item.h"

enum e_items {
    ITEM_VACIO,
    BOTAS,
    SALUD,
    PODER,
    VIGOR,
    TRAJE_REFORZADO,
    GEMA_DE_SALUD,
    GEMA_DE_PODER,
    GEMA_DE_VIGOR,
    TRAJE_ENCANTADO,
    BOTAS_ENCANTADAS,
    BOTAS_ANTIGUAS,
    CANTIDAD_DE_ITEMS
};

typedef struct {
    unsigned int estado_del_retorno;
    t_item retorno;
} t_retorno_item;


extern t_item item_collection[];

t_retorno_item devolver_item_por_id(unsigned int id);

#endif // ITEM_COLLECTION_H_INCLUDED
