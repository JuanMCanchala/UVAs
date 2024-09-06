#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int MAX = 10000;
int n, t = 0;
vector<vector<int>> adj(MAX);
vector<int> visitado(MAX), pred(MAX), f(MAX), d(MAX);
vector<int> topo;

// 0 = no visitado, 1 = visitado pero no completado, 2 = completado
void topoSort(int v){
  int u, i;
  d[v] = ++t;
  visitado[v] = 1;
  //printf("%d\n", v);

  for(i = 0; i < adj[v].size(); ++i){
    u = adj[v][i];
    if(visitado[u] == 0){
      pred[u] = v;
      topoSort(u);
    }
  }

  visitado[v] = 2;
  f[v] = ++t;
  topo.push_back(v);
}

void topoSortAux(){
  int i;
  
  for(i = 0; i < n; ++i){
    visitado[i] = 0;
    pred[i] = -1;
  }
  
  for(i = 0; i < n; ++i){
    if(visitado[i] == 0)
      topoSort(i);
  }
}

int main(){
  int m, u, v, i, j;
  cin >> n >> m;

  for(i = 0; i < n; ++i){
    cin >> u;
    adj[i].resize(u);
    for(j = 0; j < u; ++j)
      cin >> adj[i][j];
  }

  cout << "Grafo" << endl;

  for(i = 0; i < n; ++i){
    cout << "Nodo " << i << ":";
    for(j = 0; j < adj[i].size(); ++j)
      cout << " " << adj[i][j];
    cout << endl;
  }

  cout << "Ordenamiento topológico" << endl;
  topoSortAux();

  for(i = n - 1; i >= 0; --i)
    printf("%d%c", topo[i], (i == 0) ? '\n' : ' ');

  return 0;
}
