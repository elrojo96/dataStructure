//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 5: Operaciones en Linked List

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "node.h"

template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		T deleteFirst();
		T deleteLast();
		T del(int pos);
		int deleteAll();
		T get(int pos);
		T set(T data, int pos);
		void print();
		bool change(int pos1, int pos2);

        //Funciones de Tarea
        LinkedList(const LinkedList<T> &Objeto);        //Copy Constructor
        void reverse();                                 //Funcion que invierte la lista
        void shift(int pos);                            //Funcion que cambia el nodo en la posicion ingresada al final de la fila
        void spin(int pos);
        void operator+=(T data);                        //Funcion que agrega un valor al valor del nodo solicitado
        void operator+=(const LinkedList<T> &Objeto);   //Funcion que le suma un nodo a otro nodo
        void operator=(const LinkedList<T> &Objeto);    //Funcion que iguala una lista a otra
        bool operator==(const LinkedList<T> &Objeto);   //Funcion que compara si dos listas son iguales

	private:
		node<T> *head;
		int length;
		void borra();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	length = 0;
}

template <typename T>
void LinkedList<T>::borra()
{
	node<T> *aux = head;
	while(head != NULL)
	{
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	borra();
}

template <typename T>
int LinkedList<T>::deleteAll()
{
	borra();
	int contAux = this->length;
	this->length  = 0;
	return contAux;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return (head == NULL);
}

template <typename T>
void LinkedList<T>::addFirst(T data)
{
	head = new node<T>(data, head);
	length++;
}

template <typename T>
bool LinkedList<T>::add(T data, int pos)
{
	if (pos < 0 || pos > this->length)
	{
		return false;
	}
	if (pos == 0)
	{
		this->addFirst(data);
	}
	else
	{
		if (pos == length)
		{
			this->addLast(data);
		}
		else
		{
			node<T> *aux = head;
			for (int i=1; i<pos; i++)
			{
				aux = aux->getNext();
			}
			aux->setNext(new node<T>(data, aux->getNext()));
			this->length++;
		}
	}
	return true;
}

template <typename T>
void LinkedList<T>::addLast(T data)
{
	if (this->isEmpty())
	{
		this->addFirst(data);
	}
	else
	{
		node<T> *aux = head;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		aux->setNext(new node<T>(data));
		length++;
	}
}

template <typename T>
T LinkedList<T>::deleteFirst()
{
	if (this->isEmpty())
	{
		return NULL;
	}
	node<T> *aux = head;
	head = head->getNext();
	T dataAux = aux->getData();
	delete aux;
	length--;
	return dataAux;
}

template <typename T>
T LinkedList<T>::deleteLast()
{
	if (this->length <= 1)
	{
		return this->deleteFirst();
	}
	else
	{
		node<T> *aux = head;
		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		T dataAux = aux->getNext()->getData();
		delete aux->getNext();
		aux->setNext(NULL);
		length--;
		return dataAux;
	}
}

template <typename T>
T LinkedList<T>::del(int pos)
{
	if (pos < 0 || pos >= this->length)
	{
		return NULL;
	}
	if (pos == 0)
	{
		return this->deleteFirst();
	}
	if (pos == length-1)
	{
		return this->deleteLast();
	}
	node<T> *aux = head;
	for (int i=1; i<pos; i++)
	{
		aux = aux->getNext();
	}
	node<T> *aux2 = aux->getNext();
	aux->setNext(aux->getNext()->getNext());
	T dataAux = aux2->getData();
	delete aux2;
	this->length--;
	return dataAux;
}

template <typename T>
T LinkedList<T>::get(int pos)
{
	if (pos < 0 || pos >= this->length)
	{
		return NULL;
	}
	node<T> *aux = head;
	for (int i=0; i<pos; i++)
	{
		aux = aux->getNext();
	}
	return aux->getData();
}

template <typename T>
T LinkedList<T>::set(T data, int pos)
{
	if (pos < 0 || pos >= this->length)
	{
		return NULL;
	}
	node<T> *aux = head;
	for (int i=0; i<pos; i++)
	{
		aux = aux->getNext();
	}
	T dataAux = aux->getData();
	aux->setData(data);
	return dataAux;
}

template <typename T>
void LinkedList<T>::print()
{
	node<T> *aux = head;
	while (aux != NULL)
	{
		cout << aux->getData()<<" ";
		aux = aux->getNext();
	}
	cout << endl;
}

template <typename T>
bool LinkedList<T>::change(int pos1, int pos2)
{
	if (pos1 < 0 || pos1 >= this->length || pos2 < 0 || pos2 >= this->length)
	{
		return false;
	}
	if (pos1 == pos2)
	{
		return true;
	}

	int men = (pos1 < pos2)? pos1 : pos2;
	int may = (pos1 > pos2)? pos1 : pos2;

	node<T> *aux1 = head, *aux2;
	for (int i=0; i<men; i++)
	{
		aux1 = aux1->getNext();
	}

	aux2 = aux1;
	for (int i=men; i<may; i++)
	{
		aux2 = aux2->getNext();
	}
	T dataAux = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(dataAux);
	return true;
}

//Copy Constructor
template <typename T>
LinkedList<T> :: LinkedList(const LinkedList<T> &Objeto)
{
    node<T> *auxiliar1 = new node<T>(Objeto.head -> getData());
    node<T> *auxiliar2 = Objeto.head;

    this -> head = auxiliar1;

    while(auxiliar2 -> getNext() != NULL)
    {
        auxiliar2 = auxiliar2 -> getNext();
        node<T> *auxiliar3 = new node<T>(auxiliar2 -> getData());
        auxiliar1 -> setNext(auxiliar3);
        auxiliar1 = auxiliar3;
    }
    auxiliar1 -> setNext(NULL);
    length = Objeto.length;
    this -> length = Objeto.length;
}

//Funcion que invierte la lista
template <typename T>
void LinkedList<T> :: reverse()
{
    if(this -> length > 1)
    {
        for(int i = 1; i < length; i++)
        {
            this -> addFirst( this -> del(i));
        }
    }
}

//Funcion que cambia el nodo en la posicion ingresada al final de la fila
template <typename T>
void LinkedList<T> :: shift(int pos)
{
    node<T> *auxiliar1;
    node<T> *auxiliar2;

    auxiliar1 = head;

    if(pos > 0)
    {
        for(int i = 0; i < pos - 1; i++)
        {
            auxiliar1 = auxiliar1 -> getNext();
        }

        auxiliar2 = auxiliar1 -> getNext();
        auxiliar1 -> setNext(NULL);
        auxiliar1 = auxiliar2;

        while(auxiliar1 -> getNext() != NULL)
        {
            auxiliar1 = auxiliar1 -> getNext();
        }

        auxiliar1 -> setNext(head);
        head = auxiliar2;
    }
    else if(pos < 0)
    {
        for(int i = 0; i < length - 1 + pos; i++)
        {
            auxiliar1 = auxiliar1 -> getNext();
        }

        auxiliar2 = auxiliar1 -> getNext();
        auxiliar1 -> setNext(NULL);
        auxiliar1 = auxiliar2;

        for(int i = pos + length; i < length - 1; i++)
        {
            auxiliar1 = auxiliar1 -> getNext();
        }
        auxiliar1 -> setNext(head);
        head = auxiliar2;
    }
}

template <typename T>
void LinkedList<T> :: spin(int pos)
{
    LinkedList<T> auxiliar;
    int iAuxiliar = length;

    for(int y = 0; y < iAuxiliar / pos; y++)
    {
        for(int x = pos - 1; x >= 0; x--)
        {
            auxiliar.addLast(this -> del(x));
        }
    }

    if(length > 1)
    {
        iAuxiliar = length;
        for(int i = iAuxiliar - 1; i >= 0; i--)
        {
            auxiliar.addLast(this -> del(i));
        }
    }

    iAuxiliar = auxiliar.length;

    for(int i = 0; i < iAuxiliar; i++)
    {
        this -> addLast(auxiliar.deleteFirst());
    }
}

//Funcion que agrega un valor al valor del nodo solicitado
template <typename T>
void LinkedList<T> :: operator+=(T data)
{
    node<T> *auxiliar = head;

    if(this -> isEmpty())
    {
        this -> addFirst(data);
    }
    else
    {
        while(auxiliar -> getNext() != NULL)
        {
            auxiliar = auxiliar -> getNext();
        }
        node<T> *nuevoNodo = new node<T>(data);
        auxiliar -> setNext(nuevoNodo);
        length++;
    }
}

//Funcion que le suma un nodo a otro nodo
template <typename T>
void LinkedList<T> :: operator+=(const LinkedList<T> &Objeto)
{
    node<T> *auxiliar1 = new node<T>(Objeto.head -> getData());
    node<T> *auxiliar2 = Objeto.head;

    this -> head = auxiliar1;

    while(auxiliar2 -> getNext() != NULL)
    {
        auxiliar2 = auxiliar2 -> getNext();
        node<T> *auxiliar3 = new node<T>(auxiliar2 -> getData());
        auxiliar1 -> setNext(auxiliar3);
        auxiliar1 = auxiliar3;
    }
    auxiliar1 -> setNext(NULL);
    length = Objeto.length;
    this -> length = Objeto.length;
}

//Funcion que iguala una lista a otra
template <typename T>
void LinkedList<T> :: operator=(const LinkedList<T> &Objeto)
{
    this -> deleteAll();

    if(Objeto.head != NULL)
    {
        node<T> *auxiliar = new node<T>(Objeto.head -> getData());
        this -> head = auxiliar;
        node<T> *auxiliar2 = Objeto.head;

        while(auxiliar2 -> getNext() != NULL)
        {
            auxiliar2 = auxiliar2 -> getNext();
            node<T> *auxiliar3 = new node<T>(auxiliar2 -> getData());
            auxiliar -> setNext(auxiliar3);
            auxiliar = auxiliar3;
        }

        auxiliar -> setNext(NULL);
        length = Objeto.length;
    }
}

//Funcion que compara si dos listas son iguales
template <typename T>
bool LinkedList<T> :: operator==(const LinkedList<T> &Objeto)
{
    if(this -> length != Objeto.length)
    {
        return false;
    }

    node<T> *auxiliar1 = this -> head;
    node<T> *auxiliar2 = Objeto.head;

    while(auxiliar1 != NULL)
    {
        if(auxiliar1 -> getData() == auxiliar2 -> getData())
        {
            auxiliar1 = auxiliar1 -> getNext();
            auxiliar2 = auxiliar2 -> getNext();
        }
        else
        {
            return false;
        }
    }
    return false;
}

#endif // LINKEDLIST_H_INCLUDED
