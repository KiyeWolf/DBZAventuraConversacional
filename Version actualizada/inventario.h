#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#define TAM_INVENTARIO 150

#include "item_collection.h"

typedef struct  {
    unsigned int cantidad_de_ocupados_inventario;
    unsigned int id[TAM_INVENTARIO];
}t_inventory;

unsigned int guardar_item (t_inventory* inventario, unsigned int id);
unsigned int remover_item (t_inventory* inventario,unsigned int id);
unsigned int devolver_item_id (t_inventory* inventario, unsigned int pos);

#endif // INVENTARIO_H_INCLUDED
