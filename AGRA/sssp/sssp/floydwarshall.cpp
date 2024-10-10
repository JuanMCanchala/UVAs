#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void floydWarshall(vector<vector<double>>& w, vector<vector<double>>& d, vector<vector<int>>& next) {
    int n = w.size();
    
    // Inicialización de d y next
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = w[i][j];
            next[i][j] = j;
        }
    }

    // Establecer las diagonales en 0
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
        next[i][i] = i;
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

int main() {
    int n = 5;
    // Matriz de pesos inicializada manualmente
    vector<vector<double> > w(n, vector<double>(n, numeric_limits<double>::infinity()));
    w[0][0] = 0; w[0][1] = 4; w[0][2] = 5;
    w[1][1] = 0; w[1][2] = -1; w[1][3] = 1;
    w[2][1] = 2; w[2][2] = 0; w[2][3] = -1; w[2][4] = 1;
    w[3][0] = 2; w[3][4] = 2;
    w[4][0] = 3; w[4][1] = 3; w[4][4] = 0;

    // Inicializar matrices d y next
    vector<vector<double> > d(n, vector<double>(n, numeric_limits<double>::infinity()));
    vector<vector<int> > next(n, vector<int>(n, -1));

    // Llamada a la función de Floyd-Warshall
    floydWarshall(w, d, next);

    // Imprimir matriz next (se puede modificar para imprimir d también si se desea)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << next[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
