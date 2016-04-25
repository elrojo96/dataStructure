//Luis Alfonso Rojo Sanchez
//A01113049
//Estructura de Datos
//Tarea 6: Evaluación de Expresiones Postfijo

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

//Referencia: http://www.cplusplus.com/forum/general/118877/
struct comparacion
{
    bool operator()(const int& izquierda, const int& derecha)
    {
        return izquierda > derecha;
    }
};

//Referencia del Profesor para transformar un string a int
int miatoi(string s)
{
	int acum = 0;

	for(int iA = 0; iA < s.length(); iA++)
	{
		acum = (acum * 10) + s[iA] - '0';
	}
	return acum;
}

//Funcion que trabaja los datos con una Pila
int iPila(string linea)
{
    stack<int> sPila;

    stringstream sLineaSS;

    sLineaSS << linea;

    string sLineaTemporal;

    sLineaSS >> sLineaTemporal;

    do{
        if(sLineaTemporal == "+")//Suma
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = sPila.top();
            sPila.pop();
            iNumeroY = sPila.top();
            sPila.pop();

            iNumeroResultante = iNumeroY + iNumeroX;

            sPila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "-")//Resta
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = sPila.top();
            sPila.pop();
            iNumeroY = sPila.top();
            sPila.pop();

            iNumeroResultante = iNumeroY - iNumeroX;

            sPila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "*")//Multiplicacion
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = sPila.top();
            sPila.pop();
            iNumeroY = sPila.top();
            sPila.pop();

            iNumeroResultante = iNumeroY * iNumeroX;

            sPila.push(iNumeroResultante);
        }
        else
        {
            int iNumeroTemporal = miatoi(sLineaTemporal);
            sPila.push(iNumeroTemporal);
        }

    }while(sLineaSS >> sLineaTemporal);

    return sPila.top();
}

//Funcion que trabaja los datos con una Fila
int iFila(string linea)
{
    queue<int> qFila;

    stringstream sLineaSS;

    sLineaSS << linea;

    string sLineaTemporal;

    sLineaSS >> sLineaTemporal;

    do{
        if(sLineaTemporal == "+")//Suma
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = qFila.front();
            qFila.pop();
            iNumeroY = qFila.front();
            qFila.pop();

            iNumeroResultante = iNumeroY + iNumeroX;

            qFila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "-")//Resta
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = qFila.front();
            qFila.pop();
            iNumeroY = qFila.front();
            qFila.pop();

            iNumeroResultante = iNumeroY - iNumeroX;

            qFila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "*")//Multiplicacion
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = qFila.front();
            qFila.pop();
            iNumeroY = qFila.front();
            qFila.pop();

            iNumeroResultante = iNumeroY * iNumeroX;

            qFila.push(iNumeroResultante);
        }
        else
        {
            int iNumeroTemporal = miatoi(sLineaTemporal);
            qFila.push(iNumeroTemporal);
        }
    }while(sLineaSS >> sLineaTemporal);

    return qFila.front();
}

//Funcion que trabaja los datos con una Fila Priorizada
int iFilaPriorizada(string linea)
{
    priority_queue<int, vector<int>, comparacion> pFila;

    stringstream sLineaSS;

    sLineaSS << linea;

    string sLineaTemporal;

    sLineaSS >> sLineaTemporal;

    do{
        if(sLineaTemporal == "+")//Suma
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = pFila.top();
            pFila.pop();
            iNumeroY = pFila.top();
            pFila.pop();

            iNumeroResultante = iNumeroY + iNumeroX;

            pFila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "-")//Resta
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = pFila.top();
            pFila.pop();
            iNumeroY = pFila.top();
            pFila.pop();

            iNumeroResultante = iNumeroY - iNumeroX;

            pFila.push(iNumeroResultante);
        }
        else if(sLineaTemporal == "*")//Multiplicacion
        {
            int iNumeroX;
            int iNumeroY;
            int iNumeroResultante;

            iNumeroX = pFila.top();
            pFila.pop();
            iNumeroY = pFila.top();
            pFila.pop();

            iNumeroResultante = iNumeroY * iNumeroX;

            pFila.push(iNumeroResultante);
        }
        else
        {
            int iNumeroTemporal = miatoi(sLineaTemporal);
            pFila.push(iNumeroTemporal);
        }
    }while(sLineaSS >> sLineaTemporal);

    return pFila.top();
}

int main()
{
    //Variable que es la linea a trabajar
    string sLinea;

    //Se obtiene el contenido a trabajar
    getline(cin, sLinea);

    //Mientras no se presione gato se puede trabajar
    while(sLinea != "#")
    {
        cout << iPila(sLinea) << " ";
        cout << iFila(sLinea) << " ";
        cout << iFilaPriorizada(sLinea);

        cout << endl;

        getline(cin, sLinea);
    }

    return 0;
}
