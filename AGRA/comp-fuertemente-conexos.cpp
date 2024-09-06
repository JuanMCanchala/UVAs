//libro de uva
//Algoritmo de tarjan para scc

#include <iostream>
#include <vector>
#include <algorithm> // Para min()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AdjList;  // Lista de adyacencia
vi dfs_num, dfs_low, S, visited;  // Variables globales
int dfsNumberCounter, numSCC;
const int UNVISITED = -1;

// Función que implementa el algoritmo de Tarjan para encontrar SCC
void tarjanSCC(int u) {
    // Inicializar dfs_low y dfs_num para el nodo actual
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    
    S.push_back(u);  // Guardar u en la pila según el orden de visita
    visited[u] = 1;  // Marcar el nodo como visitado en esta iteración

    // Recorrer los nodos adyacentes de u
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];

        if (dfs_num[v.first] == UNVISITED) {  // Si el nodo v no ha sido visitado
            tarjanSCC(v.first);  // Llamada recursiva para v
        }
        
        // Actualizar dfs_low[u] si v está en el SCC actual
        if (visited[v.first]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
    }

    // Si u es el nodo raíz de un SCC
    if (dfs_low[u] == dfs_num[u]) {
        printf("SCC %d:", ++numSCC);  // Nuevo SCC encontrado

        // Desapilar hasta encontrar el nodo u
        while (1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;  // Marcar el nodo como no visitado
            printf(" %d", v);  // Imprimir nodo en el SCC actual
            if (u == v) break;  // Salir del bucle cuando se alcanza u
        }
        printf("\n");
    }
}

int main() {
    int V;  // Número de vértices
    cin >> V;

    AdjList.assign(V, vi());  // Inicializar la lista de adyacencia

    // Lectura de las aristas
    int E;  // Número de aristas
    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);  // Grafo dirigido u -> v
    }

    // Inicialización de variables
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    visited.assign(V, 0);
    dfsNumberCounter = numSCC = 0;

    // Aplicar el algoritmo de Tarjan a cada componente no visitada
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {
            tarjanSCC(i);
        }
    }

    return 0;
}
