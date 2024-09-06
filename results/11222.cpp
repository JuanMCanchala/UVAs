/*
Nombre: Juan Manuel Canchala Jimenez
Codigo: 8983809
Complejidad:Es O(N^2) Lectura la complejidad es O(N) ya que para los 3 amigos los guardamos en un vector que seria 3N pero por generalidad lo dejamos como O(N) en la funcion de eliminacion de elementos repetidos es O(N) y en la funcion de eliminacion de elementos comunes la complejidad es O(N^2) por lo tanto la complejidad del programa es O(N^2)
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// elimina los elementos repetidos adyancentes asi que como ya lo tenemmos ordenados no hay tema
void eliminarRepetidosUnaLista(vector<int> &deleteRepeted)
{
    vector<int>::iterator nuevoFin = unique(deleteRepeted.begin(), deleteRepeted.end());

    // Ahora, vectorOrdenado contiene los elementos únicos al principio
    deleteRepeted.erase(nuevoFin, deleteRepeted.end());
}
void eliminarRepetidos(vector<int> &lista1, vector<int> &lista2, vector<int> &lista3)
{
    /*Al parecer si el numero x esta repetido varias veces en el primer vector y esta tambien en los otros 2 se imprime no se porque asi que eliminare los comunes de los 3 vectores*/
    // Eliminar elementos repetidos en (1 y 2)

    vector<int> commonNumbers;
    vector<int>::iterator it1 = lista1.begin();
    vector<int>::iterator it2 = lista2.begin();
    while (it1 != lista1.end() && it2 != lista2.end())
    {

        if (*it1 == *it2)
        {
            it1 = lista1.erase(it1);
            it2 = lista2.erase(it2);
        }
        else if (*it1 < *it2)
        {
            it1++;
        }
        else
        {
            it2++;
        }
    }

    // Eliminar elementos repetidos en (1 y 3)
    it1 = lista1.begin();
    vector<int>::iterator it3 = lista3.begin();

    while (it1 != lista1.end() && it3 != lista3.end())
    {
        if (*it1 == *it3)
        {
            it1 = lista1.erase(it1);
            it3 = lista3.erase(it3);
        }
        else if (*it1 < *it3)
        {
            it1++;
        }
        else
        {
            it3++;
        }
    }

    // Eliminar elementos repetidos en (2 y 3)
    it2 = lista2.begin();
    it3 = lista3.begin();

    while (it2 != lista2.end() && it3 != lista3.end())
    {
        if (*it2 == *it3)
        {
            it2 = lista2.erase(it2);
            it3 = lista3.erase(it3);
        }
        else if (*it2 < *it3)
        {
            it2++;
        }
        else
        {
            it3++;
        }
    }
}

void eliminarComun(vector<int> &lista1, vector<int> &lista2, vector<int> &lista3)
{
    vector<int> commonNumbers;

    // Encontrar los números comunes
    for (int i = 0; i < lista1.size(); i++)
    {
        int num = lista1[i];
        if (count(lista2.begin(), lista2.end(), num) > 0 && count(lista3.begin(), lista3.end(), num) > 0)
        {
            commonNumbers.push_back(num);
        }
    }

    // Eliminar el número común de las tres listas
    for (int i = 0; i < commonNumbers.size(); i++)
    {
        int num = commonNumbers[i];
        lista1.erase(remove(lista1.begin(), lista1.end(), num), lista1.end());
        lista2.erase(remove(lista2.begin(), lista2.end(), num), lista2.end());
        lista3.erase(remove(lista3.begin(), lista3.end(), num), lista3.end());
    }
}
int main()
{
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++)
    {
        int size1, size2, size3;
        vector<int> lista1, lista2, lista3;

        scanf("%d", &size1);
        for (int j = 0; j < size1; j++)
        {
            int numeros1;
            scanf("%d", &numeros1);
            lista1.push_back(numeros1);
        }

        scanf("%d", &size2);
        for (int k = 0; k < size2; k++)
        {
            int numeros2;
            scanf("%d", &numeros2);
            lista2.push_back(numeros2);
        }

        scanf("%d", &size3);
        for (int l = 0; l < size3; l++)
        {
            int numeros3;
            scanf("%d", &numeros3);
            lista3.push_back(numeros3);
        }

        // eliminar y ordenar los repetidos de una lista y de todas las listas
        sort(lista1.begin(), lista1.end());
        sort(lista2.begin(), lista2.end());
        sort(lista3.begin(), lista3.end());
        eliminarRepetidosUnaLista(lista1);
        eliminarRepetidosUnaLista(lista2);
        eliminarRepetidosUnaLista(lista3);
        eliminarComun(lista1, lista2, lista3);
        eliminarRepetidos(lista1, lista2, lista3);
        int amigo1 = lista1.size();
        int amigo2 = lista2.size();
        int amigo3 = lista3.size();
        int result = max(max(amigo1, amigo2), amigo3);

        printf("Case #%d:\n", i + 1);

        if (result == amigo1)
        {
            cout << 1 << " " << amigo1 << " ";
            for (int r = 0; r < lista1.size(); r++)
            {
                cout << lista1[r];
                if (r < lista1.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        if (result == amigo2)
        {
            cout << 2 << " " << amigo2 << " ";
            for (int r = 0; r < lista2.size(); r++)
            {
                cout << lista2[r];
                if (r < lista2.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        if (result == amigo3)
        {
            cout << 3 << " " << amigo3 << " ";
            for (int r = 0; r < lista3.size(); r++)
            {
                cout << lista3[r];
                if (r < lista3.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
