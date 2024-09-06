#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Función para construir el arreglo de sufijos
vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> suffixArray(n), rank(n), tempRank(n);

    // Inicializar el arreglo de sufijos y el arreglo de rangos
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i; // Inicialmente, el sufijo i comienza en la posición i
        rank[i] = s[i];     // El rango inicial es el valor ASCII del carácter
    }

    // Ordenar los sufijos usando la técnica de comparación por rangos
    for (int k = 1; k < n; k *= 2) {
        // Comparador lambda para ordenar los sufijos basados en los primeros 2k caracteres
        auto comparator = [&rank, &n, &k](int a, int b) {
            if (rank[a] != rank[b]) {
                return rank[a] < rank[b];
            }
            int rankA = (a + k < n) ? rank[a + k] : -1;
            int rankB = (b + k < n) ? rank[b + k] : -1;
            return rankA < rankB;
        };

        sort(suffixArray.begin(), suffixArray.end(), comparator);

        // Recalcular los rangos temporales
        tempRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]];
            if (comparator(suffixArray[i - 1], suffixArray[i])) {
                tempRank[suffixArray[i]]++;
            }
        }

        // Actualizar los rangos
        rank = tempRank;
    }

    return suffixArray;
}

// Función para imprimir el arreglo de sufijos
void printSuffixArray(const vector<int>& suffixArray, const string &s) {
    cout << "Sufijos ordenados lexicográficamente:\n";
    for (int i : suffixArray) {
        cout << i << ": " << s.substr(i) << '\n';
    }
}

int main() {
    string s;
    cout << "Ingresa una cadena: ";
    cin >> s;

    // Construir el arreglo de sufijos
    vector<int> suffixArray = buildSuffixArray(s);

    // Imprimir el arreglo de sufijos
    printSuffixArray(suffixArray, s);

    return 0;
}
