
/*
Sub-dictionary
https://uva.onlinejudge.org/external/12/1229.pdf

Solution with SCC

*/

#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int n, numSCC;
map<string, vector<string> > adj;
map<string, vector<string> > adjT;
map<string, bool> visitados;
vector<string> ord;
map<string, int> sccInd;
vector<string> grupo;

void kosarajuAux(string);
void asignar(string, int);

void kosaraju(){
  for(map<string, bool>::iterator it = visitados.begin(); it != visitados.end(); it++)
    kosarajuAux(it->first);
  
  numSCC = 0;
  for(int i = ord.size() - 1; i >= 0; i--){
    if(sccInd[ord[i]] == -1){
      numSCC++;
      asignar(ord[i], numSCC);
    }
  }
}

void kosarajuAux(string v){
  if(!visitados[v]){
    visitados[v] = true;
    
    for(int i = 0; i < adj[v].size(); i++)
      kosarajuAux(adj[v][i]);

    ord.push_back(v);
  }
}

void asignar(string u, int v){
  sccInd[u] = v;

  for(int i = 0; i < adjT[u].size(); i++){
    if(sccInd[adjT[u][i]] == -1)
      asignar(adjT[u][i], v);
  }
}

void dfs(string w){
  visitados[w] = true;

  for(int i = 0; i < adj[w].size(); i++)
    if(!visitados[adj[w][i]])
      dfs(adj[w][i]);
}

int main(){
  int m, i, j, aux1, aux2;
  string cad, pal1, pal2;
  bool flag;
  
  cin >> n;
  cin.ignore();

  while(n != 0){
    adj.clear();
    adjT.clear();
    visitados.clear();
    sccInd.clear();
    ord.clear();
    grupo.clear();
    
    for(i = 0; i < n; i++){
      getline(cin, cad);

      stringstream tok(cad);
      tok >> pal1;

      if(adj.find(pal1) == adj.end())
	adj[pal1] = vector<string>();

      visitados[pal1] = false;
      sccInd[pal1] = -1;

      set<string> signif;

      while(tok >> pal2){
	if(signif.find(pal2) == signif.end()){
	  signif.insert(pal2);
	  adj[pal1].push_back(pal2);

	  if(adjT.find(pal2) == adjT.end())
	    adjT[pal2] = vector<string>();
	  
	  adjT[pal2].push_back(pal1);
	  visitados[pal2] = false;
	  sccInd[pal2] = -1;
	}
      }
    }
    
    kosaraju();

    vector<int> tams(numSCC + 1, 0);

    for(map<string, int>::iterator it = sccInd.begin(); it != sccInd.end(); it++)
       tams[it->second]++;

    for(map<string, bool>::iterator it = visitados.begin(); it != visitados.end(); it++)
      it->second = false;

    for(map<string, int>::iterator it = sccInd.begin(); it != sccInd.end(); it++){
      if(tams[it->second] > 1 && !visitados[it->first])
	dfs(it->first);
    }

    for(map<string, bool>::iterator it = visitados.begin(); it != visitados.end(); it++){
      if(it->second){
	flag = false;
	for(i = 0; i < grupo.size(); i++){
	  if(it->first < grupo[i]){
	    grupo.insert(grupo.begin() + i, it->first);
	    flag = true;
	    break;
	  } 
	}

	if(!flag)
	  grupo.push_back(it->first);
      }
    }

    cout << grupo.size() << endl;
    for(i = 0; i < grupo.size(); i++)
      cout << grupo[i] << ((i != grupo.size() - 1) ? " " : "\n");

    cin >> n;
    cin.ignore();
  }
  
  return 0;
}