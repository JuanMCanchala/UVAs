#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int INF = -1;

bool esBipartito(map<int, vector<int> >& graph, int numNodos) {
    vector<int> color(numNodos, INF);
    queue<int> q;
    bool esBipartito = true;

    for (int i = 0; i < numNodos && esBipartito; i++) {
        if (color[i] == INF) {
            color[i] = 0;
            q.push(i);
        }
        while (!q.empty() && esBipartito) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                if (color[v] == INF) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    esBipartito = false;
                }
            }
        }
    }
    return esBipartito;
}

int main() {
    int numNodos;
    while (cin >> numNodos && numNodos != 0) {
        int numAristas;
        cin >> numAristas;
        map<int, vector<int> > graph;
        for (int i = 0; i < numAristas; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        if (esBipartito(graph, numNodos)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
