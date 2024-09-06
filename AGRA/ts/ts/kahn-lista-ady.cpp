#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int MAX = 10000;
int n, t = 0;
vector<vector<int>> adj(MAX);
vector<int> inc(MAX, 0);
vector<int> topo;

int main(){
  int m, u, v, i, j, vis = 0;
  queue<int> cola;
  cin >> n >> m;

  for(i = 0; i < n; ++i){
    cin >> u;
    adj[i].resize(u);
    for(j = 0; j < u; ++j){
      cin >> v;
      adj[i][j] = v;
      ++inc[v];
    }
  }

  cout << "Grafo" << endl;

  for(i = 0; i < n; ++i){
    cout << "Nodo " << i << ":";
    for(j = 0; j < adj[i].size(); ++j)
      cout << " " << adj[i][j];
    cout << endl;
  }

  cout << "Ordenamiento topológico" << endl;

  for(i = 0; i < n; ++i)
    if(inc[i] == 0)
      cola.push(i);

  while(!cola.empty()){
    v = cola.front();
    cola.pop();
    topo.push_back(v);

    for(i = 0; i < adj[v].size(); ++i){
      u = adj[v][i];
      --inc[u];
      if(inc[u] == 0)
	cola.push(u);
    }

    ++vis;
  }

  if(vis != n)
    printf("Hay un ciclo\n");
  else{
    for(i = 0; i < n; ++i)
      printf("%d%c", topo[i], (i == n - 1) ? '\n' : ' ');
  }

  return 0;
}
