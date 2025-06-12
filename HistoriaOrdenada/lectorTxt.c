#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sonidos.c"
#define TODO_OK 0
#define ERR_LECTURA_ARCH 1
#define ACEPTADO 1
#define RECHAZADO 0

#define MAX_LINEA 4096

void IniciarSecuencia(int indice, char *secuencias[]);
void leerPreguntaBooleana(int* res);
int preguntarYLeerSegunTexto(char* texto);
int tutorial();
int aceptarAyudarAnimales();
int cinematica(char* nombreTxt);
void Altar();
int acertijo();
void leerRespuestaMultiples(int* res, int li, int ls);

void aceptarAyudaEsqueleto(int* esqueleto);
int investigarRuidos();
int rodearGolem();
int perdonarAfreezer();

int main() {
    system("chcp 65001 <nul");
    int final=0;
   int esqueleto=0;
    char *secuencias[] = {
        "./ArchivosDeTexto/introduccion.txt",
        "./ArchivosDeTexto/caminoANamek.txt",
        "./ArchivosDeTexto/barNamek.txt",
        "./ArchivosDeTexto/caminoAGranja.txt",
        "./ArchivosDeTexto/siBatallaBandidos.txt",
        "./ArchivosDeTexto/granjaNamek.txt",
        "./ArchivosDeTexto/caminoABosqueRojo.txt",
        "./ArchivosDeTexto/bosqueRojoPreAcertijo.txt",
        "./ArchivosDeTexto/acertijoRtaCorrecta.txt",
        "./ArchivosDeTexto/acertijoRtaIncorrecta.txt",
        "./ArchivosDeTexto/caminoPorBosqueRojo.txt",
        "./ArchivosDeTexto/esqueletoAyuda.txt",
        "./ArchivosDeTexto/esqueletoNoAyuda.txt",
        "./ArchivosDeTexto/temploBosqueRojo.txt",
        "./ArchivosDeTexto/temploBosqueRojoGuardianPrimerFase.txt",
        "./ArchivosDeTexto/temploBosqueRojoGuardianSegundaFase.txt",
        "./ArchivosDeTexto/segundaEsfera.txt",
        "./ArchivosDeTexto/postTemploBosqueRojo.txt",
        "./ArchivosDeTexto/postSoldadosBosqueRojo.txt",
        "./ArchivosDeTexto/ruidosInvestigados.txt",
        "./ArchivosDeTexto/caminoEsferaBrillante.txt",
        "./ArchivosDeTexto/tercerEsferaOPiccolo.txt",
        "./ArchivosDeTexto/seUnePiccolo.txt",
        "./ArchivosDeTexto/llanurasPrePiccolo.txt",
        "./ArchivosDeTexto/llanurasPostPiccolo.txt",
        "./ArchivosDeTexto/camaraDeFreezer.txt",
        "./ArchivosDeTexto/introLlanuraDeKihel.txt",
        "./ArchivosDeTexto/cobrarFavor.txt",
        "./ArchivosDeTexto/cobrarFavorNo.txt",
        "./ArchivosDeTexto/llanuraDeKihel.txt",
        "./ArchivosDeTexto/preVeggeta.txt",
        "./ArchivosDeTexto/postVeggeta.txt",
        "./ArchivosDeTexto/postGolemBatalla.txt",
        "./ArchivosDeTexto/encuentroFuerzasGyu.txt",
        "./ArchivosDeTexto/llegadaGoku.txt",
        "./ArchivosDeTexto/freezerMataADende.txt",
        "./ArchivosDeTexto/freezerPidePerdon.txt",
        "./ArchivosDeTexto/freezerNoPerdonado.txt",
        "./ArchivosDeTexto/freezerEsPerdonado.txt",
        "./ArchivosDeTexto/diosesJuzgando.txt",
        "./ArchivosDeTexto/finalBueno.txt",
        "./ArchivosDeTexto/finalMalo.txt"
    };
    IniciarSecuencia(0, secuencias);
    IniciarSecuencia(1, secuencias);
    // Si el tutorial es necesario, se puede descomentar la siguiente línea
        //if (tutorial())
        //el combate es con tutorial [LADRONES NAMEK]
        //Puede o no haber combate
    IniciarSecuencia(2, secuencias);
    //Altar
    IniciarSecuencia(3, secuencias);
    if(aceptarAyudarAnimales())
    {
        //se inicia un combate [BANDIDOS NAMEK]
        final++;
        IniciarSecuencia(4, secuencias);
    }
    
    IniciarSecuencia(5, secuencias);
//    se inicia un combate [SOLDADOS BASICOS]
    IniciarSecuencia(6, secuencias);

    IniciarSecuencia(7, secuencias);
    if (acertijo())
    {
        IniciarSecuencia(8, secuencias);
    }
    else
    {
        IniciarSecuencia(9, secuencias);
        //combate [BESTIAS DE LA NIEBLA]
    }
    IniciarSecuencia(10, secuencias);
   aceptarAyudaEsqueleto(&esqueleto);
    if(esqueleto)
    {
        IniciarSecuencia(11, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(12, secuencias);
        //combate [BESTIAS DE LA NIEBLA]
    }
    IniciarSecuencia(13, secuencias);


    //Dende se Une a la Party


    //Altar();
    IniciarSecuencia(14, secuencias);
    //combate [GUARDIAN DEL TEMPLO PRIMER FASE]
    IniciarSecuencia(15, secuencias);
    //combate [GUARDIAN DEL TEMPLO SEGUNDA FASE]
   IniciarSecuencia(16, secuencias);
    IniciarSecuencia(17, secuencias);
   // combate [SOLDADOS NORMALES]
    IniciarSecuencia(18, secuencias);
    //combate [SOLDADOS ELITE]
    IniciarSecuencia(19, secuencias);
    //combate [GOLEMS]
    IniciarSecuencia(20, secuencias);
    IniciarSecuencia(21, secuencias);
    IniciarSecuencia(22, secuencias);


    //Piccolo se une a la Party


   // Altar();
   if (investigarRuidos())
    {
        IniciarSecuencia(23, secuencias);
        //combate [GOLEMS]
    }
    IniciarSecuencia(24, secuencias);
    //MECANICA DE BOTONES

    sonidista();

    IniciarSecuencia(25, secuencias);



    IniciarSecuencia(26, secuencias);
    IniciarSecuencia(27, secuencias);
    //batalla [SOLDADOS ELITE]
    IniciarSecuencia(28, secuencias);
    Altar();
    IniciarSecuencia(29, secuencias);
    IniciarSecuencia(30, secuencias);
    if(esqueleto)
    {
        IniciarSecuencia(31, secuencias);
        //combate []
    }
    else{
        IniciarSecuencia(32, secuencias);
    }
    IniciarSecuencia(33, secuencias);
    //combate [SOLDADOS DE VEGGETA]
    IniciarSecuencia(34, secuencias);
    IniciarSecuencia(35, secuencias);
    if(!rodearGolem())
    {
        IniciarSecuencia(36, secuencias);
        //combate [GOLEM]
    }
    else
    {
        final++;
    }
    //Altar();

    IniciarSecuencia(37, secuencias);
    
    //Se unio Veggeta a la Party

    //combate [Fuerzas Gyu]
    IniciarSecuencia(38, secuencias);
    //comabate [Frezer]

    IniciarSecuencia(39, secuencias);

    //Ya estamos con Gokú
    //combate [FreezerGoku]
    IniciarSecuencia(40, secuencias);

    if(!perdonarAfreezer())
    {
        IniciarSecuencia(41, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(42, secuencias);
    }
    IniciarSecuencia(43, secuencias);
    if(final>1)
    {
        IniciarSecuencia(44, secuencias);
    }
    else
    {
        IniciarSecuencia(45, secuencias);
    }
    puts("FIN DEL JUEGO");
    return 0;
}
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
    respuesta = preguntarYLeerSegunTexto("¿DESEAS AYUDAR AL ESQUELETO QUE TE PIDE AYUDA? \n\n1. Si \n\n0. No");
    if (respuesta)
    {
        *esqueleto = ACEPTADO;
    }
    else
    {
        *esqueleto = RECHAZADO;
    }
}
int aceptarAyudarAnimales()
{
    return preguntarYLeerSegunTexto("¿DESEAS AYUDAR A LOS ANIMALES QUE TE PIDEN AYUDA? \n\n1. Si \n\n0. No");
}
int tutorial()
{
    return preguntarYLeerSegunTexto("¿DESEAS HACER EL TUTORIAL? \n\n1. Si \n\n0. No");
}
int investigarRuidos()
{
    return preguntarYLeerSegunTexto("¿QUIERES INVESTIGAR LOS RUIDOS QUE ESCUCHAS?\n1.SI\n0.NO");
}
int rodearGolem()
{
    return preguntarYLeerSegunTexto("¿QUIERES RODEAR AL GOLEM?\n1.SI\n0.NO");
}
int perdonarAfreezer()
{
    return preguntarYLeerSegunTexto("¿DESEAS PERDONAR A FREEZER?\n1.SI\n0.NO");
}
void IniciarSecuencia(int indice, char *secuencias[]) {
    cinematica(secuencias[indice]);
}