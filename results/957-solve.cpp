#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Respuesta {
    int numPapas;
    int firstPapa;
    int lastPapa;
};

Respuesta findRango(vector<int>& popes, int rango) {
    int maxPopes = 0;
    int primerYear = 0;
    int ultimoYear = 0;
    int n = popes.size();

    for (int i = 0; i < n; ++i) {
        int inicio = popes[i];
        int fin = inicio + rango - 1;
    
        int j = upper_bound(popes.begin(), popes.end(), fin) - popes.begin();

        int count = j - i;

        if (count > maxPopes) {
            maxPopes = count;
            primerYear = inicio;
            ultimoYear = popes[j - 1];
        }
    }

    Respuesta respuesta;
    respuesta.numPapas = maxPopes;
    respuesta.firstPapa = primerYear;
    respuesta.lastPapa = ultimoYear;
    return respuesta;
}

int main() {
    int rango;
    while (cin >> rango) {
        int numPopes;
        cin >> numPopes;

        vector<int> popes(numPopes);
        for (int i = 0; i < numPopes; ++i) {
            cin >> popes[i];
        }

        Respuesta result = findRango(popes, rango);
        cout << result.numPapas << " " << result.firstPapa << " " << result.lastPapa << endl;
    }

    return 0;
}
