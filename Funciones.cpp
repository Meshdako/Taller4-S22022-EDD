#include "Funciones.h"

void PressEnterToContinue()
{
    cout << "Presiona Enter para continuar... " << flush;
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n' ); 
}giut

void Menu()
{
    int opcion;

    do{
        system("clear");
        cout << "\e[1mSeleccione una opción:\e[0m" << endl;
        cout << "1.- " << endl;
        cout << "2.- " << endl;
        cout << "3.- " << endl;
        cout << "4.- " << endl;
        cout << "5.- " << endl;
        cout << "0.- Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        switch(opcion){
            case 0:
                cout << "\t\t\e[1mSee You Space Cowboy...\e[0m" << endl;
                PressEnterToContinue();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "Seleccione una opción válida." << endl;
                PressEnterToContinue();
                break;
        }
    }while(opcion != 0);
}

void archivoAVector(string nombreArchivo, Elector p[] , int &indice){
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    archivo.open(nombreArchivo, ios::in);

    if(archivo.is_open() == true) {

        while( getline(archivo, lineaObtenida, '\n')){
            //ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');

            if(indice > 0) {
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

vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;      //#include <vector>
    stringstream linea(lineaASeparar);  //#include <sstream>
    string parteDelString;

    while(getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}