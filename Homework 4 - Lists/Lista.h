//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 4: Lista Encadenada

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <class T>
class Lista
{
public:
    Lista();                                                    //Constructor vacío
    Lista(const Lista<T> &listaOriginal);                       //Copy Constructor
    int getCant();                                              //Funcion que regresa la cantidad de informacion de la lista
    T getDato(int indice);                                      //Funcion que regresa el dato del indice ingresado
    bool add(T dato);                                           //Funcion que agrega un elemento a l lista
    int search(T dato);                                         //Funcion que busca un elemento en la lista
    void sort(bool ordenar);                                    //Funcion que ordena la lista
    void operator=(Lista<T> &lista);                             //Funcion que realiza la asignacion de una lista a otra
    bool operator==(Lista<T> lista2);   //Funcion que realiza la comparacion entre dos listas
    void print();                                               //Funcion que imprime la lista de datos
private:
    T arrDatos[10];                                             //Arreglo generico de 10 elementos
    int iCant;                                                  //Cantidad de datos almacenados en el arreglo
};

//Constructor vacio
template <typename T>
Lista<T> :: Lista()
{
    for(int i = 0; i < 10; i++)
    {
        arrDatos[i] = 0;
    }
    iCant = 0;
}

//Copy Constructor
template <typename T>
Lista<T> :: Lista(const Lista<T> &listaOriginal)
{
    this -> iCant = listaOriginal.iCant;

    for(int i = 0; i < listaOriginal.iCant; i++)
    {
        this -> arrDatos[i] = listaOriginal.arrDatos[i];
    }
}

//Funcion que regresa la cantidad de informacion de la lista
template <typename T>
int Lista<T> :: getCant()
{
    return iCant;
}

//Funcion que regresa el dato del indice ingresado
template <typename T>
T Lista<T> :: getDato(int indice)
{
    return arrDatos[indice];
}

//Funcion que agrega un elemento a l lista
template <typename T>
bool Lista<T> :: add(T dato)
{
    if(iCant == 10)
    {
        return false;
    }
    else
    {
            arrDatos[iCant] = dato;
            iCant++;
            return true;
    }
}

//Funcion que busca un elemento en la lista
template <typename T>
int Lista<T> :: search(T dato)
{
    for(int i = 0; i < iCant; i++)
    {
        if(arrDatos[i] == dato)
        {
            return i;
        }
        else if(i == 10 && arrDatos[i] != dato)
        {
            return -1;
        }
    }
}

//Funcion que ordena la lista
template <typename T>
void Lista<T> :: sort(bool ordenar)
{
    if(ordenar == true)//Ordenar ascendentemente
    {
        bool interruptor = true;

        for(int pasada = 0; pasada < iCant - 1 && interruptor; pasada++)
        {
            interruptor = false;
            for(int j = 0; j < iCant - 1 - pasada; j++)
            {
                if(arrDatos[j + 1] < arrDatos[j])
                {
                    T tmp = arrDatos[j];
                    arrDatos[j] = arrDatos[j + 1];
                    arrDatos[j + 1] = tmp;

                    interruptor = true;
                }
            }
        }
    }
    else if(ordenar == false)//Ordenar Descendentemente
    {
        bool interruptor = true;

        for(int pasada = 0; pasada < iCant - 1 && interruptor; pasada++)
        {
            interruptor = false;
            for(int j = 0; j < iCant - 1 - pasada; j++)
            {
                if(arrDatos[j + 1] > arrDatos[j])
                {
                    T tmp = arrDatos[j];
                    arrDatos[j] = arrDatos[j + 1];
                    arrDatos[j + 1] = tmp;

                    interruptor = true;
                }
            }
        }
    }
}

//Funcion que realiza la asignacion de una lista a otra
template <typename T>
void Lista<T> :: operator=(Lista<T> &lista)
{
    this -> iCant = lista.iCant;

    for(int i = 0; i < lista.iCant; i++)
    {
        this -> arrDatos[i] = lista.arrDatos[i];
    }
}

//Funcion que realiza la comparacion entre dos listas
template <class T>
bool Lista<T> :: operator==(Lista<T> lista2)
{
    if(this -> iCant != lista2.iCant)
    {
        //cout << "Primera condicion" << endl;
        return false;
    }

    for(int i = 0; i < this -> iCant; i++)
    {
        if(this -> arrDatos[i] != lista2.arrDatos[i])
        {
            //cout << "Segunda condicion" << endl;
            return false;
        }
    }

    //cout << "Ninguna condicion" << endl;
    return true;
}

//Funcion que imprime la lista de datos
template <typename T>
void Lista<T> :: print()
{
    for(int i = 0; i < this -> iCant; i++)
    {

        if(i != this -> iCant - 1)
        {
            cout << arrDatos[i] << " ";
        }
        else
        {
            cout << arrDatos[i] << endl;
        }
    }
}

#endif // LISTA_H_INCLUDED
