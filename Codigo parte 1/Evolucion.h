#ifndef EVOLUCION_H
#define EVOLUCION_H

#include "character.h"

typedef struct
{
    unsigned int puntos_habilidad;
    int cant_mejoras_HP;
    int cant_mejoras_ATK;
    int cant_mejoras_ENERGY;
    int cant_mejoras_ARMOR;
    int cant_mejoras_CS;
} t_evolucion;

void inicializar_evolucion(t_evolucion* ev);//funcion para inicializar la evolucion de un personaje.

void otorgar_puntos(t_evolucion* ev, int puntos);//funcion para calcular y cargar los puntos de habilidad a un personaje.

void mostrar_menu_mejoras(t_evolucion* ev, t_character* pj);//funcion para mostrar el menu de mejoras y canjear los puntos en ellas.

#endif
