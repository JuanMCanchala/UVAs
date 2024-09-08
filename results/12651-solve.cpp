/*
Juan Manuel Canchala
8983809
Carlos Ramirez
Complejidad: n x log n

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int numCasos;
    while (cin >> numCasos) {
        vector<int> numeros(numCasos);
        int sumaTotal = 0;

        for (int i = 0; i < numCasos; i++) {
            cin >> numeros[i];
            sumaTotal += numeros[i];
        }

        if (sumaTotal % 3 == 0) {
            int longitud = sumaTotal / 3;
            set<int> sumaPre;
            int sumaAcumulada = 0;

            for (int i = 0; i < numCasos; i++) {
                sumaAcumulada += numeros[i];
                sumaPre.insert(sumaAcumulada % sumaTotal);
            }

            int count1 = 0, ans = 0;
            sumaAcumulada = 0;

            for (int i = 0; i < numCasos; i++) {
                sumaAcumulada += numeros[i];
                // el principal problema estaba en que tenia que usar modulo para los valores si no puede que de triangulos falsos como pasaba con la primera version de este codigo
                if (sumaPre.find((sumaAcumulada + longitud) % sumaTotal) != sumaPre.end() &&
                    sumaPre.find((sumaAcumulada + 2 * longitud) % sumaTotal) != sumaPre.end()) {
                    ans++;
                }
            }

            cout << ans / 3 << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}
