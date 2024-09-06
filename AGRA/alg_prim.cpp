// libro de uva

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii; // Par de enteros (peso, vértice)
vector<vector<ii>> AdjList; // Lista de adyacencia: (peso, vértice)
vector<int> taken; // Etiqueta booleana para evitar ciclos
priority_queue<ii> pq; // Cola de prioridad para elegir las aristas más cortas

// Función para procesar las aristas incidentes a un vértice
void process(int vtx) {
    taken[vtx] = 1; // Marcar el vértice como "tomado"
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ii(-v.second, -v.first)); // Se usa signo negativo para invertir el orden (min-heap)
        }
    }
}

int main() {
    int V, E; // Número de vértices y aristas
    scanf("%d %d", &V, &E);

    AdjList.assign(V, vector<ii>()); // Inicializar la lista de adyacencia

    // Leer las aristas del grafo
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); // Leer (u, v, w): vértices y peso de la arista
        AdjList[u].push_back(ii(v, w)); // Añadir arista u -> v
        AdjList[v].push_back(ii(u, w)); // Añadir arista v -> u (grafo no dirigido)
    }

    // Inicialización del algoritmo
    taken.assign(V, 0); // Al principio, no se ha tomado ningún vértice
    process(0); // Tomamos el vértice 0 y procesamos todas sus aristas incidentes

    int mst_cost = 0, num_taken = 0; // Inicialmente no hemos tomado ninguna arista

    // Mientras queden aristas en la cola de prioridad y no se hayan tomado V-1 aristas
    while (!pq.empty() && num_taken < V - 1) {
        ii front = pq.top(); pq.pop(); // Tomamos la arista más ligera disponible
        int u = -front.second, w = -front.first; // Desinvertimos los signos

        // Si el vértice u aún no ha sido tomado
        if (!taken[u]) {
            num_taken++; // Tomamos una arista más como parte del MST
            mst_cost += w; // Sumamos el peso de la arista al costo total del MST
            process(u); // Procesamos todas las aristas incidentes al vértice u
        }
    }

    // Imprimir el costo total del MST
    printf("MST cost = %d (Prim's)\n", mst_cost);

    return 0;
}
