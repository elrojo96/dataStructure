//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 3: ACM-ICPC Score

#include <iostream>

using namespace std;

struct sEquipo
{
    string sNombre;
    string sNombreProblemas[10];
    int iProblemasResueltos;
    int iTiempo;
    int iTiempoExtra[10];

};

sEquipo sEquipos[20];

void burbuja(int iCantidadEquipos)
{
    bool interruptor = true;

    for (int pasada = 0; pasada<iCantidadEquipos-1 && interruptor; pasada++)
    {
        interruptor = false;   // no se han hecho intercambios

        for (int j = 0; j < iCantidadEquipos - 1 - pasada; j++)
        {
            if (sEquipos[j+1].iProblemasResueltos > sEquipos[j].iProblemasResueltos)
            {
                sEquipo tmp;
                tmp = sEquipos[j];
                sEquipos[j] = sEquipos[j+1];
                sEquipos[j+1] = tmp;
                interruptor = true;
            }
            else if(sEquipos[j+1].iProblemasResueltos == sEquipos[j].iProblemasResueltos && sEquipos[j+1].iTiempo < sEquipos[j].iTiempo)
            {
                sEquipo tmp;
                tmp = sEquipos[j];
                sEquipos[j] = sEquipos[j+1];
                sEquipos[j+1] = tmp;
                interruptor = true;
            }
        }
    }
}

int main()
{
    for(int i = 0; i <= 19; i++)
    {
        sEquipos[i].sNombre = "";
        sEquipos[i].iProblemasResueltos = 0;
        sEquipos[i].iTiempo = 0;

        for(int j = 0; j < 10; j++)
        {
            sEquipos[i].iTiempoExtra[j] = 0;
            sEquipos[i].sNombreProblemas[j] = "";
        }
    }

    //Delcaracion de variables
    int iNumeroEquipos;
    int iCantidadProblemas;
    int iSolucionesEnviadas;

    //Se ingresa el numero de equipos
    cin >> iNumeroEquipos;

    //Se valida el numero de equipos
    while(iNumeroEquipos < 1 || iNumeroEquipos > 20)
    {
        cin >> iNumeroEquipos;
    }

    //Se ingresa la cantidad de problemas
    cin >> iCantidadProblemas;

    //Se valida la cantidad de problemas
    while(iCantidadProblemas < 1 || iCantidadProblemas > 10)
    {
        cin >> iCantidadProblemas;
    }

    //Se ingresan los nombres de los equipos
    for(int i = 0; i < iNumeroEquipos; i++)
    {
        cin >> sEquipos[i].sNombre;
    }

    //Se ingresan la cantidad de soluciones enviadas
    cin >> iSolucionesEnviadas;

    //Se valida la cantidad de soluciones enviadas
    while(iSolucionesEnviadas < 1 || iSolucionesEnviadas > 1000)
    {
        cin >> iSolucionesEnviadas;
    }

    for(int i = 0; i < iSolucionesEnviadas; i++)
    {
        string sNombreEquipo;

        cin >> sNombreEquipo;

        string sNombreProblema;

        cin>> sNombreProblema;

        int iTiempo;

        cin >> iTiempo;

        string sRespuesta;

        cin >> sRespuesta;

        for(int j = 0; j < iNumeroEquipos; j++)
        {
            if(sEquipos[j].sNombre == sNombreEquipo)
            {
                if(sRespuesta == "W")
                {
                    for(int k = 0; k < iCantidadProblemas; k++)
                    {
                        if(sEquipos[j].sNombreProblemas[k] == sNombreProblema || sEquipos[j].sNombreProblemas[k] == "")
                        {
                            sEquipos[j].iTiempoExtra[k] += 20;
                            sEquipos[j].sNombreProblemas[k] = sNombreProblema;
                            k = iCantidadProblemas;
                        }
                    }
                }
                else
                {
                    for(int l = 0; l < iCantidadProblemas; l++)
                    {
                        if(sEquipos[j].sNombreProblemas[l] == sNombreProblema || sEquipos[j].sNombreProblemas[l] == "")
                        {
                            sEquipos[j].iTiempo += sEquipos[j].iTiempoExtra[l];
                            l = iCantidadProblemas;
                        }
                    }

                    sEquipos[j].iTiempo += iTiempo;
                    sEquipos[j].iProblemasResueltos += 1;
                    j = iNumeroEquipos;
                }
            }
        }
    }

    burbuja(iNumeroEquipos);

    for(int i = 0; i < iNumeroEquipos; i++)
    {
        if(sEquipos[i].iTiempo == 0)
        {
            cout << i + 1 << " - " << sEquipos[i].sNombre << " " << sEquipos[i].iProblemasResueltos << " " << "-" << endl;
        }
        else
        {
            cout << i + 1 << " - " << sEquipos[i].sNombre << " " << sEquipos[i].iProblemasResueltos << " " << sEquipos[i].iTiempo << endl;
        }
    }

    return 0;
}
