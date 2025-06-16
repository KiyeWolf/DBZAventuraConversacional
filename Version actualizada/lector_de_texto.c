#include "lector_de_texto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Busca el archivo y lo abre y llena el buffer
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

//Busca la ruta de el archivo y devuelve un char* con el contenido
char* devolverNombreDeArchSegunCodigo(int codigo_linea) {
    FILE* archivo = fopen("Ruta.txt", "r");

    if (!archivo) {
        puts("No se pudo abrir el archivo");
        return NULL;
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
    return NULL;  // Si no se encontró la línea
}


