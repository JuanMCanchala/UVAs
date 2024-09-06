#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;
vector<vector<int>> adj(10000);
bool visitados[1000];
int p[1000];

void bfsAux(int v){
  int u, w, i;
  queue<int> cola;
  visitados[v] = true;
  cola.push(v);

  while(!cola.empty()){
    w = cola.front();
    printf("%d\n", w);
    cola.pop();

    for(i = 0; i < adj[w].size(); ++i){
      v = adj[w][i];
      if(!visitados[v]){
	visitados[v] = true;
	//p[v] = u;
	cola.push(v);
      }
    }
  }
}

void bfs(){
  int i;

  //fill(visitados, visitados + n, false);
  for(i = 0; i < n; ++i){
    visitados[i] = false;
    //p[i] = -1;
  }

  for(i = 0; i < n; ++i){
    if(!visitados[i])
      bfsAux(i);
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

  cout << "BFS:" << endl;
  bfs();

  return 0;
}
