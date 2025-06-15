
#include <windows.h> // Para Sleep
#include <stdio.h>
#define MAX_LEN 5

// Simulación de "sonidos" con textos
void reproducirSonido(int boton) {
    switch(boton) {
        case 1: printf("¡Sonido agudo!\n");
        break;
        case 2: printf("¡Sonido grave!\n");
        break;
        case 3: printf("¡Sonido metálico!\n");
        break;
        case 4: printf("¡Sonido suave!\n");
        break;
        default: printf("Botón inválido.\n");
    }
    Sleep(600); // Espera entre sonidos
}

// Mostrar la secuencia original
void mostrarFrecuencia(int secuencia[], int len) {
    printf("\nReproduciendo secuencia...\n");
    for(int i = 0; i < len; i++) {
        reproducirSonido(secuencia[i]);
    }
    printf("\n");
}

void juegoDeSonidosYColores()
{
    int secuencia[MAX_LEN] = {1, 1, 3, 4, 2}; // se puede cambiar la  secuencia aca
    int entrada[MAX_LEN];

    printf("--- Botones de Sonido ---\n");
    printf("Presiona del 1 al 4 para escuchar sonidos.\n");
    printf("Presiona 0 para escuchar la secuencia completa.\n");
    printf("¡Repite la secuencia correctamente para avanzar!\n\n");

    while(1) {
        int index = 0;

        while(index < MAX_LEN) {
            printf("Ingresa un número (0 para escuchar secuencia): ");
            int opc;
            scanf("%d", &opc);

            if(opc == 0) {
                mostrarFrecuencia(secuencia, MAX_LEN);
                continue;
            }

            if(opc < 1 || opc > 4) {
                printf("❌ Opción inválida.\n");
                continue;
            }

            reproducirSonido(opc);
            entrada[index++] = opc;
        }

        // Verificación
        int correcto = 1;
        for(int i = 0; i < MAX_LEN; i++) {
            if(entrada[i] != secuencia[i]) {
                correcto = 0;
                break;
            }
        }

        if(correcto) {
            printf("\n ¡Secuencia correcta! Has desbloqueado la esfera.\n");
            Sleep(2000);
            system("cls");
            break;
        }
        else
        {
            printf("\nX Secuencia incorrecta. Inténtalo de nuevo.\n\n");
            Sleep(2000);
            system("cls");
        }
    }

}
