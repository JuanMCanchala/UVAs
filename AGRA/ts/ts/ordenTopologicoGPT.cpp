#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int> > &graph, vector<bool> &visited, stack<int> &order) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]]) {
            dfs(graph[node][i], graph, visited, order);
        }
    }
    order.push(node);
}

void orden_topologico_dfs(vector<vector<int> > &graph, int nodes) {
    vector<bool> visited(nodes, false);
    stack<int> order;

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, order);
        }
    }

    // Imprimir el orden topológico
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
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

    orden_topologico_dfs(graph, nodes);

    return 0;
}
