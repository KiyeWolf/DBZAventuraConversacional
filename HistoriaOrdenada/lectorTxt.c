#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 4096
void leerPreguntaBooleana(int* res);
int tutorial();
int batallaBandidos();
void cinematica(char* nombreTxt);
void Altar();

int main() {
   cinematica("introduccion.txt");
        //if (tutorial())
        //el combate es con tutorial [LADRONES NAMEK]
        //Puede o no haber combate
    cinematica("barNamek.txt");
        //En esta parte aparece un Altar

        cinematica("AltarDeGuardado.txt");
        Altar(); //por ahora nose que mandarle

    cinematica("caminoAGranja.txt");
    if(batallaBandidos())
    {
        //se inicia un combate [BANDIDOS NAMEK]
        cinematica("siBatallaBandidos.txt");
    }

    cinematica("granjaNamek.txt");
    //se inicia un combate [SOLDADOS BASICOS]
    cinematica("caminoABosqueRojo.txt");

}
void cinematica(char* nombreTxt)
{
    FILE *archivo = fopen(nombreTxt, "r");
    system("chcp 65001 <nul");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
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
    return 0;
}
int batallaBandidos()
{
    unsigned int respuesta;
    puts("¿DESEAS INTERVENIR EN LA VIDA DE LOS ANIMALES?\n1.SI\n0.NO");
    leerPreguntaBooleana(&respuesta);
    return respuesta;
}
int tutorial()
{
    //habria que validar el ingreso por teclado no?
    unsigned int respuesta;
    puts("¿QUIERES SALTEAR EL TUTORIAL?\n1.SI\n0.NO");
    leerPreguntaBooleana(&respuesta);
    return respuesta;
}
void leerPreguntaBooleana(int* res)
{
    unsigned int num;
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
    puts("¿Qué deseás hacer? \n 1. Guardar Progreso \n 2. Recuperar Energía \n 3. Organizar Equipo \n 0. Salir ");
}
