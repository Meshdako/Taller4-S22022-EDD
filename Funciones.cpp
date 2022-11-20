#include "Funciones.h"

typedef Nodo *ABB;

typedef struct miEstructura{
    char _DV;
    ABB miArbolito;
}miEstructura;

typedef miEstructura misEstructuras[11];

/* Funciones globales */

void Inicializacion(misEstructuras &E)
{
    for (int i = 0; i < 11; i++)
    {
        if (i == 10)
            E[i]._DV = 'K';
        else
            E[i]._DV = i + '0';
    }
}

void PressEnterToContinue()
{
    cout << "Presiona Enter para continuar... " << flush;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void insertarABB(long in_key, ABB &T, Elector e)
{
    // si el ARBOL es vacío, se creo el objeto
    if (T == NULL)
    {
        T = new Nodo(in_key, e);
    }
    // avanzar hasta el nodo
    if (T->_key == in_key)
    {
        cout << "el RUT ya existe" << endl;
    }
    else{ 
        if (T->_key > in_key)
            insertarABB(in_key, T->izq, e);
        else
            insertarABB(in_key, T->der, e);
    }
}

void postOrden(ABB &T)
{
    if(T != NULL){
        postOrden(T->izq);
        postOrden(T->der);
        T->_elector.verElector();
    }
}

/* Funciones del Taller 4 */

// Menu1
void ElectoresXDV(misEstructuras &E, char in_DV)
{
    for(int i = 0; i < 11; i++){
        if(in_DV == E[i]._DV){
            postOrden(E[i].miArbolito);
        }
    }
}

// Menu2
void BuscarKey(ABB &T, long in_Run)
{
    if(T == NULL)
        cout << "RUT no encontrado." << endl;
    
    else{
        if(T->_key == in_Run)
            T->_elector.verElector();
        
        else{
            if(in_Run < T->_key)
                BuscarKey(T->izq, in_Run);
            else
                BuscarKey(T->der, in_Run);
        }
    }
}

void BuscarXRut(misEstructuras &E, long in_Run, char in_DV)
{
    for(int i = 0; i < 11; i++){
        if(in_DV == E[i]._DV){
            BuscarKey(E[i].miArbolito, in_Run);
        }
    }
}

// Menu3
void MayorKey(ABB &T, Elector &in_Mayor)
{
    if(T != NULL){
        MayorKey(T->izq, in_Mayor);
        MayorKey(T->der, in_Mayor);

        if(T->_elector.getRUN().getRun() > in_Mayor.getRUN().getRun()){
            in_Mayor = T->_elector;
        }
    }
}   

void MayorRut(misEstructuras &E)
{
    Elector in_Mayor = E[0].miArbolito->_elector;

    for(int i = 0; i < 11; i++){
        MayorKey(E[i].miArbolito, in_Mayor);
    }

    cout << "El RUT más grande del arreglo de árboles es: " << endl;
    in_Mayor.verElector();
}

// Menu4
void MenorAnho(ABB &T, Elector &in_Menor)
{
    if(T != NULL){
        MenorAnho(T->izq, in_Menor);
        MenorAnho(T->der, in_Menor);

        if(T->_elector.getFecha().getAnho() > in_Menor.getFecha().getAnho()){
            in_Menor = T->_elector;
        }
    }
}

void MenorXDV(misEstructuras &E)
{
    for(int i = 0; i < 11; i++){
        Elector in_Menor;
        MenorAnho(E[i].miArbolito, in_Menor);

        cout << "\n*****************************" << endl;
        cout << "\t\e[1mDV = " << E[i]._DV << "\e[0m" << endl;
        in_Menor.verElector();
    }
}

void Menu(misEstructuras &E)
{
    int opcion;

    long in_Run;
    char in_DV;

    do
    {
        system("clear");
        cout << "\e[1mSeleccione una opción:\e[0m" << endl;
        cout << "1.- Electores por DV" << endl;
        cout << "2.- Buscar por RUT" << endl;
        cout << "3.- Mayor RUT" << endl;
        cout << "4.- Menor edad por cada DV" << endl;
        cout << "0.- Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion)
        {
        case 0:
            cout << "\t\t\e[1mSee You Space Cowboy...\e[0m" << endl;
            PressEnterToContinue();
            break;
        case 1:
            cout << "Ingrese el DV que desea buscar: ";
            cin >> in_DV;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            ElectoresXDV(E, in_DV);
            PressEnterToContinue();
            break;
        case 2:
            cout << "Ingrese el RUT que desea buscar." << endl;
            cout << "RUT s/Puntos - s/DV: ";
            cin >> in_Run;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            cout << "DV: ";
            cin >> in_DV;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            BuscarXRut(E, in_Run, in_DV);
            PressEnterToContinue();
            break;
        case 3:
            MayorRut(E);
            PressEnterToContinue();
            break;
        case 4:
            MenorXDV(E);
            PressEnterToContinue();
            break;
        default:
            cout << "Seleccione una opción válida." << endl;
            PressEnterToContinue();
            break;
        }
    } while (opcion != 0);
}

void vectorAArbol(Elector p[], misEstructuras &E, int indice)
{
    for (int i = 0; i < indice; i++){
        for (int j = 0; j < 11; j++){
            if (p[i].getRUN().getDv() == E[j]._DV){
                insertarABB(p[i].getRUN().getRun(), E[j].miArbolito, p[i]);
            }
        }
    }
}

void archivoAVector(string nombreArchivo, Elector p[], int &indice)
{
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    archivo.open(nombreArchivo, ios::in);

    if (archivo.is_open() == true){
        while (getline(archivo, lineaObtenida, '\n')){
            // ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');

            if (indice > 0){
                RUN Run_Aux(stol(data[0]), data[1].front());

                Fecha Fecha_Aux(stoi(data[5]), stoi(data[6]), stoi(data[7]));

                Direccion Dir_Aux(data[8], stoi(data[9]), data[10]);

                Elector Elector_Aux(data[2], data[3], data[4], Run_Aux, Fecha_Aux, Dir_Aux, stoi(data[11]), stoi(data[12]), stoi(data[13]));

                p[indice] = Elector_Aux;
            }
            indice++;
        }
    }
    archivo.close();
}

vector<string> split(string lineaASeparar, char delimitador)
{
    vector<string> vector_interno;     //#include <vector>
    stringstream linea(lineaASeparar); //#include <sstream>
    string parteDelString;

    while (getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}