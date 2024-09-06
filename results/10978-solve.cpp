/*
Nombre: Juan Manuel Canchala
Codigo: 8983809
Complejidad: O(N^2) para la lectura lo hacemos en N para guardar la carta y los movimientos en dos vectores distintos posteriormente creo un vector de resultados y lo relleno de strings con "X" y en el procesamiento que es de N^2 donde reemplazo el vector de resultado en las posiciones de "X" con las cartas
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N; // lee el numero de casos
    while (cin >> N && N != 0)
    {
        vector<string> cartas(N);
        vector<string> movimientos(N);

        // Read card values and movimientos
        for (int i = 0; i < N; i++)
        {
            cin >> cartas[i] >> movimientos[i];
        }

        vector<string> resultado(N);

        for (int i = 0; i < N; i++)
        {
            resultado[i] = "X";
        }

        int posicionActual = 1;

        for (int i = 0; i < N; i++)
        {
            int avance = 0;
            if (movimientos[i].length() > 0)
            {
                while (avance < movimientos[i].length())
                {
                    posicionActual = (posicionActual + 1) % N;
                    if (resultado[posicionActual] == "X")
                    {
                        avance++;
                    }
                }
            }
            resultado[posicionActual] = cartas[i];
        }
        // tengo que tomar en cuenta que si por ejemplo las cartas son menores de 3 va a dar un error de segmento por la forma en la que imprimo
        if (resultado.size() < 2)
        {
            cout << resultado[0] << endl;
        }
        if (resultado.size() <= 2 && resultado.size() != 1 )
        {
            cout << resultado[0] << " ";
            cout << resultado[1] << endl;
        }
        if (resultado.size() >= 3)
        {
            for (int i = 2; i < N; i++)
            {
                cout << resultado[i] << " ";
            }

            cout << resultado[0] << " " << resultado[1] << endl;
        }
        if (resultado.size() < 3 && resultado.size() != 2 && resultado.size() != 1)
        {
            for (int i = 0; i < N; i++)
            {
                cout << resultado[i] << " " << endl;
            }
        }
    }
    return 0;
}