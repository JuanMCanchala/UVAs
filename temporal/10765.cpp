/*
Doves and Bombs
https://uva.onlinejudge.org/external/107/10765.pdf

Articulation Points

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int n, t;
vector<vector<int> > adj(10001);
int visitado[10001];
int low[10001];
int padre[10001];
vector<pair<int, int> > comp(10001);
//set<int> apNodos;

void apAux(int);

void ap(){
  int i;

  for(i = 0; i < n; i++)
    low[i] = visitado[i] = padre[i] =-1;

  for(i = 0; i < n; i++)
    if(visitado[i] == -1)
      apAux(i);
}

void apAux(int v){
  int w, numHijos = 0;
  visitado[v] = low[v] = ++t;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      numHijos++;
      padre[w] = v;
      apAux(w);
      low[v] = low[v] < low[w] ? low[v] : low[w];

      //verificar si es un punto de articulacion
      if(padre[v] != -1 && low[w] >= visitado[v])
	comp[v].second++;
    }
    else if(w != padre[v])
      low[v] = low[v] < visitado[w] ? low[v] : visitado[w];
  }

  if(padre[v] == -1 && numHijos > 1)
    comp[v].second = numHijos;
}

bool compare(pair<int, int> &p1, pair<int, int> &p2){
  if(p1.second != p2.second)
    return p1.second > p2.second;
  else
    return p1.first < p2.first;
}

int main(){
  int m, i, aux1, aux2;

  cin >> n >> m;
  
  while(n != 0 || m != 0){
    t = 0;
    for(i = 0; i < n; ++i){
      adj[i].clear();
      visitado[i] = low[i] = padre[i] = -1;
      comp[i] = make_pair(i, 1);
    }
    
    cin >> aux1 >> aux2;
    while(aux1 != -1 && aux2 != -1){
      adj[aux1].push_back(aux2);
      adj[aux2].push_back(aux1);
      cin >> aux1 >> aux2;
    }

    ap();
    sort(comp.begin(), comp.begin() + n, compare);

    i = 0;
    for(vector<pair<int, int> >::iterator it = comp.begin(); it != comp.begin() + n && i < m; ++it, ++i)
      cout << it->first << " " << it->second << endl;
    cout << endl;

    cin >> n >> m;
  }
  
  return 0;
}