#include <stdio.h>
#include "evolucion.h"

void inicializar_evolucion(t_evolucion* ev)
{
    ev->puntos_habilidad = 0;
    cant_mejoras_HP=0;
    cant_mejoras_ATK=0;
    cant_mejoras_ENERGY=0;
    cant_mejoras_ARMOR=0;
    cant_mejoras_CS=0;
}

void otorgar_puntos(t_evolucion* ev, int puntos)
{
    ev->puntos_habilidad += puntos;
    printf("\nTenes %d puntos disponibles.\n",
            puntos, ev->puntos_habilidad);
}

void mostrar_menu_mejoras(t_evolucion* ev, t_character* pj)
{
    int opcion, confirmar;

    if (ev->puntos_habilidad == 0) {
        printf("No tenes puntos de habilidad para gastar.\n");
        return;
    }

    do {
        printf("\n=== MEJORAS DE PERSONAJE ===\n");
        printf("Puntos disponibles: %d\n", ev->puntos_habilidad);
        if (ev->cant_mejoras_HP < 5)
            printf("1. HP nivel %d --> nivel %d*\n", ev->cant_mejoras_HP + 1, ev->cant_mejoras_HP + 2);
        else
            printf("1. HP nivel 5 (MAXIMO ALCANZADO)\n");

        if (ev->cant_mejoras_ATK < 5)
            printf("2. ATK nivel %d --> nivel %d*\n", ev->cant_mejoras_ATK + 1, ev->cant_mejoras_ATK + 2);
        else
            printf("2. ATK nivel 5 (MAXIMO ALCANZADO)\n");

        if (ev->cant_mejoras_ENERGY < 5)
            printf("3. ENERGY nivel %d --> nivel %d*\n", ev->cant_mejoras_ENERGY + 1, ev->cant_mejoras_ENERGY + 2);
        else
            printf("3. ENERGY nivel 5 (MAXIMO ALCANZADO)\n");

        if (ev->cant_mejoras_ARMOR < 3)
            printf("4. ARMOR nivel %d --> nivel %d*\n", ev->cant_mejoras_ARMOR + 1, ev->cant_mejoras_ARMOR + 2);
        else
            printf("4. ARMOR nivel 3 (MAXIMO ALCANZADO)\n");

        if (ev->cant_mejoras_CS < 3)
            printf("5. COMBAT SPEED nivel %d --> nivel %d*\n", ev->cant_mejoras_CS + 1, ev->cant_mejoras_CS + 2);
        else
            printf("5. COMBAT SPEED nivel 3 (MAXIMO ALCANZADO)\n");

        printf("0. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if(ev->cant_mejoras_HP < 5)
                {
                    do
                    {
                        printf("HP: Seguro que quieres subir a nivel %d esta habilidad?\n", ev->cant_mejoras_HP+2);
                        printf("HP = %d + 10\n", pj->personaje_template.stats.HP);
                        printf("1. SI\n");
                        printf("2. NO\n");
                        scanf("%d", &confirmar);
                        if(confirmar==1)
                        {
                            pj->personaje_template.stats.HP += 10;
                            ev->puntos_habilidad--;
                            ev->cant_mejoras_HP++;
                            printf("HP mejorado!\n");
                        }
                        else if(confirmar!=2)
                        {
                            printf("Opcion incorrecta. Vuelva a ingresar.");
                        }
                    }while(confirmar!=1 && confirmar!=2);
                }
                else
                {
                    printf("Alcanzaste el limite de mejoras para esta habilidad.\n");
                }
                break;

            case 2:
                if(ev->cant_mejoras_ATK < 5)
                {
                    do
                    {
                        printf("ATK: Seguro que quieres subir a nivel %d esta habilidad?\n", ev->cant_mejoras_ATK+2);
                        printf("ATK = %d + 2\n", pj->personaje_template.stats.ATK);
                        printf("1. SI\n");
                        printf("2. NO\n");
                        scanf("%d", &confirmar);
                        if(confirmar==1)
                        {
                            pj->personaje_template.stats.ATK += 2;
                            ev->puntos_habilidad--;
                            ev->cant_mejoras_ATK++;
                            printf("ATK mejorado!\n");
                        }
                        else if(confirmar!=2)
                        {
                            printf("Opcion incorrecta. Vuelva a ingresar.");
                        }
                    }while(confirmar!=1 && confirmar!=2);
                }
                else
                {
                    printf("Alcanzaste el limite de mejoras para esta habilidad.\n");
                }
                break;

            case 3:
                if(ev->cant_mejoras_ENERGY < 5)
                {
                    do
                    {
                        printf("ENERGY: Seguro que quieres subir a nivel %d esta habilidad?\n", ev->cant_mejoras_ENERGY+2);
                        printf("ENERGY = %d + 5\n", pj->personaje_template.stats.ENERGY);
                        printf("1. SI\n");
                        printf("2. NO\n");
                        scanf("%d", &confirmar);
                        if(confirmar==1)
                        {
                            pj->personaje_template.stats.ENERGY += 5;
                            ev->puntos_habilidad--;
                            ev->cant_mejoras_ENERGY++;
                            printf("ENERGY mejorada!\n");
                        }
                        else if(confirmar!=2)
                        {
                            printf("Opcion incorrecta. Vuelva a ingresar.");
                        }
                    }while(confirmar!=1 && confirmar!=2);
                }
                else
                {
                    printf("Alcanzaste el limite de mejoras para esta habilidad.\n");
                }

                break;

            case 4:
                if(ev->cant_mejoras_ARMOR < 3)
                {
                    do
                    {
                        printf("ARMOR: Seguro que quieres subir a nivel %d esta habilidad?\n", ev->cant_mejoras_ARMOR+2);
                        printf("ARMOR = %d + 1\n", pj->personaje_template.stats.ARMOR);
                        printf("1. SI\n");
                        printf("2. NO\n");
                        scanf("%d", &confirmar);
                        if(confirmar==1)
                        {
                            pj->personaje_template.stats.ARMOR += 1;
                            ev->puntos_habilidad--;
                            ev->cant_mejoras_ARMOR++;
                            printf("ARMOR mejorada!\n");
                        }
                        else if(confirmar!=2)
                        {
                            printf("Opcion incorrecta. Vuelva a ingresar.");
                        }
                    }while(confirmar!=1 && confirmar!=2);
                }
                else
                {
                    printf("Alcanzaste el limite de mejoras para esta habilidad.\n");
                }
                break;

            case 5:
                if(ev->cant_mejoras_CS < 3)
                {
                    do
                    {
                        printf("COMBAT SPEED: Seguro que quieres subir a nivel %d esta habilidad?\n", ev->cant_mejoras_CS+2);
                        printf("COMBAT SPEED = %d + 0.1\n", pj->personaje_template.stats.COMBAT_SPEED);
                        printf("1. SI\n");
                        printf("2. NO\n");
                        scanf("%d", &confirmar);
                        if(confirmar==1)
                        {
                            pj->personaje_template.stats.COMBAT_SPEED += 0.1;
                            ev->puntos_habilidad--;
                            ev->cant_mejoras_CS++;
                            printf("COMBAT SPEED mejorada!\n");
                        }
                        else if(confirmar!=2)
                        {
                            printf("Opcion incorrecta. Vuelva a ingresar.");
                        }
                    }while(confirmar!=1 && confirmar!=2);
                }
                else
                {
                    printf("Alcanzaste el limite de mejoras para esta habilidad.\n");
                }
                break;

            case 0:
                printf("Saliendo del menú de mejoras.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0 && ev->puntos_habilidad > 0);
}
