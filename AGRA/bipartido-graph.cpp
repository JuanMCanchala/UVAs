#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int INF = -1;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int> > graph(V); 

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int start = 0; 
    queue<int> q;
    q.push(start);
    vector<int> color(V, INF); 
    color[start] = 0;
    bool esBipartido = true;

    while (!q.empty() && esBipartido) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < graph[u].size(); j++){
            int v = graph[u][j];
            if (color[v] == INF) {
                color[v] = 1 - color[u]; 
                q.push(v);
            } else if (color[v] == color[u]) { 
                esBipartido = false;
            }
            if (!esBipartido) {
                j = graph[u].size(); 
            }
        }
    }
    return 0;
}
