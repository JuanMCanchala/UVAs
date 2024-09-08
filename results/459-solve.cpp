#include <vector>
#include <map>
#include <iostream>

using namespace std;

int UNVISITED = -1;

void dfs(int u, map<int, vector<int>>& graph, vector<int>& visits) {
    visits[u] = 1;
    for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j];
        if (visits[v] == UNVISITED) dfs(v, graph, visits);
    }
}

int contarComponentesConexos(map<int, vector<int>>& graph, int V) {
    vector<int> visits(V, UNVISITED);
    int numCC = 0;
    for (int i = 0; i < V; i++) {
        if (visits[i] == UNVISITED) {
            numCC++;
            dfs(i, graph, visits);
        }
    }
    return numCC;
}

int main() {
    int numCasos;
    cin >> numCasos;
    while (numCasos--) {
        char c;
        cin >> c;
        int V = c - 'A' + 1;
        char u, v;
        map<int, vector<int>> graph;
        cin.ignore();
        string s;
        while (getline(cin, s) && !s.empty()) {
            u = s[0];
            v = s[1];
            graph[u - 'A'].push_back(v - 'A');
            graph[v - 'A'].push_back(u - 'A');
        }
        cout << contarComponentesConexos(graph, V) << endl;
        if (numCasos) cout << endl;
    }
    return 0;
}
