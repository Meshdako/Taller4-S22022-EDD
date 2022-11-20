/**
 * @author Martín Sobarzo Huerta (MESH)
 * 7/11/2022
 * Estructura de Datos
 * Mauro Castillo
*/

#include <iostream>

#include "Funciones.h"
#include "Funciones.cpp"

//Clases
#include "Clases/Direccion.h"
#include "Clases/Direccion.cpp"
#include "Clases/Fecha.h"
#include "Clases/Fecha.cpp"
#include "Clases/Run.h"
#include "Clases/Run.cpp"
#include "Clases/Persona.h"
#include "Clases/Persona.cpp"
#include "Clases/Elector.h"
#include "Clases/Elector.cpp"

#include "ABB/Nodo.h"
#include "ABB/Nodo.cpp"

using namespace std;

#define MAX_VECTOR 1001

int main()
{
    int indice = 0; //indice del vector  o cantidad actual de elementos en el vector
    string nombreArchivo ="servel.txt";
    
    misEstructuras E;

    Inicializacion(E);

    for(int i = 0; i < 11; i++){
        cout << E[i]._DV << " - ";
    }
    cout << endl;
    

    Elector Electores[MAX_VECTOR];

    archivoAVector(nombreArchivo, Electores, indice);
    vectorAArbol(Electores, E, indice);

    Menu(E);

    return 0;
}