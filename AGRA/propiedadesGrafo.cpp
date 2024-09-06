//libro de uva

#include <iostream>
#include <vector>
#include <cstdio> // Para usar printf

// Definiciones para el estado de los nodos durante DFS
enum { UNVISITED, EXPLORED, VISITED };

// Tipos para almacenar la lista de adyacencias y los estados de visita
typedef std::pair<int, int> ii; // Tipo para representar una arista
std::vector<std::vector<ii> > AdjList; // Lista de adyacencia
std::vector<int> dfs_num; // Estado de visita (UNVISITED, EXPLORED, VISITED)
std::vector<int> dfs_parent; // Vector para almacenar el padre de cada vértice en el árbol DFS

void graphCheck(int u) {
    // Marcamos el vértice u como explorado
    dfs_num[u] = EXPLORED;

    // Recorremos cada vértice adyacente a u
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];

        // Si el vértice v no ha sido visitado, es una arista de árbol
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u; // Establecemos u como padre de v
            graphCheck(v.first); // Llamada recursiva para explorar v
        } else if (dfs_num[v.first] == EXPLORED) {
            // Diferenciamos si es una arista bidireccional o un ciclo
            if (v.first == dfs_parent[u])
                printf(" Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
            else
                printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
        } else if (dfs_num[v.first] == VISITED) {
            // Si el vértice ha sido completamente visitado, es una arista adelante o cruzada
            printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
        }
    }

    // Marcamos el vértice u como completamente visitado
    dfs_num[u] = VISITED;
}

int main() {
    int V; // Número de vértices
    int numComp = 0; // Contador de componentes

    // Inicializamos los vectores para el número de vértices V
    // Nota: Se asume que el número de vértices V es conocido de antemano
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, 0);

    // Llamada a DFS para cada componente no visitado
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {
            printf("Component %d:\n", ++numComp);
            graphCheck(i);
        }
    }

    return 0;
}
