/*
Nombre: Juan Manuel Canchala
Codigo: 8983809
Complejidad: Es O(N^2) para la lecutra lo hacemos en un for y lo guardamos en un vector de struct y para el posterior procesamiento lo hacemos en O(N^2) para repartir el dinero a los amigos y finalmente para el output seria O(N) 
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Amigo
{
    string amigo;
    int dinero;
};

int main()
{
    int casos, dinero, quienes, division, modulo;
    string entrada, repartidor, nombresreciben;

    while (cin >> casos)
    {
        vector<Amigo> amigos;

        for (int i = 0; i < casos; i++)
        {
            cin >> entrada;
            Amigo estructura;
            estructura.amigo = entrada;
            estructura.dinero = 0; // Inicializa el dinero en 0 para cada amigo
            amigos.push_back(estructura);
        }

        for (int j = 0; j < casos; j++)
        {
            cin >> repartidor >> dinero >> quienes;

            if (quienes != 0)
            {
                division = dinero / quienes;
                modulo = dinero % quienes;

                // Encuentra al amigo que reparte el dinero
                for (int a = 0; a < casos; a++)
                {
                    if (amigos[a].amigo == repartidor)
                    {
                        amigos[a].dinero -= dinero;
                        amigos[a].dinero += modulo;
                    }
                }

                for (int a = 0; a < quienes; a++)
                {
                    cin >> nombresreciben;
                    for (int b = 0; b < casos; b++)
                    {
                        if (amigos[b].amigo == nombresreciben)
                        {
                            amigos[b].dinero += division;
                        }
                    }
                }
            }
        }

        for (int r = 0; r < casos; r++)
        {
            cout << amigos[r].amigo << " " << amigos[r].dinero << endl;
        }
            cout << endl;
    }

    return 0;
}
