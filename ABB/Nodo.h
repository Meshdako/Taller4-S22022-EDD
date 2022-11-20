#ifndef NODO_H
#define NODO_H

#include <iostream>

#include "../Clases/Elector.h"

using namespace std;

class Nodo{
    public:
        long _key;
        Elector _elector;

        Nodo *izq;
        Nodo *der;

        Nodo();
        Nodo(long, Elector);
        virtual ~Nodo();
};

#endif  //NODO_H