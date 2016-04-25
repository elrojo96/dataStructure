//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 7 y 8: Operaciones en BST

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "nodeT.h"
#include <queue>
#include <stack>
#include <stdlib.h>
#include <time.h>

class BST
{
	public:
		BST();
		~BST();
		void add(int d);
		bool search(int d);
		void print(int idx);
		void del(int d);
		int count();

		//Funciones de Tarea
        BST(BST const &Objeto);                         //Copy Constructor
        int height();                                   //Funcion que devuelve la altura de un arbol
        void ancestors(int d);                          //Funcion que imprime los ancestros de un nodo
        int wherelevelIam(int d);                       //Funcion que regresa en que nivel esta un nodo
        bool operator==(BST arbol);                     //Funcion que compara si dos arboles son iguales
        void nearst_relative(int iDato1, int iDato2);   //Funcion que muestra cual es el nodo mas cercano
        int max_width();                                //Funcion que imprime la maxima anchura de un arbol
        bool isBalanced();                              //Funcion que regresa si un arbol esta balanceado

	private:
		nodeT* root;
		void preorden(nodeT *r);
		void inorden(nodeT *r);
		void postorden(nodeT *r);
		void delAll(nodeT *r);
		int howManyChildren(nodeT *r);
		int pred(nodeT *r);
		int suc(nodeT *r);
		void printLeaves(nodeT *r);
		int countR(nodeT *r);

		//Funciones de Tarea
		void printLevels(nodeT *r);     //Funcion que imprime los niveles de un arbol
		int auxHeight(nodeT *r);        //Funcion auxiliar a la altura
		stack<int> auxiliar(nodeT *r);  //Pila auxiliar
		int balancear(nodeT *r);        //Funcion que balancea un arbol
};


BST::BST()
{
	root = NULL;
}

void BST::delAll(nodeT *r)
{
	if (r != NULL)
	{
		delAll(r->getLeft());
		delAll(r->getRight());
		delete r;
	}
}

BST::~BST()
{
	delAll(root);
}

void BST::preorden(nodeT *r)
{
	if (r != NULL)
	{
		cout << r->getData() << " ";
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BST::inorden(nodeT *r)
{
	if (r != NULL)
	{
		inorden(r->getLeft());
		cout << r->getData() << " ";
		inorden(r->getRight());
	}
}

void BST::postorden(nodeT *r)
{
	if (r != NULL)
	{
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " ";
	}
}

void BST::add(int d)
{
	if (root == NULL)
	{
		root = new nodeT(d);
	}
	else
	{
		nodeT *aux = root;
		nodeT *father = NULL;
		while (aux != NULL)
		{
			if (aux->getData() == d)
			{
				return;
			}
			father = aux;
			aux = (aux->getData()>d ? aux->getLeft() : aux->getRight());
		}
		(father->getData() > d) ? father->setLeft(new nodeT(d)) : father->setRight(new nodeT(d));
	}
}

bool BST::search(int d)
{
	nodeT *aux = root;
	while (aux != NULL)
	{
		if (aux->getData() == d)
		{
			return true;
		}
		aux = (aux->getData()>d ? aux->getLeft() : aux->getRight());
	}
	return false;
}
int BST::howManyChildren(nodeT *r)
{
	return (r->getLeft() == NULL && r->getRight() == NULL)? 0 :
		(r->getLeft() == NULL || r->getRight() == NULL? 1 : 2);

/*
	int iCont = 0;

	if (r->getLeft() != NULL)
	{
		iCont++;
	}
	if (r->getRight() != NULL)
	{
		iCont++;
	}
	return iCont;*/
}

int BST::pred(nodeT *r)
{
	nodeT *aux = r->getLeft();
	while (aux->getRight() != NULL)
	{
		aux = aux->getRight();
	}
	return aux->getData();
}

int BST::suc(nodeT *r)
{
	nodeT *aux = r->getRight();
	while (aux->getLeft() != NULL)
	{
		aux = aux->getLeft();
	}
	return aux->getData();
}


void BST::del(int d)
{
	nodeT *father = NULL;
	nodeT *aux = root;
	while (aux != NULL && aux->getData() != d)
	{
		father = aux;
		aux = (aux->getData() > d ? aux->getLeft() : aux->getRight());
	}
	if (aux == NULL)
	{
		return;
	}
	switch (howManyChildren(aux))
	{
		case 0:	if (father == NULL)
				{
					root = NULL;
				}
				else
				{
					father->getData() > d ? father->setLeft(NULL) :
											father->setRight(NULL);
				}
				delete aux;
				break;
		case 1:
				if (father == NULL)
				{
					root = (aux->getLeft() != NULL)? aux->getLeft() :
													 aux->getRight();
				}
				else
				{
					if (father->getData() > d)
					{
						if (aux->getLeft() != NULL)
						{
							father->setLeft(aux->getLeft());
						}
						else
						{
							father->setLeft(aux->getRight());
						}
					}
					else
					{
						if (aux->getLeft() != NULL)
						{
							father->setRight(aux->getLeft());
						}
						else
						{
							father->setRight(aux->getRight());
						}
					}
				}
				delete aux;
				break;
		case 2:
				int nuevo = suc(aux);
				del(nuevo);
				aux->setData(nuevo);
				break;
	}

}

void BST::printLeaves(nodeT *r)
{
	if (r != NULL)
	{
		if (howManyChildren(r)==0)
		{
			cout << r->getData() << " ";
		}
		else
		{
			printLeaves(r->getLeft());
			printLeaves(r->getRight());
		}
	}

}
void BST::print(int idx)
{
	switch (idx)
	{
		case 1: preorden(root);
				break;
		case 2: inorden(root);
				break;
		case 3: postorden(root);
				break;
		case 4: printLeaves(root);
				break;
        case 5: printLeaves(root);
                break;
	}
	cout << endl;

}

int BST::countR(nodeT *r)
{
	if (r == NULL)
	{
		return 0;
	}
	return 1 + countR(r->getLeft()) + countR(r->getRight());
}

int BST::count()
{
	return countR(root);
}

BST::BST(BST const &Objeto)
{
    root = Objeto.root;
}

void BST::printLevels(nodeT *r)
{
    nodeT *auxiliar;
    queue<nodeT> miFila;
    miFila.push(*r);

    while(!miFila.empty())
    {
        auxiliar = &miFila.front();
        miFila.pop();
        cout << auxiliar -> getData() << " ";

        if(auxiliar -> getLeft() != NULL)
        {
            miFila.push(*auxiliar -> getLeft());
        }
        if(auxiliar -> getRight() != NULL)
        {
            miFila.push(*auxiliar -> getRight());
        }
    }
    cout << endl;
}

int BST :: auxHeight(nodeT *r)
{
    if(r != NULL)
    {
        int iAlturaIzquierda;
        int iAlturaDerecha;

        iAlturaIzquierda = auxHeight(r -> getLeft());
        iAlturaDerecha = auxHeight(r -> getRight());

        if(iAlturaIzquierda > iAlturaDerecha)
        {
            return iAlturaIzquierda + 1;
        }
        else
        {
            return iAlturaDerecha + 1;
        }
    }
    return 0;
}

int BST :: height()
{
    return auxHeight(root);
}

void BST :: ancestors(int d)
{
    stack<nodeT> miPila;
    nodeT *auxiliar = root;

    miPila.push(*auxiliar);

    while(auxiliar != NULL && auxiliar -> getData() != d)
    {
        if(d > auxiliar -> getData())
        {
            auxiliar = auxiliar -> getRight();
        }
        else
        {
            auxiliar = auxiliar -> getLeft();
        }

        miPila.push(*auxiliar);
    }

    miPila.pop();

    while(!miPila.empty())
    {
        cout << (&miPila.top()) -> getData() << ", ";
        miPila.pop();
    }

    cout << endl;
}

int BST :: wherelevelIam(int d)
{
    int iNivel = 0;
    nodeT *auxiliar = root;

    while(auxiliar != NULL && auxiliar -> getData() != d)
    {
        iNivel++;

        if(d > auxiliar -> getData())
        {
            auxiliar = auxiliar -> getRight();
        }
        else
        {
            auxiliar = auxiliar -> getLeft();
        }
    }

    if(auxiliar == NULL)
    {
        iNivel = -1;
    }

    return iNivel;
}

stack<int> BST :: auxiliar(nodeT *r)
{
    stack<int> miPila;

    if(r != NULL)
    {
        miPila.push(r -> getData());
        auxiliar(r -> getLeft());
        auxiliar(r -> getRight());
    }

    return miPila;
}

bool BST :: operator==(BST arbol)
{
    nodeT *auxiliar1 = root;
    nodeT *auxiliar2 = arbol.root;

    stack<int> miPila1;
    stack<int> miPila2;

    miPila1 = auxiliar(auxiliar1);
    miPila2 = auxiliar(auxiliar2);

    while(!miPila1.empty() || !miPila2.empty())
    {
        if(miPila1.top() != miPila2.top())
        {
            return false;
        }
        else
        {
            miPila1.pop();
            miPila2.pop();
        }
    }

    return true;
}

void BST :: nearst_relative(int iDato1, int iDato2)
{
    nodeT *auxiliar1;
    nodeT *auxiliar2;

    queue<int> miFila1;
    queue<int> miFila2;

    while(auxiliar1 != NULL && auxiliar1 -> getData() != iDato1)
    {
        if(iDato1 > auxiliar1 -> getData())
        {
            auxiliar1 = auxiliar1 -> getRight();
        }
        else
        {
            auxiliar1 = auxiliar1 -> getLeft();
        }

        miFila1.push(auxiliar1 -> getData());
    }

    while(auxiliar2 != NULL && auxiliar2 -> getData() != iDato2)
    {
        if(iDato2 > auxiliar2 -> getData())
        {
            auxiliar2 = auxiliar2 -> getRight();
        }
        else
        {
            auxiliar2 = auxiliar2 -> getLeft();
        }

        miFila2.push(auxiliar2 -> getData());
    }

    int iContenedor1;
    int iContenedor2;

    while(!miFila1.empty() || !miFila2.empty())
    {
        iContenedor1 = miFila1.front();
        iContenedor2 = miFila2.front();

        if(iContenedor1 == iContenedor2)
        {
            miFila1.pop();
            miFila2.pop();
        }
        else
        {
            cout << "El ancestro mas cercano es: " << iContenedor1 << endl;
        }
    }
}

int BST :: max_width()
{
    if(root != NULL)
    {
        int iSiguiente = 1;
        int iAtras = 0;
        int iMaximo = -50;

        queue<nodeT*> miFila;

        miFila.push(root);

        nodeT *auxiliar;

        while(!miFila.empty())
        {
            for(int i = 0; i < iAtras; i++)
            {
                auxiliar = miFila.front();
                if(auxiliar -> getRight() != NULL)
                {
                    miFila.push(auxiliar -> getRight());
                    iSiguiente++;
                }
                if(auxiliar -> getLeft() != NULL)
                {
                    miFila.push(auxiliar -> getLeft());
                    iSiguiente++;
                }
                miFila.pop();
            }
            if(iSiguiente > iMaximo)
            {
                iMaximo = iSiguiente;
            }

            iAtras = iSiguiente;
            iSiguiente = 0;
        }
        return iMaximo;
    }
    return -1;
}

bool BST :: isBalanced()
{
    if(height() >= 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif // BST_H_INCLUDED
