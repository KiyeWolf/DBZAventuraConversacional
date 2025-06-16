#include "texto_condicionales.h"
#include "lector_de_texto.h"

int preguntarYLeerSegunTexto(char* texto)
{
    int respuesta;
    puts(texto);
    leerPreguntaBooleana(&respuesta);
    system("cls");
    return respuesta;
}

int perdonarAfreezer()
{
    return preguntarYLeerSegunTexto("¿DESEAS PERDONAR A FREEZER?\n1.SI\n0.NO");
}

int ayudarAVegeta()
{
  return preguntarYLeerSegunTexto("¿DESEAS AYUDAR A VEGGETA? \n\n1. Si \n\n0. No");
}

int acertijo()
{
    int respuesta;
    puts("\"Soy lo que es, lo que fue y lo que vendrá. \n Divídeme y me multiplicaré. \n Olvidame, y jamás podrás cruzar.¿Qué soy? \"\n");
    system("pause");
    system("cls");
    puts("\"Soy lo que es, lo que fue y lo que vendrá. \n Divídeme y me multiplicaré. \n Olvidame, y jamás podrás cruzar.¿Qué soy? \"\n");
    puts("1) El tiempo \n 2) El silencio \n 3) El conocimiento \n 4) El poder");
    leerRespuestaMultiples(&respuesta, 1, 4);
    system("cls");
    if (respuesta!=3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void leerRespuestaMultiples(int* res, int li, int ls)
{
    int num;
    scanf("%d",&num);
    while(num<li || num>ls)
    {
        puts("Error");
        scanf("%d",&num);
    }
    *res = num;
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
