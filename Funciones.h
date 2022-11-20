#include <iostream>     //utilizada para la entrada y salida de datos
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores
#include <cctype>

//Clases
#include "Clases/Direccion.h"
#include "Clases/Fecha.h"
#include "Clases/Run.h"
#include "Clases/Persona.h"
#include "Clases/Elector.h"

#include "ABB/Nodo.h"

using namespace std;

typedef Nodo * ABB;

typedef struct miEstructura miEstructura;

typedef miEstructura misEstructuras[11];

void Inicializacion(misEstructuras &E);

/* Funciones globales */

void PressEnterToContinue();

void insertarABB(long in_key, ABB &T, Elector e);

void postOrden(ABB &T);

/* Funciones del Taller 4. */

// Menu1
// Implementa correctamente una función que recibe como parámetros un arreglo de ABB y un DV, y a partir de estos datos muestra los nombres de los electores utilizando recorrido PostOrden.
void ElectoresXDV(misEstructuras &E, char in_DV);

// Menu2
// Implementa correctamente una función que recibe un arreglo de ABB's, el número de RUT y DV para mostrar por pantalla toda la información del elector que coincida con la información ingresada.
void BuscarKey(ABB &T, long in_Run);

void BuscarXRut(misEstructuras &E, long in_Run, char in_DV);

// Menu3
// Deberá mostrar la información del elector que tenga el número de RUT más alto.
void MayorKey(ABB &T, Elector &in_Mayor);

void MayorRut(misEstructuras &E);

// Menu4
// Implemente correctamente una función que recibe un arreglo de ABB's para mostrar el elector con menor edad para cada DV existente.
void MenorAnho(ABB &T, Elector &in_Menor);

void MenorXDV(misEstructuras &E);

/* Menú de opciones */

void Menu(misEstructuras &E);

/* Funciones para leer el archivo */

// Función que lee el archivo "servel" y guarda la información en un Vector.
void archivoAVector(string nombreArchivo, Elector p[] , int &indice);

// Función que guarda la información de una línea en un Vector, mediante un caracter Delimitador.
vector<string> split(string lineaASeparar, char delimitador);