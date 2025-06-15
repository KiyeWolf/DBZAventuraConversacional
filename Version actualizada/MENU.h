#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// #define INSTRUCCION(NAME) { #NAME, &NAME }
/*
//////////////////////  MENU  ///////////////////////
*/

typedef struct {
    char* name;
    void *argumento;
    void (*funcion)(void*);
} t_instruccion;

void menu_generator(char *text, t_instruccion *instrucciones, int cantidad);


void quit(void *ptr);
void nueva_partida(void *ptr);
void continuar(void *ptr);


/*
/////////////////////////////////////////////////////
*/


#endif // MENU_H_INCLUDED
