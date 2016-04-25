//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 4: Lista Encadenada

#include <iostream>
#include <map>

using namespace std;

#include "Lista.h"

int main()
{
    //Cambiar el main a "AppLista.cpp"
    Lista<int> *IUno;
    Lista<int> *IDos;
    Lista<int> *ITres;

    //IUno
    IUno = new Lista<int>;
    cout << "Agregar los datos a IUno: " << endl;
    int iDatoAgregar;
    do{
            cin >> iDatoAgregar;

            if(iDatoAgregar > 0)
            {
                IUno -> add(iDatoAgregar);
            }
    }while(iDatoAgregar > 0 && IUno -> getCant() < 10);

    //IDos
    IDos = new Lista<int>;
    cout << "Agregar los datos a IDos: " << endl;
    int iDatoAgregar2;
    do{
            cin >> iDatoAgregar2;

            if(iDatoAgregar2 > 0)
            {
                IDos -> add(iDatoAgregar2);
            }
    }while(iDatoAgregar2 > 0 && IDos -> getCant() < 10);

    //ITres
    ITres = new Lista<int>;
    (*ITres) = (*IDos);
    cout << "Se copiaron los valores de IDos a ITres" << endl;

    //Se evalua si ITres e IDos son iguales
    if((*ITres)==(*IDos))
    {
        cout << "ITres e IDos son iguales!" << endl;
    }
    else
    {
        cout << "ITres e IDos no son iguales!" << endl;
    }

    //Se evalua si IUno e IDos son iguales
    if((*IUno) == (*IDos))
    {
        cout << "IUno e IDos son iguales!" << endl;
    }
    else
    {
        cout << "IUno e IDos no son iguales!" << endl;
    }

    //Se despliegan los valores de IUno
    cout << "Los valores de IUno son: ";
    (*IUno).print();

    //Ordenar lUno ascendentemente
    (*IUno).sort(true);
    cout << "Los valores de IUno ascendentemente son: ";
    (*IUno).print();

    //Ordenar lUno descendentemente
    (*IUno).sort(false);
    cout << "Los valores de IUno descendentemente son: ";
    (*IUno).print();

    //Cantidad de datos que están de la lista IDos en IUno
    //Creacion de un mapa
    map<int, bool> miMapa;
    int iEncontrados = 0;
    for(int x = 0; x < (*IDos).getCant(); x++)
    {
        if(miMapa[(*IDos).getDato(x)] == NULL)
        {
            miMapa[(*IDos).getDato(x)] = false;
        }

        for(int y = 0; y < (*IUno).getCant(); y++)
        {
            if((*IDos).getDato(x) == (*IUno).getDato(y) && !(miMapa[(*IDos).getDato(x)]))
            {
                iEncontrados++;
                miMapa[(*IDos).getDato(x)] = true;
                y = (*IUno).getCant();
            }
        }
    }

    cout << "Cantidad de datos que estan de la lista IDos en IUno: " << iEncontrados << endl;

    //(*IDos).print();
    //(*ITres).print();

    return 0;
}
