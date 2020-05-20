#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dawawarehouse3.h"
#include "funcionesMoto.h"
#include "informes.h"

#define TAMMOTO 5

#define TAMTIPO 4
#define TAMCOL 5
#define TAMSERV 4
#define TAMTRAB 10
#define TAMCLI 5

// < >

/** \brief Hardcodea los arreglos de tipo, color y servicio
 *
 * \param El arreglo de tipos
 * \param El arreglo de colores
 * \param El arreglo de servicios
 * \param El tamaño del arreglo de tipos
 * \param El tamaño del arreglo de colores
 * \param El tamaño del arreglo de servicios
 * \return void
 *
 */
void hardcodear(eTipo[], eColor[], eServicio[], int, int, int);

//HARDCODEO INTERNO-------------------------------------------------------
void hardcodearMotos(eMoto[], int);
void hardcodearTrabajos(eTrabajo[], int);
void hardcodearClientes(eCliente [], int);
//-----------------------------------------------------------------------

int main()
{
    char seguir = 's';
    char confirma;

    int proximoIdMoto = 10005;
    int proximoIdTrabajo =1005;

    int hayMoto=1;

    eMoto motos[TAMMOTO];
    eTipo tipos[TAMTIPO];
    eColor colores[TAMCOL];
    eServicio servicios[TAMSERV];
    eTrabajo trabajos[TAMTRAB];
    eCliente clientes[TAMCLI];

    hardcodear(tipos, colores, servicios, TAMTIPO, TAMCOL, TAMSERV);

    inicializarMotos(motos, TAMMOTO);
    inicializarTrabajos(trabajos, TAMTRAB);
//HARDCODEO INTERNO-----------------------------------------------------------------
    hardcodearMotos(motos, TAMMOTO);
    hardcodearTrabajos(trabajos, TAMTRAB);
    hardcodearClientes(clientes, TAMCLI);
//---------------------------------------------------------------------

        do{
        switch(menu())
        {
        case 'a':
            if(altaMoto(proximoIdMoto, motos, TAMMOTO) == 1)
            {
                proximoIdMoto++;
                hayMoto=1;
            }
            break;
        case 'b':
            if(hayMoto==0)
            {
                printf("\nERROR. No hay ninguna moto ingresada.\n");
            }
            else
            {
                modificarMoto(motos, TAMMOTO);
            }
            break;
        case 'c':
            if(hayMoto==0)
            {
                printf("\nERROR. No hay ninguna moto ingresada.\n");
            }
            else
            {
                bajaMoto(motos, TAMMOTO);
            }
            break;
        case 'd':
            if(hayMoto==0)
            {
                printf("\nERROR. No hay ninguna moto ingresada.\n");
            }
            else
            {
                listarMotos(motos, TAMMOTO, clientes, TAMCLI);
            }
            break;
        case 'e':
            system("cls");
            listarTipos(tipos, TAMTIPO);
            break;
        case 'f':
            system("cls");
            listarColores(colores, TAMCOL);
            break;
        case 'g':
            system("cls");
            listarServicios(servicios, TAMSERV);
            break;
        case 'h':
            if((altaTrabajo (trabajos, TAMTRAB, proximoIdTrabajo))==1)
            {
                proximoIdTrabajo++;
            }
            break;
        case 'i':
            system("cls");
            listarTrabajos(trabajos, TAMTRAB);
            break;
        case 'j':
            menuInformes(motos, TAMMOTO);
            fflush(stdin);
        case 'k':
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
    return 0;
}

void hardcodear(eTipo vec1[], eColor vec2[], eServicio vec3[], int tTipo, int tColor, int tServicio)
{
    for(int i=0; i<tTipo; i++)
    {
        vec1[i].id = idTipo[i];
        strcpy(vec1[i].descripcion, descripcionTipo[i]);
    }
    for(int i=0; i<tColor; i++)
    {
        vec2[i].id = idColor[i];
        strcpy(vec2[i].nombreColor, nombreCol[i]);
    }
    for(int i=0; i<tServicio; i++)
    {
        vec3[i].id = idServicio[i];
        strcpy(vec3[i].descripcion, descripcionServicio[i]);
        vec3[i].precio = precioServicio[i];
    }

}

//HARDCODEO INTERNO--------------------------------------------------------
void hardcodearMotos(eMoto vec[], int tam)
{
    for(int i=0; i<5; i++)
    {
        vec[i].id=idMoto[i];
        strcpy(vec[i].marca, marca[i]);
        vec[i].idTipo=t[i];
        vec[i].idColor=col[i];
        vec[i].cilindrada=cil[i];
        vec[i].isEmpty=0;
    }
    vec[0].idCliente =1002;
    vec[1].idCliente = 1003;
    vec[2].idCliente = 1000;
    vec[3].idCliente = 1004;
    vec[4].idCliente =1001;
}

void hardcodearTrabajos(eTrabajo vec[], int tam)
{
    for(int i=0; i<5; i++)
    {
        vec[i].id=idT[i];
        vec[i].idMoto=idMotoT[i];
        vec[i].idServicio=idServicioT[i];
        vec[i].fecha.dia=diaT[i];
        vec[i].fecha.mes=mesT[i];
        vec[i].fecha.anio=anioT[i];
        vec[i].isEmpty=0;
    }
}
//-------------------------------------------------------------------------------------

void hardcodearClientes(eCliente v[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        v[i].id=idCliente[i];
        strcpy(v[i].nombre, nombreCliente[i]);
        v[i].sexo=sexoCliente[i];
    }
}
