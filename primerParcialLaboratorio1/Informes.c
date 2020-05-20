#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesMoto.h"
#include "informes.h"

void menuInformes(eMoto vec[], int tam)
{
    char seguir = 's';
    char confirma;
    do
    {
        switch(mostrarMenuInformes())
        {
        case 1:
            mostrarXColor(vec, tam);
            break;
        case 2:
            mostrarXTipo(vec, tam);
            break;
        case 3:
            mostrarMayorCilindrada(vec, tam);
            break;
        case 4:
            printf("\nInforme 4");
            break;
        case 5:
            contarColorYTipo(vec, tam);
            break;
        case 6:
            mostrarColorMasElegido(vec, tam);
            break;
        case 7:
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }while(seguir == 's');
}

int mostrarMenuInformes()
{
    int opcion;

    system("cls");
    printf("***** Informes *****\n\n");
    printf("1. Mostrar motos por color\n");
    printf("2. Mostrar motos por tipo\n");
    printf("3. Mostrar la moto de mayor cilindrada\n");
    printf("4. \n");
    printf("5. Contar motos por color y tipo\n");
    printf("6. Mostrar color mas elegido\n");
    printf("7. Salir\n");

    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void mostrarXColor(eMoto vec[], int tam)
{
    int idColor;
    int flag=0;

    printf("****MOSTRAR POR COLOR********\n\n");
    printf("Ingrese el id del color a buscar: ");
    fflush(stdin);
    scanf("%d", &idColor);
    printf("  Id      Marca      Id Tipo        Id Color       Cilindrada\n\n");
    for(int i=0; i<tam; i++)
    {
        if(idColor == vec[i].idColor)
        {
            mostrarMoto(vec[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay ninguna moto con tal color\n");
    }
    printf("\n");
}

void mostrarXTipo(eMoto vec[], int tam)
{
    int idTipo;
    int flag=0;

    printf("****MOSTRAR POR TIPO********\n\n");
    printf("Ingrese el id del tipo a buscar: ");
    fflush(stdin);
    scanf("%d", &idTipo);
    printf("  Id      Marca      Id Tipo        Id Color       Cilindrada\n\n");
    for(int i=0; i<tam; i++)
    {
        if(idTipo == vec[i].idTipo)
        {
            mostrarMoto(vec[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay ninguna moto con tal tipo\n");
    }
    printf("\n");
}

void mostrarMayorCilindrada(eMoto vec[], int tam)
{
    eMoto aux;
    aux=vec[0];

    for(int i=0; i<tam && vec[i].isEmpty!=1; i++)
    {
        if(vec[i].cilindrada > aux.cilindrada)
        {
            aux=vec[i];
        }
    }
    printf("\n  Id      Marca      Id Tipo        Id Color       Cilindrada       Cliente   \n\n");
    mostrarMoto(aux);
}

void contarColorYTipo(eMoto vec[], int tam)
{
    int cont=0;
    int idColor;
    int idTipo;

    printf("\nIngrese id color: ");
    fflush(stdin);
    scanf("%d", &idColor);

    printf("\nIngrese id tipo: ");
    fflush(stdin);
    scanf("%d", &idTipo);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idColor == idColor && vec[i].idTipo == idTipo)
            cont++;
    }
    if(cont==0)
    {
        printf("\nNo hay ninguna moto del tipo %d y el color %d\n", idTipo, idColor);
    }
    else
    {
        printf("\nHay %d motos del color %d y el tipo %d\n", cont, idColor, idTipo);
    }
}

void mostrarColorMasElegido(eMoto vec[], int tam)
{
    int contGris=0;
    int contNegro=0;
    int contBlanco=0;
    int contAzul=0;
    int contRojo=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idColor == 10000)
        {
            contGris++;
        }
        if(vec[i].idColor == 10001)
        {
            contNegro++;
        }
        if(vec[i].idColor == 10002)
        {
            contBlanco++;
        }
        if(vec[i].idColor == 10003)
        {
            contAzul++;
        }
        if(vec[i].idColor == 10004)
        {
            contRojo++;
        }
    }
    printf("\nEl color mas elegido es el ");
    //if(contGris>contNegro &&contGris>contBlanco && )
}
// <>
