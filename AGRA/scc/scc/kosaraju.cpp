/*
Algoritmo de Kosaraju (SCC)
Autor: Carlos Ramirez
Fecha: Marzo 23 de 2020

En esta version se utiliza una lista en la cual se van agregando
los elementos al inicio mientras se realiza el primer recorrido.
Ademas, con esta implementacion se debe recorrer el arreglo sccInd
para saber cuantos SCC resultaron y los nodos que componen cada SCC.
 */

#include <vector>
#include <list>
#include <iostream>

using namespace std;

int n;
vector<vector<int> > adj(50000);
vector<vector<int> > adjT(50000);
bool visitados[50000];
list<int> ord;
int sccInd[50000];

void kosarajuAux(int);
void asignar(int, int);

void kosaraju(){
  int i;

  for(i = 0; i < n; i++)
    kosarajuAux(i);

  for(i = 0; i < n; i++)
    sccInd[i] = -1;

  for(list<int>::iterator it = ord.begin(); it != ord.end(); it++)
    asignar(*it, *it);
}

void kosarajuAux(int v){
  if(!visitados[v]){
    visitados[v] = true;
    
    for(int i = 0; i < adj[v].size(); i++)
      kosarajuAux(adj[v][i]);

    ord.push_front(v);
  }
}

void asignar(int u, int v){
  if(sccInd[u] == -1){
    sccInd[u] = v;

    for(int i = 0; i < adjT[u].size(); i++)
      asignar(adjT[u][i], v);
  }
}

int main(){
  int m, i, aux1, aux2;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2;
    adj[aux1].push_back(aux2);
    adjT[aux2].push_back(aux1);
  }

  kosaraju();

  for(i = 0; i < n; i++){
    cout << sccInd[i] << " ";
  }

  cout << endl;
  
  return 0;
}
