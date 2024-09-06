/*
libro de uva

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii; // Par de enteros (vértice, peso)
vector<vector<ii>> AdjList; // Lista de adyacencia: (vértice, peso)

const int INF = 1e9; // Un valor grande para representar "infinito"
int s, t; // Vértices origen y destino

// Función recursiva para imprimir el camino desde el vértice s hasta u
void printPath(int u, const vector<int>& p) {
    if (u == s) { // Caso base: llegamos al origen
        printf("%d", s);
        return;
    }
    printPath(p[u], p); // Llamada recursiva al predecesor de u
    printf(" %d", u); // Imprimir el vértice actual
}

int main() {
    int V, E; // Número de vértices y aristas
    scanf("%d %d", &V, &E);

    AdjList.assign(V, vector<ii>()); // Inicializar la lista de adyacencia

    // Leer las aristas del grafo
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        AdjList[u].push_back(ii(v, 0)); // Grafo no ponderado
        AdjList[v].push_back(ii(u, 0)); // Añadir arista bidireccional
    }

    // Leer los vértices de origen s y destino t
    scanf("%d %d", &s, &t);

    // Inicialización del BFS
    vector<int> dist(V, INF); // Inicializar distancias a INF
    dist[s] = 0; // La distancia del origen s a sí mismo es 0
    queue<int> q; // Cola para realizar BFS
    q.push(s); // Insertar el origen en la cola

    vector<int> p(V, -1); // Vector de predecesores/padres
    p[s] = s; // El predecesor de s es él mismo

    // BFS para calcular las distancias mínimas y los predecesores
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j]; // Vértice adyacente a u
            if (dist[v.first] == INF) { // Si no ha sido visitado
                dist[v.first] = dist[u] + 1; // Actualizar la distancia
                p[v.first] = u; // Registrar el predecesor
                q.push(v.first); // Insertar el vértice en la cola
            }
        }
    }

    // Imprimir el camino más corto desde s hasta t
    printPath(t, p);
    printf("\n");

    return 0;
}
