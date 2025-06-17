#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#include "item_collection.h"
#define TAM_INVENTARIO_SLOTS 60

typedef struct  {
    unsigned int cantidad_de_ocupados_inventario;
    unsigned int id[TAM_INVENTARIO_SLOTS];
}t_inventory;

void inicializar_inventario(t_inventory* inventario);
unsigned int guardar_item (t_inventory* inventario, unsigned int id);
unsigned int remover_item_inventario (t_inventory* inventario, unsigned int pos);
unsigned int devolver_item_id (t_inventory* inventario, unsigned int pos);

#endif // INVENTARIO_H_INCLUDED
