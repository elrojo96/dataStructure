//Luis Alfonso Rojo Sánchez
//A01113049
//Estructura de Datos
//Tarea 2: Comprobar el Sudoku

#include <iostream>

using namespace std;

int main()
{
    //Matriz que simula al Sudoku
    int iSudoku[9][9];

    //Variable para comprobar que el Sudoku tiene variables repetidas
    bool bRepetido = false;

    //Se le dan valores al Sudoku
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> iSudoku[i][j];
        }
    }

    //Comprobacion de si la matriz es un Sudoku
    for(int iFila = 0; iFila < 9; iFila++)
    {
        for(int iColumna = 0; iColumna < 9; iColumna++)
        {
            //Comprobacion en horizontal
            for(int iHorizontal = 0; iHorizontal < 9 && !bRepetido; iHorizontal++)
            {
                if(iHorizontal != iColumna)
                {
                    if(iSudoku[iFila][iColumna] == iSudoku[iFila][iHorizontal])
                    {
                        bRepetido = true;
                    }
                }
            }

            //Comprobacion en vertical
            for(int iVertical = 0; iVertical < 9 && !bRepetido; iVertical++)
            {
                if(iVertical != iFila)
                {
                    if(iSudoku[iFila][iColumna] == iSudoku[iVertical][iColumna])
                    {
                        bRepetido = true;
                    }
                }
            }

            //Comprobacion en cuadrante de 3X3
            int iRLI = iFila - (iFila % 3);
            int iCLI = iColumna - (iColumna %3);
            int iRLS = iRLI + 2;
            int iCLS = iCLI + 2;

            for(int iFil = iRLI; iFil <= iRLS && !bRepetido; iFil++)
            {
                if(iFil != iFila)
                {
                    for(int iCol = iCLI; iCol <= iCLS && !bRepetido; iCol++)
                    {
                        if(iCol != iColumna)
                        {
                            if(iSudoku[iFil][iCol] == iSudoku[iFila][iColumna])
                            {
                                bRepetido = true;
                            }
                        }
                    }
                }
            }
        }
    }

    //Se despliega si la matriz es un Sudoku o no
    if(bRepetido == true)
    {
        cout << "NO" << endl;
    }
    else if(bRepetido == false)
    {
        cout << "YES" << endl;
    }

    return 0;
}
