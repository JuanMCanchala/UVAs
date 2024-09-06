//libro de uva

#include <iostream>
#include <vector>
#include <algorithm> // Para min()

using namespace std;

typedef pair<int, int> ii;
vector<vector<ii>> AdjList;  // Lista de adyacencia
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
const int UNVISITED = -1;

// Función para encontrar puntos de articulación y puentes
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // Inicializar dfs_low y dfs_num

    // Explorar los vecinos de u
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];

        // Si el nodo v no ha sido visitado
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;  // Asignar padre
            if (u == dfsRoot) rootChildren++;  // Caso especial para la raíz

            // Llamada recursiva para v
            articulationPointAndBridge(v.first);

            // Verificar si u es un punto de articulación
            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;

            // Verificar si es un puente
            if (dfs_low[v.first] > dfs_num[u])
                printf("Edge (%d, %d) is a bridge\n", u, v.first);

            // Actualizar dfs_low de u
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        // Arista inversa y no es el padre directo
        else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}

int main() {
    int V;  // Número de vértices
    cin >> V;
    
    AdjList.assign(V, vector<ii>());  // Inicializar lista de adyacencia

    // Lectura de las aristas
    int E;  // Número de aristas
    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(ii(v, 0));  // Grafo no ponderado
        AdjList[v].push_back(ii(u, 0));  // Añadir ambas direcciones (grafo no dirigido)
    }

    // Inicialización de variables
    dfsNumberCounter = 0;
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0);
    articulation_vertex.assign(V, 0);

    printf("Bridges:\n");

    // Ejecutar el algoritmo para cada componente no visitada
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1);  // Caso especial para la raíz
        }
    }

    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++) {
        if (articulation_vertex[i])
            printf("Vertex %d\n", i);
    }

    return 0;
}
