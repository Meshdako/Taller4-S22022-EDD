#include <iostream>     //utilizada para la entrada y salida de datos
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores
#include <utility>      //relacionada al intercambio entre dos elementos.
#include <cctype>

//Clases
#include "Clases/Direccion.h"
#include "Clases/Fecha.h"
#include "Clases/Run.h"
#include "Clases/Persona.h"
#include "Clases/Elector.h"

using namespace std;

/* Funciones globales */

void PressEnterToContinue();

/* Funciones del Taller 4. */

/* Menú de opciones */

void Menu();

/* Funciones para leer el archivo */

// Función que lee el archivo "servel" y guarda la información en un Vector.
void archivoAVector(string nombreArchivo, Elector p[] , int &indice);

// Función que guarda la información de una línea en un Vector, mediante un caracter Delimitador.
vector<string> split(string lineaASeparar, char delimitador);