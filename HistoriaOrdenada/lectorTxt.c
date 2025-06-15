#include "sonidos.c"
#include "narrativaHeader.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

    int final=0;
   int esqueleto=0;
    char *secuencias[] = {
        "./ArchivosDeTexto/introduccion.txt", //00
        "./ArchivosDeTexto/caminoANamek.txt", //01
        "./ArchivosDeTexto/barNamek.txt", //02
        "./ArchivosDeTexto/caminoAGranja.txt", //03
        "./ArchivosDeTexto/siBatallaBandidos.txt", //04
        "./ArchivosDeTexto/granjaNamek.txt", //05
        "./ArchivosDeTexto/caminoABosqueRojo.txt", //06
        "./ArchivosDeTexto/bosqueRojoPreAcertijo.txt", //07
        "./ArchivosDeTexto/acertijoRtaCorrecta.txt", //08
        "./ArchivosDeTexto/acertijoRtaIncorrecta.txt", //09
        "./ArchivosDeTexto/caminoPorBosqueRojo.txt", //10
        "./ArchivosDeTexto/esqueletoAyuda.txt", //11
        "./ArchivosDeTexto/esqueletoNoAyuda.txt", //12
        "./ArchivosDeTexto/temploBosqueRojo.txt", //13
        "./ArchivosDeTexto/temploBosqueRojoGuardianPrimerFase.txt", //14
        "./ArchivosDeTexto/temploBosqueRojoGuardianSegundaFase.txt", //15
        "./ArchivosDeTexto/segundaEsfera.txt", //16
        "./ArchivosDeTexto/postTemploBosqueRojo.txt", //17
        "./ArchivosDeTexto/postSoldadosBosqueRojo.txt", //18
        "./ArchivosDeTexto/ruidosInvestigados.txt", //19
        "./ArchivosDeTexto/caminoEsferaBrillante.txt", //20
        "./ArchivosDeTexto/tercerEsfera.txt", //21
        "./ArchivosDeTexto/seUnePiccolo.txt", //22
        "./ArchivosDeTexto/llanurasPrePiccolo.txt", //23
        "./ArchivosDeTexto/llanurasPostPiccolo.txt", //24
        "./ArchivosDeTexto/camaraDeFreezer.txt", //25
        "./ArchivosDeTexto/introLlanuraDeKihel.txt", //26
        "./ArchivosDeTexto/cobrarFavor.txt", //27
        "./ArchivosDeTexto/PostCobrarFavor.txt", //28
        "./ArchivosDeTexto/cobrarFavorNo.txt", //29
        "./ArchivosDeTexto/llanuraDeKihel.txt", //30
        "./ArchivosDeTexto/gokuEnLaNave.txt", //31
        "./ArchivosDeTexto/encuentroVeggeta.txt", //32
        "./ArchivosDeTexto/preVeggeta.txt", //33
        "./ArchivosDeTexto/postVeggeta.txt", //34
        "./ArchivosDeTexto/ayudasteAVegeta.txt", //35
        "./ArchivosDeTexto/noAyudasteAVegeta.txt", //36
        "./ArchivosDeTexto/salidaDeLlanura.txt", //37
        "./ArchivosDeTexto/postGolemBatalla.txt", //38
        "./ArchivosDeTexto/encuentroFuerzasGyu.txt", //39
        "./ArchivosDeTexto/llegadaGoku.txt", //40
        "./ArchivosDeTexto/freezerMataADende.txt", //41
        "./ArchivosDeTexto/freezerPidePerdon.txt", //42
        "./ArchivosDeTexto/freezerNoPerdonado.txt", //43
        "./ArchivosDeTexto/freezerEsPerdonado.txt", //44
        "./ArchivosDeTexto/diosesJuzgando.txt", //45
        "./ArchivosDeTexto/finalBueno.txt", //46
        "./ArchivosDeTexto/finalMalo.txt" //47
    };
    system("chcp 65001 >nul");
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
   // combate [SOLDADOS ELITE]
    IniciarSecuencia(18, secuencias);
    if(investigarRuidos())
    {
        IniciarSecuencia(19, secuencias);
        //combate [GOLEMS]
    }
    else
    {
        final++;
    }

    IniciarSecuencia(20, secuencias);

    juegoDeSonidosYColores();

    IniciarSecuencia(21, secuencias);

    IniciarSecuencia(22, secuencias);
   // Altar();

    IniciarSecuencia(23, secuencias);
    //combate [SOLDADOS DE FREEZER]
    
        //combate [GOLEMS]
    IniciarSecuencia(24, secuencias);
    //MECANICA DE BOTONES

    

    IniciarSecuencia(25, secuencias);

    // Altar();

    IniciarSecuencia(26, secuencias);
    if (esqueleto)
    {
        IniciarSecuencia(27, secuencias);
        //combate [BANDIDOS NAMEK]
        IniciarSecuencia(28, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(29, secuencias);
    }
    IniciarSecuencia(30, secuencias);
    IniciarSecuencia(31, secuencias);
    IniciarSecuencia(32, secuencias);
        //combate [FUERZAS DE VEGGETA]

    IniciarSecuencia(33, secuencias);
    //Combate [VEGGETA]

    IniciarSecuencia(34, secuencias);
    if(ayudarAVegeta())
    {
        final++;
        IniciarSecuencia(35, secuencias);
        //combate [VEGGETA]
    }
    else
    {
        IniciarSecuencia(36, secuencias);
    }
    IniciarSecuencia(37, secuencias);


    if(!rodearGolem())
    {
        IniciarSecuencia(38, secuencias);
        //combate [GOLEM]
    }
    else
    {
        final++;
    }
    
    //Altar();
    IniciarSecuencia(39, secuencias);

    //Se unio Veggeta a la Party

    //combate [Fuerzas Gyu]
    IniciarSecuencia(40, secuencias);
    //Ya estamos con Gokú
    //combate [FreezerGoku]

    IniciarSecuencia(41, secuencias);
    //Golú evoluciona
    //combate [FreezerGokú]
    IniciarSecuencia(42, secuencias);
    
    if(perdonarAfreezer())
    {
        IniciarSecuencia(44, secuencias);
    }
    else
    {
        final++;
        IniciarSecuencia(43, secuencias);
    }
    IniciarSecuencia(45, secuencias);
    if(final>1)
    {
        IniciarSecuencia(46, secuencias);
    }
    else
    {
        IniciarSecuencia(47, secuencias);
    }
    puts("FIN DEL JUEGO");

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
int ayudarAVegeta()
{
  return preguntarYLeerSegunTexto("¿DESEAS AYUDAR A VEGGETA? \n\n1. Si \n\n0. No");
}