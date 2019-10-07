#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>

#define TAM 3
#define TAMM 3 /* CANTIDAD DE EMPLEADOS */
#define TAMO 3 /* CANTIDAD DE EMPLEADOS */
#define TAMI 3 /* CANTIDAD DE EMPLEADOS */
#define LENSTR 25 /* CANTIDAD DE CARACTERES VECTORES */
#define TAML 3

/////////////////////////////
struct{
int idOrq;
char nombreOrq[LENSTR];
char lugarOrq[LENSTR];
int tipoOrq;
int isEmpty;
}typedef eOrquesta;

struct{
int idM;
char nombreM[LENSTR];
char apellidoM[LENSTR];
int edadM;
int idOrq;
int idInst;
int isEmpty;

}typedef eMusico;


struct{
int idInst;
char nombreInst[LENSTR];
int tipoInst;
int isEmpty;
}typedef eInstrumento;
/////////////////
/* ESTRUCTURAS PARA TIPOS*/
struct{
int idTi;
char tipoInst[LENSTR];

}typedef eTipoInst;
struct{
int idTo;
char tipoOrq[LENSTR];

}typedef eTipoOrquesta;
/* PROTOTIPOS*/
int initx(eOrquesta orquesta[],int tamo,eMusico musico[],int tamm,eInstrumento instrumentos[],int tami);

int menu(void);
int hardcodearMusicos( eMusico musico[], int tam, int cantidad);
int hardcodearInstrumentos(eInstrumento instrumentos[], int tam, int cantidad);
int hardcodearOrquestas(eOrquesta orquestas[], int tam, int cantidad);

int dataEntryOrq(eOrquesta orquesta[],int tamo,int lastIdOrq);
int dataEntryMusico(eMusico musico[],eOrquesta orquesta[],int tamo,int tamm,int lastIdMusico);
int dataEntryInst(eInstrumento instrumentos[],int tami,int lastIdInst);

int addOrq(eOrquesta *orquesta,int tam,int id, char name[],char lugar[],int tipo);
int addMusico(eMusico musico[],int tami,int lastIdMusico,char nombre[],char apellido[],int edad,int idOrq,int idInst);
int addInst(eInstrumento *instrumentos,int tam,int id, char name[],int tipo);


int validadorInputint(char auxlen[],int lenstr);
int validadorLen(char auxLen[],int lenstr);
int validaCadenas(char x[],int lenstr);
int validadorInputint(char auxlen[],int lenstr);

int searchFreeOrq(eOrquesta orquesta[],int tam);
int searchFreeMusico(eMusico musico[],int tam);
int searchFreeInst(eInstrumento instrumentos[],int tam);

void printOrquestas(eOrquesta orquesta[], int tam);
void printOrq(eOrquesta x);
void printMusicos(eMusico musico[],int tam,eTipoInst tiposInst[],int taml,eTipoOrquesta tiposOrq[]);

void printMusico(eMusico x,eTipoInst tiposInst[],int taml,eTipoOrquesta tiposOrq[]);
void printInstrumentos(eInstrumento instrumentos[], int tami);
void printInstrumento(eInstrumento x);



int findOrquestaById(eOrquesta* orquesta, int tam,int id);
int removeOrq(eOrquesta* orquesta, int tam, int id);

int findMusicoById(eMusico* musico, int tam,int id);
int removeMusico(eMusico* musico, int tam, int id,eTipoInst tipoinst[],eTipoOrquesta tipoOrq[],int taml);

int editOrq(eOrquesta *orquesta,int tam,int id);
int editMusico(eMusico *musico,int tam,int id,eTipoInst tiposInst[],eTipoOrquesta tiposOrq[],int taml);

/*FUNCION PRINCIPAL*/




int main()
{

eOrquesta orquesta[TAMO];
eMusico musico[TAMM];
eInstrumento instrumentos[TAMI];

  eTipoInst tiposInst[]=
    {
        { 1, "Cuerdas"},
       { 2, "Viento-Madera",},
       { 3, "Percusion"},
    };
      eTipoOrquesta tiposOrq[]=
    {
        { 1, "Sinfonica"},
       { 2, "Filarmonica",},
       { 3, "Camara"},
    };

initx(orquesta,TAMO,musico,TAMM,instrumentos,TAMI);
int lastIdOrq=1;
int lastIdMusico=1;
int lastIdInst=1;
int id;
int check;
int order;
int salir=0;
char auxLen[LENSTR];
/* cantiadd para hardcodeo de musicos*/
int cantidad=3;
lastIdInst=hardcodearInstrumentos(instrumentos,TAMI,cantidad);
lastIdMusico=hardcodearMusicos(musico,TAMM,cantidad);
lastIdOrq=hardcodearOrquestas(orquesta,TAMO,cantidad);
do
    {
        switch(menu())
        {
        case 1:  system("cls");
            printf("****ALTA ORQUESTA**\n");
            check=dataEntryOrq(orquesta,TAMO,lastIdOrq);
        if(check==1){
            lastIdOrq++;

            } break;
        case 2: system("cls");
                printf("**AMB TEATRO**BAJAS ORQUESTAS**\n");
            do{
                printf("Ingrese el ID de LA ORQUESTA:\n");
                scanf("%s",auxLen);
                check=validadorInputint(auxLen,LENSTR);
                if(check==1)
                {
                    id=atoi(auxLen);
                }
                }while(check!=1);
                removeOrq(orquesta,TAMO,id);
            break;

        case 3:printf("**AMB TEATRO**LISTADO DE ORQUESTAS**\n");
                printOrquestas(orquesta,TAMO);

            break;

        case 4:printf("AGREGAR UN MUSICO \n");
            check=dataEntryMusico(musico,TAMM,orquesta,TAMO,lastIdMusico);
            if(check==1){
            lastIdMusico++;

            } break;


        case 5:
            do{
                printMusicos(musico,TAM,tiposInst,TAML,tiposOrq);
                printf("Ingrese el ID del musico:\n");
                scanf("%s",auxLen);
                check=validadorInputint(auxLen,LENSTR);
                if(check==1)
                {
                    id=atoi(auxLen);
                  editMusico(musico,TAM,id,tiposInst,tiposOrq,TAML);
                }
                }while(check!=1);

            break;

case 6:system("cls");
                printf("**AMB TEATRO**BAJA MUSICO**\n");
            do{printMusicos(musico,TAM,tiposInst,TAML,tiposOrq);
                printf("Ingrese el ID del musico:\n");
                scanf("%s",auxLen);
                check=validadorInputint(auxLen,LENSTR);
                if(check==1)
                {
                    id=atoi(auxLen);
                    removeMusico( musico,  TAMM,  id, tiposInst, tiposOrq, TAML);
                }
                }while(check!=1);

            break;
case 7: printMusicos(musico,TAM,tiposInst,TAML,tiposOrq);
        break;
case 8:check=dataEntryInst(instrumentos,TAMI,lastIdInst);
         if(check==1){
            lastIdInst++;

            } break;

case 9:printInstrumentos(instrumentos,TAMI);
    break;
case 10:printf("Confirma salir?:");
            printf("1-SI | 2-NO ");
            scanf("%d",&salir);
            if(salir==1)
            {
                break;

            }
            else if(salir==2)
            {
                main();
            }

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");

    }while(salir != 1);

    return 0;
}




/*FUNCIONES */


int dataEntryOrq(eOrquesta orquesta[],int tamo,int lastIdOrq)
{
    char auxLen[100];
    char name[LENSTR];
    char lugar[LENSTR];
  int tipo;
    int auxint;
    int val=0;
    int check=0;
    int resultado=0;
    float salary;

do{
        printf("Ingrese nombre orquesta: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);

     if(check==1)
        {
            strcpy(name,auxLen);
            val=validaCadenas(name,LENSTR);
        }
}while(val!=1 || check!=1);


do{
        printf("Ingrese Lugar: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);
     if(check==1)
        {
            strcpy(lugar,auxLen);
            val=validaCadenas(lugar,LENSTR);
        }


}while(val!=1 || check!=1);


do{
        printf("Ingrese Tipo: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorInputint(auxLen,LENSTR);
     if(check==1)
        {
            tipo=atoi(auxLen);
            resultado=addOrq(orquesta,tamo,lastIdOrq,name,lugar,tipo);
        }
}while(val!=1 || check!=1);


resultado=1;
         return resultado;
}
//////////////////////////
int addOrq(eOrquesta *orquesta,int tam,int id, char name[],char lugar[],int tipo)
{
int resultado=0;
int l;
int check=0;

l=searchFreeOrq(orquesta,tam);

    if(l!=-1)
        {orquesta[l].idOrq=id;
        strcpy(orquesta[l].nombreOrq,name);
        strcpy(orquesta[l].lugarOrq,lugar);
        orquesta[l].tipoOrq=tipo;
        orquesta[l].isEmpty=0;
        check=1;

            if(check==1)
                {   resultado=1;
                    system("cls");
                        printf("Carga exitosa!");

                }

        }
return resultado;

}

int initx(eOrquesta orquesta[],int tamo,eMusico musico[],int tamm,eInstrumento instrumentos[],int tami)
{ int resultado=0;
    for(int i = 0; i < tamo; i++)
    {
        orquesta[i].isEmpty = 1;

    }
    for(int i = 0; i < tamm; i++)
    {

        musico[i].isEmpty = 1;

    }
    for(int i = 0; i < tami; i++)
    {

        instrumentos[i].isEmpty = 1;
    }


    return resultado;
}

int menu(void)
{
    int opcion;

    system("cls");
    printf("****** ABM TEATRO *******\n\n");
    printf("1-Alta Orquesta\n");
    printf("2-Baja Orquesta\n");
    printf("3-Imprimir Orquesta\n");
    printf("4-Agregar Musico\n");
    printf("5-Modificar Musico\n");
    printf("6-Baja Musico\n");
    printf("7-Imprimir Musicos\n");
    printf("8-Agregar Instrumento\n");
    printf("9-Imprimir Instrumentos\n");
    printf("----------------\n");
    scanf("%d",&opcion);

    return opcion;
}

int validadorLen(char auxLen[],int lenstr)
{   int check=0;
    int vlen;
    vlen=strlen(auxLen);
    if(vlen<lenstr)
    {
        check=1;
    }
    return check;

}

int validadorInputint(char auxlen[],int lenstr)
{
    int i;
    int cont;
    int flag=0;

    int resultado=1;
cont=strlen(auxlen);
for(i=0;i<lenstr;i++)
{  if(i+1<=cont)
        {
                     if(auxlen[i]<48 || auxlen[i]>57)
                    {
                          resultado=0;
                          break;
                    }
        }
        else
            {
            break;
            }
}
return resultado;

}

int searchFreeOrq(eOrquesta orquesta[],int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( orquesta[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int searchFreeMusico(eMusico musico[],int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( musico[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int searchFreeInst(eInstrumento instrumentos[],int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( instrumentos[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int validaCadenas(char x[],int lenstr)
{
    int i;
    int res=0;
    int len;

    len=strlen(x);

    for(i=0;i<len;i++)
    {
            if(isalpha(x[i])&&len<=lenstr)
            {
                res=1;
            }
            else
            {
                break;
            }
    }



    return res;
}

int removeOrq(eOrquesta* orquesta, int tam, int id)
{
    int check=-1;
    int opcion;
    int posicion;

    posicion=findOrquestaById(orquesta,tam,id);
        if(posicion!=-1){
                            printOrq(orquesta[posicion]);
                            printf("Desea dar de baja este usuario?\n");
                            printf("1-SI | 2-NO\n");
                            scanf("%d",&opcion);

                            switch(opcion)
                                {
                                case 1: orquesta[posicion].isEmpty=1;
                                        check=0;
                                        printf("Baja exitosa\n");
                                        break;
                                case 2:printf("Baja cancelada\n");
                                        break;
                                }
                        }



 return check;
}

void printOrq(eOrquesta x)
{

    printf(" %d   %s  %s    %d  \n",
           x.idOrq,
           x.nombreOrq,
           x.lugarOrq,
           x.tipoOrq
          );

printf("-----------------------------------------------\n");
}
//////////////////////////////////////
void printOrquestas(eOrquesta orquesta[], int tam)
{

    int flag = 0;
    system("cls");
    int i;

    printf("ID    NOMBRE    LUGAR   TIPO\n");
    for(i=0; i < tam; i++)
    {
        if( orquesta[i].isEmpty == 0)
        {
            printOrq(orquesta[i]);
            flag = 1;
        }
    }
    if (flag==0)
    {
        system("cls");
        printf("NO HAY NADA QUE MOSTRAR\n");
    }
}
int findOrquestaById(eOrquesta* orquesta, int tam,int id)
{ int i;
int null=-1;
    for(i=0;i<tam;i++)
    { if(orquesta[i].idOrq==id && orquesta[i].isEmpty==0)
                {
                 null=i;
                 break;
                }

    }
    if(null==-1)
    {
                printf("No se encontro ninguna Orquesta con ese ID\n");
    }

 return null;
}
int editOrq(eOrquesta *orquesta,int tam,int id)
{
    int confirm=0;
    int opcion;
    char auxName[25];
    char auxlen[LENSTR];
    int check;
    int resultado=0;
    int tipo;

system("cls");


        confirm = findOrquestaById(orquesta,tam,id);

    if(confirm!=-1){
            do{
        system("cls");
printf("ID   NOMBRE  LUGAR   TIPO");
        printOrq(orquesta[confirm]);
        printf("________________________________\n");
            printf("Elija la modificacion que desea realizar\n");
            printf(" 1- NOMBRE \n 2- LUGAR \n 3-TIPO \n");
            fflush(stdin);
            scanf("%s",auxlen);
            check=validadorInputint(auxlen,LENSTR);
            if(check==1){
            opcion=atoi(auxlen);
                }
            }while(check!=1);
        switch(opcion)
        {
        case 1:system("cls");
                printf("ID   NOMBRE  LUGAR   TIPO");
                printOrq(orquesta[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo nombre \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(orquesta[confirm].nombreOrq,auxName);
                printf("ID   NOMBRE  LUGAR   TIPO");
                printOrq(orquesta[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 2: system("cls");
                printf("ID   NOMBRE  LUGAR   TIPO");
                printOrq(orquesta[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo lugar \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(orquesta[confirm].lugarOrq,auxName);
                 printf("ID   NOMBRE  LUGAR   TIPO");
                printOrq(orquesta[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 3:system("cls");
                 printf("ID   NOMBRE  LUGAR   TIPO");
                printOrq(orquesta[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo tipo \n");
                fflush(stdin);
                scanf("%s",auxlen);
                check=validadorInputint(auxlen,LENSTR);
                if(check==1){
                                tipo=atoi(auxlen);

                                orquesta[confirm].tipoOrq=tipo;
                                printf("ID   NOMBRE  LUGAR   TIPO");
                                printOrq(orquesta[confirm]);
                                resultado=1;
                                printf("Cambio exitoso\n");
                                break;
                            }
        }
    }
    return resultado;

}
///////////// MUSICOS*/



int dataEntryMusico(eMusico musico[],eOrquesta orquesta[],int tamo,int tamm,int lastIdMusico)
{
    char auxLen[100];
    char nombre[LENSTR];
    char apellido[LENSTR];
    int idOrq;
    int idInst;
    int edad;;
    int auxInt;
    int val=0;
    int check=0;
    int resultado=0;
    float salary;

do{
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);

     if(check==1)
        {
            strcpy(nombre,auxLen);
            val=validaCadenas(nombre,LENSTR);
        }
}while(val!=1 || check!=1);


do{
        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);
     if(check==1)
        {
            strcpy(apellido,auxLen);
            val=validaCadenas(apellido,LENSTR);
        }


}while(val!=1 || check!=1);


do{
        printf("Ingrese edad: ");
        gets(auxLen);
        check=validadorInputint(auxLen,LENSTR);
     if(check==1)
        {
            edad=atoi(auxLen);

        }
}while(val!=1 || check!=1);
do{
        printf("Ingrese idOrq ");
        printOrquestas(orquesta,tamo);
        gets(auxLen);
        check=validadorInputint(auxLen,LENSTR);
     if(check==1)
        {
            idOrq=atoi(auxLen);

        }
}while(val!=1 || check!=1);
do{
        printf("Ingrese idInst: ");
        gets(auxLen);
        check=validadorInputint(auxLen,LENSTR);
     if(check==1)
        {
            idInst=atoi(auxLen);
            resultado=addMusico(musico,tamm,lastIdMusico,nombre,apellido,edad,idOrq,idInst);
        }
}while(val!=1 || check!=1);

resultado=1;
         return resultado;
}
//////////////////////////
int addMusico(eMusico musico[],int tami,int lastIdMusico,char nombre[],char apellido[],int edad,int idOrq,int idInst)
{
int resultado=0;
int l;
int check=0;

l=searchFreeMusico(musico,tami);

    if(l!=-1)
        {musico[l].idM=lastIdMusico;
        strcpy(musico[l].nombreM,nombre);
        strcpy(musico[l].apellidoM,apellido);
        musico[l].edadM=edad;
        musico[l].idOrq=idOrq;
        musico[l].idInst=idInst;
        musico[l].isEmpty=0;
        check=1;

            if(check==1)
                {   resultado=1;
                    system("cls");
                        printf("Carga exitosa!");

                }

        }
return resultado;
}
/////////////////////////
void printMusico(eMusico x,eTipoInst tiposInst[],int taml,eTipoOrquesta tiposOrq[])
{
    char auxTipoInst[25];
    char auxTipoOrq[25];
int i;

for(i=0;i<taml;i++)
{
    if(x.idInst==tiposInst[i].idTi)
    {
        strcpy(auxTipoInst,tiposInst[i].tipoInst);
    }
}
for(i=0;i<taml;i++)
{
    if(tiposOrq[i].idTo==x.idOrq)
    {
        strcpy(auxTipoOrq,tiposOrq[i].tipoOrq);
    }
}
    printf(" %d   %s      %s        %d           %s       %s \n",
           x.idM,
           x.nombreM,
           x.apellidoM,
           x.edadM,
           auxTipoOrq,
           auxTipoInst
          );

printf("-----------------------------------------------\n");
}
//////////////////////////////////////
void printMusicos(eMusico musico[], int tam,eTipoInst tiposInst[],int taml,eTipoOrquesta tiposOrq[])
{

    int flag = 0;
    system("cls");
    int i;

    printf("ID    NOMBRE    APELLIDO   EDAD  ORQUESTA  INSTRUMENTO\n");
    for(i=0; i < tam; i++)
    {
        if( musico[i].isEmpty == 0)
        {
             printMusico(musico[i],tiposInst,taml,tiposOrq);

            flag = 1;
        }

    }
    if (flag==0)
    {
        system("cls");
        printf("NO HAY NADA QUE MOSTRAR\n");
    }
}

int removeMusico(eMusico* musico, int tam, int id,eTipoInst tipoInst[],eTipoOrquesta tipoOrq[],int taml)
{
    int check=-1;
    int opcion;
    int posicion;

    posicion=findMusicoById(musico,tam,id);
        if(posicion!=-1){
                            printMusico(musico[posicion], tipoInst, taml, tipoOrq);
                            printf("Desea dar de baja este usuario?\n");
                            printf("1-SI | 2-NO\n");
                            scanf("%d",&opcion);

                            switch(opcion)
                                {
                                case 1: musico[posicion].isEmpty=1;
                                        check=0;
                                        printf("Baja exitosa\n");
                                        break;
                                case 2:printf("Baja cancelada\n");
                                        break;
                                }
                        }



 return check;
}

int findMusicoById(eMusico* musico, int tam,int id)
{ int i;
int null=-1;
    for(i=0;i<tam;i++)
    { if(musico[i].idM==id && musico[i].isEmpty==0)
                {
                 null=i;
                 break;
                }

    }
    if(null==-1)
    {
                printf("No se encontro ninguna Orquesta con ese ID\n");
    }

 return null;
}

int editMusico(eMusico *musico,int tam,int id,eTipoInst tiposInst[],eTipoOrquesta tiposOrq[],int taml)
{
    int confirm=0;
    int opcion;
    char auxName[25];
    char auxlen[LENSTR];
    int edad;
    int idOrq;
    int idInst;
    int check;
    int resultado=0;
    int tipo;

system("cls");


        confirm = findMusicoById(musico,tam,id);

    if(confirm!=-1){
            do{
        system("cls");
printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
        printMusico(musico[confirm],tiposInst,taml,tiposOrq);
        printf("________________________________\n");
            printf("Elija la modificacion que desea realizar\n");
            printf(" 1- NOMBRE \n 2- APELLIDO \n 3-EDAD \n 4-ORQUESTA \n 5-INSTRUMENTO  \n");
            fflush(stdin);
            scanf("%s",auxlen);
            check=validadorInputint(auxlen,LENSTR);
            if(check==1){
            opcion=atoi(auxlen);
                }
            }while(check!=1);
        switch(opcion)
        {
        case 1:system("cls");
               printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                printf("__________________________\n");
                printf("Ingrese el nuevo nombre \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(musico[confirm].nombreM,auxName);
                printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 2: system("cls");
                printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                printf("__________________________\n");
                printf("Ingrese el nuevo lugar \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(musico[confirm].apellidoM,auxName);
                 printf("ID   NOMBRE  APELLIDO  EDAD  IDORQ   IDINSTRUMENTO\n");
                printMusico(musico[confirm],tiposInst,taml ,tiposOrq);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 3:system("cls");
               printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                printf("__________________________\n");
                printf("Ingrese el nuevo tipo \n");
                fflush(stdin);
                scanf("%s",auxlen);
                check=validadorInputint(auxlen,LENSTR);
                if(check==1){
                                edad=atoi(auxlen);

                                musico[confirm].edadM=edad;
                                printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                                printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                                resultado=1;
                                printf("Cambio exitoso\n");}
                                break;
        case 4:system("cls");
                            printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                            printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                            printf("__________________________\n");
                            printf("Ingrese el nuevo tipo \n");
                            fflush(stdin);
                            scanf("%s",auxlen);
                            check=validadorInputint(auxlen,LENSTR);
                            if(check==1){
                                            idOrq=atoi(auxlen);

                                            musico[confirm].idOrq=idOrq;
                                            printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                                            printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                                            resultado=1;
                                            printf("Cambio exitoso\n");}
                                            break;

        case 5:system("cls");
                       printf("ID   NOMBRE  APELLIDO EDAD  IDORQ   IDINSTRUMENTO\n");
                        printMusico(musico[confirm],tiposInst,taml,tiposOrq);
                        printf("__________________________\n");
                        printf("Ingrese el nuevo tipo \n");
                        fflush(stdin);
                        scanf("%s",auxlen);
                        check=validadorInputint(auxlen,LENSTR);
                        if(check==1){
                                        idInst=atoi(auxlen);

                                        musico[confirm].idInst=idInst;
                                        printf("ID   NOMBRE  APELLIDO    EDAD  IDORQ   IDINSTRUMENTO\n");
                                        printMusico(musico[confirm],tiposInst,taml,tiposOrq);

                                        resultado=1;
                                        printf("Cambio exitoso\n");
                                        break;
                                    }
                        }

    return resultado;

}}
///////////// INSTRUMENTOS

int dataEntryInst(eInstrumento instrumentos[],int tami,int lastIdInst)
{
    char auxLen[100];
    char nombreI[LENSTR];
    int tipoI;
    int auxint;
    int val=0;
    int check=0;
    int resultado=0;
    float salary;

do{
        printf("Ingrese nombre del instrumento: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);

     if(check==1)
        {
            strcpy(nombreI,auxLen);
            val=validaCadenas(nombreI,LENSTR);
        }
}while(val!=1 || check!=1);

do{
        printf("Ingrese el Tipo: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorInputint(auxLen,LENSTR);
     if(check==1)
        {
            tipoI=atoi(auxLen);
            resultado=addInst(instrumentos,tami,lastIdInst,nombreI,tipoI);
        }
}while(val!=1 || check!=1);


resultado=1;
         return resultado;
}
//////////////////////////

int addInst(eInstrumento *instrumentos,int tam,int id, char name[],int tipo)
{
int resultado=0;
int l;
int check=0;

l=searchFreeInst(instrumentos,tam);

    if(l!=-1)
        {instrumentos[l].idInst=id;
        strcpy(instrumentos[l].nombreInst,name);
        instrumentos[l].tipoInst=tipo;
        instrumentos[l].isEmpty=0;
        check=1;

            if(check==1)
                {   resultado=1;
                    system("cls");
                        printf("Carga exitosa!");

                }

        }
return resultado;

}

void printInstrumento(eInstrumento x)
{

    printf(" %d   %s      %d       \n",
           x.idInst,
           x.nombreInst,
           x.tipoInst
          );

printf("-----------------------------------------------\n");
}
//////////////////////////////////////
void printInstrumentos(eInstrumento instrumentos[], int tam)
{

    int flag = 0;
    system("cls");
    int i;

    printf("ID    NOMBRE    TIPO \n");
    for(i=0; i < tam; i++)
    {
        if( instrumentos[i].isEmpty == 0)
        {
            printInstrumento(instrumentos[i]);
            flag = 1;
        }
    }
    if (flag==0)
    {
        system("cls");
        printf("NO HAY NADA QUE MOSTRAR\n");
    }
}
int hardcodearMusicos( eMusico musico[], int tam, int cantidad)
{
    int cont = 0;

    eMusico suplentes[]=
    {
        { 1, "Juan","fait",20,2, 3},
       { 2, "carla","sanchez",24,3, 1},
       { 3, "melina","ramirez",14,2, 1},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            musico[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

int hardcodearOrquestas(eOrquesta orquestas[], int tam, int cantidad)
{
    int cont = 0;

    eOrquesta suplentes[]=
    {
        { 1, "los sinfo","Piso uno",1},
       { 2, "la fila","Piso dos",1,},
       { 3, "camareando","Piso tres",2},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            orquestas[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
int hardcodearInstrumentos(eInstrumento instrumentos[], int tam, int cantidad)
{
    int cont = 0;

    eInstrumento suplentes[]=
    {
        { 1, "violin",1},
       { 2, "guitarra",3,},
       { 3, "flauta",2},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            instrumentos[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

