#include <iostream>
#include <vector>

using namespace std;

#define UNVISITED -1

void dfs(int u, vector<vector<int>>& graph, vector<int>& visits) {
    visits[u] = 1; 
    for (int j = 0; j < (int)graph[u].size(); j++) {
        int v = graph[u][j];
        if (visits[v] == UNVISITED) {
            dfs(v, graph, visits);
        }
    }
}

int contarComponentesConexos(int V, vector<vector<int>>& graph) {
    vector<int> visits(V, UNVISITED); 
    int numCC = 0; 

    for (int i = 0; i < V; ++i) {
        if (visits[i] == UNVISITED) {
            ++numCC;
            dfs(i, graph, visits); 
        }
    }

    return numCC;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> graph(V); // Lista de adyacencia

    // Leer las aristas y construir la lista de adyacencia
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Grafo no dirigido
    }

    cout << contarComponentesConexos(V, graph) << endl;

    return 0;
}
