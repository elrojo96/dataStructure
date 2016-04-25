//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 9: Priority Queue con Heap

#ifndef PRIORITY_H_INCLUDED
#define PRIORITY_H_INCLUDED

class Priority
{
public:
    Priority();                         //Constructor por default                               LISTO
    Priority(bool prioridad);           //Constructor por parametros                            LISTO
    void push(int iDato);               //Agrega un elemento al arreglo                         LISTO
    void pop();                         //Saca el mayor elemento de mayor prioridad del arreglo LISTO
    int front();                        //Te devuelve el elemento de mayor prioridad            LISTO
    int size();                         //Devuelve el tamaño del arreglo                        LISTO
    bool empty();                       //Checa si el arreglo esta vacio                        LISTO

    //Funciones para probar el programa
    void print();                        //Imprime el arreglo                                   LISTO
    void ordenaArriba(int iIndice);      //Ordena los datos de mayor a menor                    HACER
    void ordenaAbajo(int iIndice);       //Ordena los datos de menor a mayor                    HACER
private:
    int iArreglo[100];                   //Arreglo de 100 elementos
    int iCantidad;                       //Cantidad de elementos en el arreglo
    bool bPrioridad;                     //Variable para ordenar el HEAP de manera descendente
};

Priority :: Priority()
{
    for(int i = 0; i < 100; i++)
    {
        iArreglo[i] = 0;
    }
    iCantidad = 0;
    bPrioridad = true;
}

Priority :: Priority(bool prioridad)
{
    bPrioridad = prioridad;
}

void Priority :: push(int iDato)
{
    if(iCantidad < 100)
    {
        iArreglo[iCantidad] = iDato;
        ordenaArriba(iCantidad);
        iCantidad++;
    }
}

void Priority :: pop()
{
    //iArreglo[0] es el elemento que sale
    iArreglo[0] = iArreglo[iCantidad - 1];
    iCantidad--;
    iArreglo[iCantidad] = 0;
    ordenaAbajo(0);
}

int Priority :: front()
{
    return iArreglo[0];
}

int Priority :: size()
{
    return iCantidad;
}

bool Priority :: empty()
{
    if(iCantidad == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Priority :: print()
{
    for(int i = 0; i < iCantidad; i++)
    {
        if(i != iCantidad - 1)
        {
            cout << iArreglo[i] << " ";
        }
        else
        {
            cout << iArreglo[i] << endl;
        }
    }
}

void Priority :: ordenaArriba(int iIndice)
{
    int iAuxiliar;
    if(bPrioridad)
    {
        while(iIndice > 1 && iArreglo[iIndice / 2] < iArreglo[iIndice])
        {
            iAuxiliar = iArreglo[iIndice];
            iArreglo[iIndice] = iArreglo[iIndice / 2];
            iArreglo[iIndice / 2] = iAuxiliar;
            iIndice = iIndice / 2;
        }
    }
    else
    {
        while(iIndice > 1 && iArreglo[iIndice / 2] > iArreglo[iIndice])
        {
            iAuxiliar = iArreglo[iIndice];
            iArreglo[iIndice] = iArreglo[iIndice / 2];
            iArreglo[iIndice / 2] = iAuxiliar;
            iIndice = iIndice / 2;
        }
    }

}

void Priority :: ordenaAbajo(int iIndice)
{
    int iAuxiliar = iIndice;

    int iHijo = iIndice * 2;

    int iHijoMayor;

    if(bPrioridad)
    {
        while((iHijo <= iCantidad && iArreglo[iHijo] > iArreglo[iIndice]) || (iHijo <= iCantidad && iArreglo[iHijo + 1] > iArreglo[iIndice]))
        {
            if(iArreglo[iHijo] > iArreglo[iHijo + 1])
            {
                iHijoMayor = iArreglo[iHijo];

                if(iArreglo[iHijoMayor] > iArreglo[iAuxiliar])
                {
                    int iTemporal = iArreglo[iAuxiliar];

                    iArreglo[iAuxiliar] = iArreglo[iHijoMayor];

                    iArreglo[iHijoMayor] = iTemporal;

                    iAuxiliar = iHijoMayor;
                    iHijo = iAuxiliar * 2;
                }
            }
            else if(iArreglo[iHijo + 1] > iArreglo[iHijo])
            {
                iHijoMayor = iArreglo[iHijo + 1];

                if(iArreglo[iHijoMayor] > iArreglo[iAuxiliar])
                {
                    int iTemporal = iArreglo[iAuxiliar];

                    iArreglo[iAuxiliar] = iArreglo[iHijoMayor];

                    iArreglo[iHijoMayor] = iTemporal;

                    iAuxiliar = iHijoMayor;
                    iHijo = iAuxiliar * 2;
                }
            }
        }
    }
    else
    {
        while((iHijo <= iCantidad && iArreglo[iHijo] < iArreglo[iIndice]) || (iHijo <= iCantidad && iArreglo[iHijo + 1] < iArreglo[iIndice]))
        {
            if(iArreglo[iHijo] < iArreglo[iHijo + 1])
            {
                iHijoMayor = iArreglo[iHijo];

                if(iArreglo[iHijoMayor] < iArreglo[iAuxiliar])
                {
                    int iTemporal = iArreglo[iAuxiliar];

                    iArreglo[iAuxiliar] = iArreglo[iHijoMayor];

                    iArreglo[iHijoMayor] = iTemporal;

                    iAuxiliar = iHijoMayor;
                    iHijo = iAuxiliar * 2;
                }
            }
            else if(iArreglo[iHijo + 1] < iArreglo[iHijo])
            {
                iHijoMayor = iArreglo[iHijo + 1];

                if(iArreglo[iHijoMayor] < iArreglo[iAuxiliar])
                {
                    int iTemporal = iArreglo[iAuxiliar];

                    iArreglo[iAuxiliar] = iArreglo[iHijoMayor];

                    iArreglo[iHijoMayor] = iTemporal;

                    iAuxiliar = iHijoMayor;
                    iHijo = iAuxiliar * 2;
                }
            }
        }
    }
}

#endif // PRIORITY_H_INCLUDED
