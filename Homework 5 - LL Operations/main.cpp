//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 5: Operaciones en Linked List

#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<int> miLista;

    miLista.addFirst(5);
    miLista.addFirst(4);
    miLista.addFirst(3);
    miLista.addFirst(2);
    miLista.addFirst(1);

    miLista.print();

    miLista.reverse();

    miLista.print();
}
