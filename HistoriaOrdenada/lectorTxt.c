#include "sonidos.c"
#include "narrativaHeader.h"
#include <stdio.h>
#include <stdlib.h>

int preguntarYLeerSegunTexto(char* texto)
{
    int respuesta;
    puts(texto);
    leerPreguntaBooleana(&respuesta);
    system("cls");
    return respuesta;
}
int cinematica(char* nombreTxt)
{
    FILE *archivo = fopen(nombreTxt, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return ERR_LECTURA_ARCH;
    }

    char lineaDeTexto[MAX_LINEA];

    while (fgets(lineaDeTexto, sizeof(lineaDeTexto), archivo)) {
        // Eliminar el salto de línea final si lo hubiera
        lineaDeTexto[strcspn(lineaDeTexto, "\n")] = 0;

        // Separar por el delimitador "|"
        char *fragmento = strtok(lineaDeTexto, "|");
        while (fragmento != NULL) {
            printf("\n\n%s\n\n", fragmento);
            system("pause");
            system("cls");
            fragmento = strtok(NULL, "|");
        }
    }
    fclose(archivo);
    return TODO_OK;
}

void leerPreguntaBooleana(int* res)
{
    int num;
    scanf("%d",&num);
    while(num!=0 && num!=1)
    {
        puts("Error");
        scanf("%d",&num);
    }
    *res = num;
}
/*
void Altar()
{
    cinematica("AltarDeGuardado.txt");
    puts("¿Qué deseás hacer? \n 1. Guardar Progreso \n 2. Recuperar Energía \n 3. Organizar Equipo \n 0. Salir ");
}
*/
int acertijo()
{
    int respuesta;
    puts("\"Soy lo que es, lo que fue y lo que vendrá. \n Divídeme y me multiplicaré. \n Olvidame, y jamás podrás cruzar.¿Qué soy? \"\n");
    system("pause");
    system("cls");
    puts("\"Soy lo que es, lo que fue y lo que vendrá. \n Divídeme y me multiplicaré. \n Olvidame, y jamás podrás cruzar.¿Qué soy? \"\n");
    puts("1) El tiempo \n 2) El silencio \n 3) El conocimiento \n 4) El poder");
    leerRespuestaMultiples(&respuesta, CANT_MINIMA_DE_OPCIONES, CANT_MAXIMA_DE_OPCIONES);
    system("cls");
    if (respuesta!=RESPUESTA_CORRECTA)
    {
        return RECHAZADO;
    }
    else
    {
        return ACEPTADO;
    }
}
int leerRespuestaMultiples(int* res, int li, int ls)
{
    int num;
    scanf("%d",&num);
    while(num<li || num>ls)
    {
        puts("Error");
        scanf("%d",&num);
    }
    return num;
}

char* devolverNombreDeArchSegunCodigo(int codigo_linea) {
    FILE* archivo = fopen("./HistoriaOrdenada/Ruta.txt", "r");
    if (!archivo) {
        puts("No se pudo abrir el archivo");
        return ERR_ARCH;
    }

    static char lineaDeTexto[MAX_LINEA];
    int contador = 0;

    while (fgets(lineaDeTexto, MAX_LINEA, archivo)) {
        if (contador == codigo_linea) {
            lineaDeTexto[strcspn(lineaDeTexto, "\n")] = '\0';
            fclose(archivo);
            return lineaDeTexto;
        }
        contador++;
    }

    fclose(archivo);
    return ERR_ARCH;
}
int perdonarAfreezer()
{
    return preguntarYLeerSegunTexto("¿DESEAS PERDONAR A FREEZER?\n1.SI\n0.NO");
}

int ayudarAVegeta()
{
  return preguntarYLeerSegunTexto("¿DESEAS AYUDAR A VEGGETA? \n\n1. Si \n\n0. No");
}