//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 7 y 8: Operaciones en BST

#ifndef NODET_H_INCLUDED
#define NODET_H_INCLUDED

class nodeT
{
	public:
		nodeT();
		nodeT(int d);
		int getData();
		void setData(int d);
		nodeT* getLeft();
		void setLeft(nodeT *l);
		nodeT* getRight();
		void setRight(nodeT *r);

	private:
		int data;
		nodeT *left;
		nodeT *right;
};

nodeT::nodeT()
{
	data = 0;
	right = left = NULL;
}


nodeT::nodeT(int d)
{
	data = d;
	right = left = NULL;
}

int nodeT::getData()
{
	return data;
}

void nodeT::setData(int d)
{
	data = d;
}

nodeT* nodeT::getLeft()
{
	return left;
}

void nodeT::setLeft(nodeT* l)
{
	left = l;
}

nodeT* nodeT::getRight()
{
	return right;
}

void nodeT::setRight(nodeT* r)
{
	right = r;
}

#endif // NODET_H_INCLUDED
