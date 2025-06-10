#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 4096
/*int leerPreguntaBooleana();
int tutorial();
int batallaBandidos();*/
void cinematica(char* nombreTxt);

int main() {
   // cinematica("introduccion.txt");
   /* if (tutorial())
        //el combate es con tutorial
    else
        //es un combate común*/
    cinematica("barNamek.txt");
    /*if(batallaBandidos())
        //se inicia un combate
        cinematica()
    cinematica("granjaNamek.txt");*/

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
            system("cls");  // En Linux usar "clear"
            fragmento = strtok(NULL, "|");
        }
    }

    fclose(archivo);
    return 0;
}
