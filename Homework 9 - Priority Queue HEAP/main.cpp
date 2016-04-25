//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 9: Priority Queue con Heap

#include <iostream>

using namespace std;

#include "Priority.h"

int main()
{
    Priority miFilaPriorizada;

    cout << miFilaPriorizada.front() << endl;

    cout << miFilaPriorizada.front() << endl;

    cout << "La fila esta vacia: " << miFilaPriorizada.empty() << endl;

    miFilaPriorizada.push(50);
    miFilaPriorizada.push(10);
    miFilaPriorizada.push(30);
    miFilaPriorizada.push(20);
    miFilaPriorizada.push(40);

    miFilaPriorizada.print();

    return 0;
}
