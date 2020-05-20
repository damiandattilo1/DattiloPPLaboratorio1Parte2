#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesMoto.h"


int menu()
{
    char opcion;

    system("cls");
    printf("***** Gestion de Motos *****\n\n");
    printf("a. Alta Moto\n");
    printf("b. Modificar Moto\n");
    printf("c. Baja Moto\n");
    printf("d. Listar Motos\n");
    printf("e. Listar Tipos\n");
    printf("f. Listar colores\n");
    printf("g. Listar servicios\n");
    printf("h. Alta trabajo\n");
    printf("i. Listar trabajos\n");
    printf("j. Informes\n");
    printf("k. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

int altaMoto(int idx, eMoto vec[], int tam)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);

    eMoto auxMoto;

    system("cls");

    printf("***** Alta moto *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxMoto.id = idx;

        printf("Ingrese marca: ");
        fflush(stdin);
        gets(auxMoto.marca);

        do
        {
            printf("Ingrese id tipo: ");
            fflush(stdin);
            scanf("%d", &auxMoto.idTipo);
            if(auxMoto.idTipo < 1000 || auxMoto.idTipo > 1003)
            {
                printf("\nERROR id no valido. Ingrese nuevamente\n");
            }
        }while(auxMoto.idTipo < 1000 || auxMoto.idTipo > 1003);

        do
        {
            printf("Ingrese id color: ");
            scanf("%d", &auxMoto.idColor);
            if(auxMoto.idColor < 10000 || auxMoto.idColor > 10004)
            {
                printf("\nERROR id no valido. Ingrese nuevamente\n");
            }
        }while(auxMoto.idColor < 10000 || auxMoto.idColor > 10004);

        printf("Ingrese cilindrada: ");
        scanf("%d", &auxMoto.cilindrada);

        auxMoto.isEmpty = 0;

        vec[indice] = auxMoto;
        todoOk = 1;

    }

    return todoOk;

}

void modificarMoto(eMoto vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    int nuevoColor;
    int nuevaCilindrada;

    system("cls");
    printf("***** Modificar moto *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarMoto(id, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de una moto con el Id: %d\n", id);
    }
    else
    {
        mostrarMoto(vec[indice]);


        printf("\nModifica color?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            printf("Ingrese nuevo id color: ");
            scanf("%d", &nuevoColor);

            vec[indice].idColor = nuevoColor;
            printf("Se ha actualizado el color con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }

        printf("\nModifica cilindrada?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            printf("Ingrese nuevo id cilindrada: ");
            scanf("%d", &nuevaCilindrada);

            vec[indice].cilindrada = nuevaCilindrada;
            printf("Se ha actualizado la cilindrada con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

void bajaMoto(eMoto vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja motoo *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarMoto(id, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de una moto con el Id: %d\n", id);
    }
    else
    {
        mostrarMoto(vec[indice]);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

int buscarMoto(int id, eMoto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int buscarLibre(eMoto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void inicializarMotos(eMoto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void inicializarTrabajos (eTrabajo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

void listarMotos(eMoto vec[], int tam, eCliente v[], int tamCli)
{
    int flag = 0;
    printf("***** Listado de Motos *****\n");
    printf("  Id      Marca      Id Tipo        Id Color       Cilindrada       Cliente   \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarMotoCliente(vec[i], v[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay motos que listar ***\n");
    }
}

void listarTipos(eTipo vec[], int tam)
{
    printf("***** Listado de Tipos de motos *****\n");
    printf("  Id      Tipo      \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d       %10s      \n", vec[i].id, vec[i].descripcion);
    }
}

void listarColores(eColor vec[], int tam)
{
    printf("***** Listado de Colores de motos *****\n");
    printf("  Id      Nombre      \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d       %10s      \n", vec[i].id, vec[i].nombreColor);
    }
}

void listarServicios(eServicio vec[], int tam)
{
    printf("***** Listado de Servicios de motos *****\n");
    printf("  Id      Descripcion       Precio         \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d       %10s        %d         \n", vec[i].id, vec[i].descripcion, vec[i].precio);
    }
}

void listarTrabajos (eTrabajo vec[], int tam)
{
    system("cls");
    if((buscarTrabajoLibre(vec, tam))==-1)
    {
        printf("ERROR: No hay trabajos que listar");
    }
    else
    {
        printf("***** Listado de Trabajos *****\n");
        printf("Id        Id moto     Id Servicio    Fecha         \n\n");
        for(int i=0; i<tam && vec[i].isEmpty!=1; i++)
        {

            printf("%d       %d        %d        %d/%d/%d \n", vec[i].id, vec[i].idMoto, vec[i].idServicio, vec[i].fecha.dia, vec[i].fecha.mes, vec[i].fecha.anio);
        }
    }
}


void mostrarMoto(eMoto x)
{

    printf("%d  %10s     %d    %d   %d    \n", x.id, x.marca, x.idTipo, x.idColor, x.cilindrada);
}

void mostrarMotoCliente(eMoto x, eCliente y)
{

    printf("%d  %10s     %d    %d   %d    ", x.id, x.marca, x.idTipo, x.idColor, x.cilindrada);
    puts(y.nombre);
    printf("\n\n");
}



int altaTrabajo(eTrabajo vec[], int tam, int idTrabajo)
{
    int indice;
    int idMoto;
    int idServicio;
    int dia;
    int mes;
    int anio;
    int todoOk=0;

    indice=buscarTrabajoLibre(vec, tam);
    if(indice==-1)
    {
        printf("\nNo se pueden agregar mas trabajos\n\n");
    }
    else
    {
        system("cls");
        printf("\n******ALTA TRABAJO**********\n\n");
        printf("Ingrese el Id de la moto: ");
        fflush(stdin);
        scanf("%d", &idMoto);

        do
        {
            printf("\nIngrese id del servicio: ");
            fflush(stdin);
            scanf("%d", &idServicio);
            if(idServicio < 20000 || idServicio > 20003)
            {
                printf("\n\nERROR Servicio incorrecto. Ingrese nuevamente\n");
            }
        }while(idServicio < 20000 || idServicio > 20003);

        printf("\nIngrese dia del servicio: ");
        scanf("%d", &dia);
        printf("\nIngrese mes del servicio: ");
        scanf("%d", &mes);
        printf("\nIngrese anio del servicio: ");
        scanf("%d", &anio);

        vec[indice].id = idTrabajo;
        vec[indice].idMoto = idMoto;
        vec[indice].idServicio = idServicio;
        vec[indice].fecha.dia= dia;
        vec[indice].fecha.mes = mes;
        vec[indice].fecha.anio = anio;
        vec[indice].isEmpty = 0;

        todoOk=1;

    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


