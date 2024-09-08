#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void orden_topologico_kahn(vector<vector<int> > &graph, int nodes) {
    vector<int> in_degree(nodes, 0);

    // Calcular los grados de entrada
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            in_degree[graph[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topological_order;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topological_order.push_back(node);

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Verificar si se ha generado un orden topológico
    if (topological_order.size() != nodes) {
        cout << "El grafo tiene un ciclo, no es posible un orden topológico" << endl;
    } else {
        for (int i = 0; i < topological_order.size(); i++) {
            cout << topological_order[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int> > graph(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);  // Arista de u a v
    }

    orden_topologico_kahn(graph, nodes);

    return 0;
}
