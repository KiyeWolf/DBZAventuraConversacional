#ifndef TEXTO_CONDICIONALES_H_INCLUDED
#define TEXTO_CONDICIONALES_H_INCLUDED

int preguntarYLeerSegunTexto(char* texto);
int perdonarAfreezer();
int ayudarAVegeta();
int acertijo();
void leerRespuestaMultiples(int* res, int li, int ls);
void leerPreguntaBooleana(int* res);



{
    0,
    1, GOHAN, KRILLIN,
    PELEA
    2, HOGUERA,
    3, GOHAN, KRILLIN,
    PELEA
    4,
    5, GOHAN, KRILLIN,
    PELEA
    6, HOGUERA
    7, BRANCH {
        8,
        9, GOHAN, KRILLIN
        PELEA
    },
    10,
    11,
    12, HOGUERA
    13, GOHAN, KRILLIN
    PELEA,
    14, GOHAN, KRILLIN,
    PELEA
    15, HOGUERA
    16, GOHAN KRILLIN
}

#endif // TEXTO_CONDICIONALES_H_INCLUDED
