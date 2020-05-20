#ifndef FUNCIONESMOTO_H_INCLUDED
#define FUNCIONESMOTO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int idCliente;
    int isEmpty;
}eMoto;

typedef struct
{
    int id;
    char descripcion[20];
    int precio;

}eServicio;

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;


#endif // FUNCIONESMOTO_H_INCLUDED

/** \brief Desarrolla el menu de opciones
 *
 * \return La opcion elegida por el usuario
 *
 */
int menu();

/** \brief Ingresa un nuevo elemento de moto
 *
 * \param El id que debe tener la moto
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return 0 si error, 1 si todo OK
 *
 */

int altaMoto(int, eMoto[], int);

/** \brief Modifica una moto ya ingresada
 *
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void modificarMoto(eMoto[], int);

/** \brief Da de baja una moto
 *
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void bajaMoto(eMoto[], int);

/** \brief Busca una moto segun su ID
 *
 * \param ID de la moto a buscar
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return El indice del arreglo en el cual se encuentra la moto o -1 si el ID no existe
 *
 */

int buscarMoto(int, eMoto[], int);

/** \brief Encuentra el primer elemento vacio en un arreglo de motos
 *
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return El indice del elemento o -1 si el arreglo esta completo
 *
 */

int buscarLibre(eMoto[], int);

/** \brief Declara todas las posiciones del arreglo como vacias
 *
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void inicializarMotos(eMoto[], int);

/** \brief Declara todas las posiciones del arreglo como vacias
 *
 * \param El arreglo que contiene el listado de trabajos
 * \param El tamaño del arreglo
 * \return void
 *
 */
void inicializarTrabajos (eTrabajo[], int);

/** \brief Imprime el arreglo de motos
 *
 * \param El arreglo que contiene el listado de motos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void listarMotos(eMoto[], int, eCliente[], int);

/** \brief Imprime un arreglo de tipos de motos
 *
 * \param El arreglo de tipos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void listarTipos(eTipo[], int);

/** \brief Imprime un arreglo de colores de motos
 *
 * \param El arreglo de colores
 * \param El tamaño del arreglo
 * \return void
 *
 */

void listarColores(eColor[], int);

/** \brief Imprime un arreglo de servicios de motos
 *
 * \param El arreglo de servicios
 * \param El tamaño del arreglo
 * \return void
 *
 */

void listarServicios(eServicio[], int);

/** \brief Imprime un arreglo de trabajos de motos
 *
 * \param El arreglo de trabajos
 * \param El tamaño del arreglo
 * \return void
 *
 */

void listarTrabajos (eTrabajo[], int);

/** \brief Imprime un elemento de motos
 *
 * \param El elemento
 * \return void
 *
 */

void mostrarMoto(eMoto);

void mostrarMotoCliente(eMoto, eCliente);

/** \brief Ingresa un nuevo elemento de trabajo
 *
 * \param El tamaño del arreglo
 * \param El id que debe tener el trabajo
 * \return 0 si error, 1 si todo OK
 *
 */

int altaTrabajo(eTrabajo[], int, int);

/** \brief Busca el primer elemento libre en un arreglo de trabajos
 *
 * \param El arreglo de trabajos
 * \param El tamaño del arreglo
 * \return El indice del primer elemento libre o 0 si el vector esta completo
 *
 */

int buscarTrabajoLibre(eTrabajo[], int);


