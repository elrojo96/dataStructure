//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 1: Gira la Matriz

#include <iostream>

using namespace std;

int main()
{
    //Declaracion de variables
    int iGiros;
    int iResiduo;
    int iMatriz[4][4];
    int iMatrizTemporal[4][4];

    //Se ingresan los giros que quiere dar el usuario
    cin >> iGiros;

    //Se obtienen cuantos giros se haran finalmente
    if(iGiros > 0)
    {
        iResiduo = iGiros % 4;
    }
    else if(iGiros < 0)
    {
        do{
            iGiros += 4;
        }while( iGiros < 0);

        iResiduo = iGiros;
    }
    else if(iGiros == 0)
    {
        iResiduo = iGiros;
    }

    //Se ingresan los valores de la matriz
    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4; x++)
        {
            cin >> iMatriz[y][x];
        }
    }

    //Se gira la matriz
    if(iResiduo == 0)//Ningun giro
    {
        //Simplemente se despliega la matriz otra vez
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                if(x == 3)
                {
                    cout << iMatriz[y][x];
                }
                else
                {
                    cout << iMatriz[y][x] << " ";
                }
            }
            cout << endl;
        }
    }
    else if(iResiduo == 1)//Un giro
    {
        //Se gira una vez
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                iMatrizTemporal[x][y] = iMatriz[3 - y][x];
            }
        }

        //Se despliega
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                if(x == 3)
                {
                    cout << iMatrizTemporal[y][x];
                }
                else
                {
                    cout << iMatrizTemporal[y][x] << " ";
                }
            }

            cout << endl;
        }
    }
    else if(iResiduo == 2)//Dos giros
    {
        //Se gira dos veces
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                iMatrizTemporal[y][x] = iMatriz[3 - y][3 - x];
            }
        }

        //Se despliega el resultado
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                if(x == 3)
                {
                    cout << iMatrizTemporal[y][x];
                }
                else
                {
                    cout << iMatrizTemporal[y][x] << " ";
                }
            }

            cout << endl;
        }
    }
    else if(iResiduo == 3)//Tres giros
    {
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                iMatrizTemporal[y][x] = iMatriz[x][3 - y];
            }
        }

        //Se depsliega la matriz
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                if(x == 3)
                {
                    cout << iMatrizTemporal[y][x];
                }
                else
                {
                    cout << iMatrizTemporal[y][x] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
