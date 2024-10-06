/*
Juan Manuel Canchala
8983809
Carlos Ramirez
Complejidad: nlogn
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Estas implementaciones de ambas funciones fueron sacadas del libro negro del competidor por Robin Quintero 
y fueron hechas algunas modificaciones para adaptarlas al problema de bids
*/
/*
La utilidad de estas dos funciones para el problema son:
lowebound: busca la primera posicion donde el valor no es menor que x.
upperbound: encuentra la primera posición donde el valor es mayor que x.
*/
int upperBound(vector<int>& A, int x) {
    int lo = 0, hi = A.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] > x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int lowerBound(vector<int>& A, int x) {
    int lo = 0, hi = A.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

// Definir una estructura para almacenar el precio y el número de personas enojadas
struct Resultado {
    int precio;
    int enojados;
};

int main() {
    int numCases;
    cin >> numCases;
    // inicio de lectura 
    while (numCases--) {
        int numProductores, numConsumidores;
        cin >> numProductores >> numConsumidores;

        vector<int> productores(numProductores);
        vector<int> consumidores(numConsumidores);
        vector<int> totales;

        for (int i = 0; i < numProductores; i++) {
            int p;
            cin >> p;
            productores[i] = p;
            totales.push_back(p);
        }

        for (int i = 0; i < numConsumidores; i++) {
            int c;
            cin >> c;
            consumidores[i] = c;
            totales.push_back(c);
        }
        
        // Ordenar todas las listas
        sort(productores.begin(), productores.end());
        sort(consumidores.begin(), consumidores.end());
        totales.push_back(0);  
        sort(totales.begin(), totales.end());

        Resultado resultado;
        resultado.enojados = numProductores + numConsumidores + 1;  
        resultado.precio = 0;  

        // Recorre todos los precios en totales para evaluar los precios de oferta
        for (int i = 0; i < totales.size(); i++) {
            int act = totales[i];

            int productoresMas = numProductores - upperBound(productores, act);
            int consumidoresMenos = lowerBound(consumidores, act);

            int enojados = productoresMas + consumidoresMenos;

            if (enojados < resultado.enojados || (enojados == resultado.enojados && act < resultado.precio)) {
                resultado.enojados = enojados;
                resultado.precio = act;
            }
        }

        cout << resultado.precio << " " << resultado.enojados << endl;
    }

    return 0;
}
