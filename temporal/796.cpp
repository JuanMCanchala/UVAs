
/*
Critical Links
https://uva.onlinejudge.org/external/7/796.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

int n, numSCC, t;
vector<vector<int> > adj(50000);
int visitado[50000];
int low[50000];
int padre[50000];
set<pair<int, int> > apAristas;

void bridgesAux(int);

void bridges(){
  for(int i = 0; i < n; i++)
    if(visitado[i] == -1)
      bridgesAux(i);
}

void bridgesAux(int v){
  int w;
  visitado[v] = low[v] = ++t;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      padre[w] = v;
      bridgesAux(w);
      low[v] = low[v] < low[w] ? low[v] : low[w];

      //verificar si es un puente
      if(low[w] > visitado[v]){
	if(v < w)
	  apAristas.insert(pair<int, int>(v, w));
	else
	  apAristas.insert(pair<int, int>(w, v));
      }
    }
    else if(w != padre[v])
      low[v] = low[v] < visitado[w] ? low[v] : visitado[w];
  }
}

void insertar(int x, int y){
  bool flag = false;

  for(vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it){
    if(y < *it){
      adj[x].insert(it, y);
      flag = true;
      break;
    }
  }

  if(!flag)
    adj[x].push_back(y);
}

int main(){
  int i, j, aux1, aux2, aux3;

  while(scanf("%d", &n) != EOF){
    apAristas.clear();
    
    for(i = 0; i < n; i++){
      scanf("%d (%d)", &aux1, &aux2);
      adj[aux1] = vector<int>();
      visitado[aux1] = low[aux1] = padre[aux1] = -1;

      for(j = 0; j < aux2; j++){
	scanf("%d", &aux3);
	adj[aux1].push_back(aux3);
	//adj[aux3].push_back(aux1);
      }
    }

    ap();

    printf("%d critical links\n", (int) apAristas.size());
    for(set<pair<int, int> >::iterator it = apAristas.begin(); it != apAristas.end(); ++it)
      printf("%d - %d\n", it->first, it->second);
    printf("\n");
  }
  
  return 0;
}