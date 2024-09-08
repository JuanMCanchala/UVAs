/*
Implementación Algoritmo Orden Topológico
Agosto 17 de 2023
*/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(vector<vector<int>>& G, vector<int>& inc) {
    queue<int> q;
    vector<int> topo;
    
    for(int i = 0; i < G.size(); ++i) {
        if(inc[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            --inc[v];
            if(inc[v] == 0) {
                q.push(v);
            }
        }
    }
    return topo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<int>> G(n);
    vector<int> inc(n, 0);

    for(int i = 0; i < n; ++i) {
        int u;
        scanf("%d", &u);
        for(int j = 0; j < u; ++j) {
            int v;
            scanf("%d", &v);
            G[i].push_back(v);
            ++inc[v];
        }
    }

    printf("Grafo\n");
    for(int i = 0; i < G.size(); ++i) {
        printf("Nodo %d:", i);
        for(int j = 0; j < G[i].size(); ++j) {
            printf(" %d", G[i][j]);
        }
        printf("\n");
    }

    printf("Ordenamiento Topológico:\n");
    vector<int> topo = topoSort(G, inc);

    for(int i = 0; i < topo.size(); ++i) {
        printf("%d ", topo[i]);
    }
    printf("\n");

    return 0;
}
