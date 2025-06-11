#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TODO_OK 0
#define ERR_LECTURA_ARCH 1
#define ACEPTADO 1
#define RECHAZADO 0

#define MAX_LINEA 4096
void leerPreguntaBooleana(int* res);
int tutorial();
int aceptarAyudarAnimales();
int cinematica(char* nombreTxt);
void Altar();
int acertijo();
void leerRespuestaMultiples(int* res, int li, int ls);

void aceptarAyudaEsqueleto(int* esqueleto);

int main() {
   int esqueleto=0;
   cinematica("introduccion.txt");
    cinematica("caminoANamek.txt");
    //if (tutorial())
        //el combate es con tutorial [LADRONES NAMEK]
        //Puede o no haber combate
    cinematica("barNamek.txt");
        //En esta parte aparece un Altar


        Altar(); //por ahora nose que mandarle

    cinematica("caminoAGranja.txt");
    if(aceptarAyudarAnimales())
    {
        se inicia un combate [BANDIDOS NAMEK]
        cinematica("siBatallaBandidos.txt");
    }

    cinematica("granjaNamek.txt");
    se inicia un combate [SOLDADOS BASICOS]
    cinematica("caminoABosqueRojo.txt");
    Altar();
    cinematica("bosqueRojoPreAcertijo.txt");
    if (acertijo())
    {
        cinematica("acertijoRtaCorrecta.txt");
    }
    else
    {
        cinematica("acertijoRtaIncorrecta.txt");
        //combate [BESTIAS DE LA NIEBLA]
    }
    cinematica("caminoPorBosqueRojo.txt");
    aceptarAyudaEsqueleto(&esqueleto);
    if(esqueleto)
    {
        cinematica("esqueletoAyuda.txt");
    }
    else
    {
        cinematica("esqueletoNoAyuda.txt");
        //combate [BESTIAS DE LA NIEBLA]
    }
    cinematica("temploBosqueRojo.txt");
    //Dende se Une a la Party
    Altar();
    cinematica("temploBosqueRojoGuardianPrimerFase.txt");
    //combate [GUARDIAN DEL TEMPLO PRIMER FASE]
    cinematica("temploBosqueRojoGuardianSegundaFase.txt");
    //combate [GUARDIAN DEL TEMPLO SEGUNDA FASE]
    cinematica("segundaEsfera.txt");

}
int cinematica(char* nombreTxt)
{
    FILE *archivo = fopen(nombreTxt, "r");
    system("chcp 65001 <nul");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return ERR_LECTURA_ARCH;
    }

    char linea[MAX_LINEA];

    while (fgets(linea, sizeof(linea), archivo)) {
        // Eliminar el salto de línea final si lo hubiera
        linea[strcspn(linea, "\n")] = 0;

        // Separar por el delimitador "|"
        char *fragmento = strtok(linea, "|");
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
int aceptarAyudarAnimales()
{
    int respuesta;
    puts("¿DESEAS INTERVENIR EN LA VIDA DE LOS ANIMALES?\n1.SI\n0.NO");
    leerPreguntaBooleana(&respuesta);
    return respuesta;
}
int tutorial()
{
    //habria que validar el ingreso por teclado no?
    int respuesta;
    puts("¿QUIERES SALTEAR EL TUTORIAL?\n1.SI\n0.NO");
    leerPreguntaBooleana(&respuesta);
    return respuesta;
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
void Altar()
{
    cinematica("AltarDeGuardado.txt");
    puts("¿Qué deseás hacer? \n 1. Guardar Progreso \n 2. Recuperar Energía \n 3. Organizar Equipo \n 0. Salir ");
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
void aceptarAyudaEsqueleto(int* esqueleto)
{
    int respuesta;
    puts("¿CONFIAR EN EL ESQUELETO Y ACEPTAR EL TRATO? \n\n1. Aceptar el trato \n\n0. Rechazarlo y encontrar otro camino\n\n");
    leerPreguntaBooleana(&respuesta);
    system("cls");
    if (respuesta)
    {
        *esqueleto = ACEPTADO;
    }
    else
    {
        *esqueleto = RECHAZADO;
    }
}
