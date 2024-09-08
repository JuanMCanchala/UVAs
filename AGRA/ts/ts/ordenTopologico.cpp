/*
Implementación Algoritmo Orden Topológico
Agosto 17 de 2023
*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > G;        // Lista de adyacencia
vector<int> topo;              // Almacena el orden topológico
vector<int> visited;           // Marca los nodos visitados
vector<int> inc;               // Grados de entrada

// Función de ordenamiento topológico recursiva
void topoSort(int p, int n) {
    if (p < n) {
        int r = -1;
        for (int i = 0; i < n && r == -1; ++i) {
            if (visited[i] == 0 && inc[i] == 0) {
                r = i;
            }
        }

        if (r != -1) {
            for (int i = 0; i < G[r].size(); ++i) {
                int v = G[r][i];
                --inc[v];
            }
            visited[r] = 1;
            topo.push_back(r);
            topoSort(p + 1, n);
        }
    }
}

int main() {
    int n, m;
    
    // Leer la cantidad de nodos y aristas
    scanf("%d %d", &n, &m);

    // Inicializar las estructuras de datos
    G.resize(n);
    visited.assign(n, 0);
    inc.assign(n, 0);
    topo.clear();

    // Leer las aristas del grafo
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; ++j) {
            int v;
            scanf("%d", &v);
            G[i].push_back(v);
            ++inc[v];
        }
    }

    // Imprimir la representación del grafo y los grados de entrada
    cout << "Grafo\n";
    for (int i = 0; i < n; ++i) {
        printf("Nodo %d:", i);
        for (int j = 0; j < G[i].size(); ++j) {
            printf(" %d", G[i][j]);
        }
        printf("\n");
    }

    // Ordenamiento topológico
    cout << "Ordenamiento Topológico:\n";
    topoSort(0, n);

    // Imprimir el resultado del orden topológico
    for (int i = 0; i < topo.size(); ++i) {
        printf("%d ", topo[i]);
    }
    printf("\n");

    return 0;
}
