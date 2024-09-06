#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;
int adj[1000][1000];
bool visitados[1000];

void bfsAux(int v){
  int u, i;
  queue<int> cola;
  visitados[v] = true;
  cola.push(v);

  while(!cola.empty()){
    u = cola.front();
    printf("%d\n", u);
    cola.pop();

    for(i = 0; i < n; ++i){
      if(adj[u][i] && !visitados[i]){
	visitados[i] = true;
	cola.push(i);
      }
    }
  }
}

void bfs(){
  int i;

  //fill(visitados, visitados + n, false);
  for(i = 0; i < n; ++i)
    visitados[i] = false;

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
    for(j = 0; j < u; ++j){
      cin >> v;
      adj[i][v] = 1;
    }
  }

  cout << "Grafo" << endl;

  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j)
      cout << adj[i][j] << " ";
    cout << endl;
  }

  return 0;
}
