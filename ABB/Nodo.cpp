#include "Nodo.h"

Nodo::Nodo()
{

}

Nodo::Nodo(long in_key, Elector in_Elector)
{
    _key = in_key;
    _elector = in_Elector;
    izq = NULL;
    der = NULL;
}

Nodo::~Nodo()
{
    //Destructor.
}