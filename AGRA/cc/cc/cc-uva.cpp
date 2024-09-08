#include <iostream>
#include <vector>

using namespace std;

#define UNVISITED -1

vector<vector<int> > adjList; // Lista de adyacencia
vector<int> dfs_num;          // Estado de cada vértice: visitado o no
int numCC;                    // Número de componentes conexos

void dfs(int u) {
    // Marcar el vértice como visitado
    dfs_num[u] = 1;
    printf("%d ", u); // Imprimir el vértice actual (pertenece al componente actual)

    // Recorrer todos los vecinos del vértice u
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == UNVISITED) { // Si el vecino no ha sido visitado
            dfs(v);                     // Llamada recursiva para explorar el vecino
        }
    }
}

int main() {
    int V; // Número de vértices en el grafo
    cin >> V;

    adjList.assign(V, vector<int>()); // Inicializar la lista de adyacencia
    dfs_num.assign(V, UNVISITED);     // Inicializar el estado de los vértices

    int E; // Número de aristas
    cin >> E;

    // Leer las aristas del grafo
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Grafo no dirigido
    }

    numCC = 0; // Inicializamos el número de componentes conexos

    // Ejecutar DFS para encontrar los componentes conexos
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {  // Si el vértice no ha sido visitado
            printf("CC %d: ", ++numCC); // Nuevo componente conexo
            dfs(i);                     // Llamada DFS para explorar todo el componente
            printf("\n");               // Nueva línea al finalizar el componente
        }
    }

    return 0;
}
