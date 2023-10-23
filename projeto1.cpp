#include <bits/stdc++.h>

using namespace std;

int main()
{

    // Definindo a Matriz de Adjacencias
    int matriz[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
    matriz[0][0] = 0;
    matriz[1][0] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[2][1] = 1;
    matriz[2][3] = 1;
    matriz[3][2] = 1;
    matriz[3][4] = 1;
    matriz[2][1] = 1;
    matriz[4][3] = 1;

    int matrizA2[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int soma = 0;
            for (int a = 0; a < 5; a++)
            {
                soma += matriz[i][a] * matriz[a][j];
            }
            matrizA2[i][j] = soma;
        }
    }

    int matrizA3[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int soma = 0;
            for (int a = 0; a < 5; a++)
            {
                soma += matrizA2[i][a] * matriz[a][j];
            }
            matrizA3[i][j] = soma;
        }
    }

    // Definindo a Matriz de Adjacencias
    while (true)
    {
        // Resolução (i)
        int li, lj;
        cout << "Digite os dois locais de transmissao: ";
        cin >> li >> lj;
        int ai = li - 1;
        int aj = lj - 1;
        cout << "Possibilidades: " << matriz[ai][aj] << endl;
        if (matriz[ai][aj])
            cout << "(i): L" << li << " -> L" << lj << endl;
        else
            cout << "(i): Nao ha caminhos diretos entre o local " << li << " e " << lj << endl;
        // Resolução (i)

        // Resolução (ii)
        cout << "Possibilidades: " << matrizA2[ai][aj] << endl;
        for (int a = 0; a < 5; a++)
        {
            if (a == aj || a == ai)
                continue;
            if (matriz[ai][a] == 1 && matriz[a][aj] == 1)
            {
                cout << "(ii): L" << li << " -> L" << a + 1 << " -> L" << lj << endl;
            }
        }
        // Resolução (ii)

        // Resolução (iii)
        cout << "Possibilidades: " << matrizA3[ai][aj] << endl;
        for (int a = 0; a < 5; a++)
        {
            if (a == aj || a == ai)
                continue;
            if (matriz[ai][a])
            {
                for (int b = 0; b < 5; b++)
                {
                    if (b == aj || b == ai)
                        continue;
                    if (matriz[a][b] == 1 && matriz[b][aj] == 1)
                    {
                        cout << "(ii): L" << li << " -> L" << a + 1 << " -> L" << b + 1 << " -> L" << lj << endl;
                    }
                }
            }
        }
        // Resolução (iii)
        cout << "Deseja continuar? [y/n]: ";
        char parada;
        cin >> parada;
        if(parada == 'n')
        {
            cout << "Fim do programa!" << endl;
            break;
        }
    }

    return 0;
}