
/*
Babel
https://uva.onlinejudge.org/external/114/11492.pdf

Shortest Path (Dijkstra)

*/

#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct Estado{
  string lenguaje;
  int letra;
  int costo;

  Estado(){}

  Estado(string leng, int l, int c){
    lenguaje = leng;
    letra = l;
    costo = c;
  }
};

struct Nodo{
  string palabra, lenguaje;

  Nodo(){}
  
  Nodo(string pal, string l){
    palabra = pal;
    lenguaje = l;
  }
};

class Comparador{
  public:
    bool operator() (const Estado& p1, const Estado& p2) const{
      return p1.costo > p2.costo;
    }
};

int main(){
  int m, i, j, costoAct, letraAct, letraNueva, res;
  string leng1, leng2, palabra, inicial, fin, lengAct;
  map<string, vector<Nodo> > adj;
  map<string, vector<int> > costos;
  Estado curr, oth;
  Nodo nodo;

  cin >> m;

  while(m != 0){
    adj.clear();
    costos.clear();    
    cin >> inicial >> fin;

    for(i = 0; i < m; i++){
      cin >> leng1 >> leng2 >> palabra;

      if(adj.find(leng1) == adj.end()){
	adj[leng1] = vector<Nodo>();
	costos[leng1] = vector<int>(27, -1);
      }
      if(adj.find(leng2) == adj.end()){
	adj[leng2] = vector<Nodo>();
	costos[leng2] = vector<int>(27, -1);
      }

      adj[leng1].push_back(Nodo(palabra, leng2));
      adj[leng2].push_back(Nodo(palabra, leng1));
    }

    if(adj.find(inicial) == adj.end() || adj.find(fin) == adj.end() || inicial == fin)
      cout << "impossivel" << endl;
    else{
      priority_queue<Estado, vector<Estado>, Comparador> cola;
      curr = Estado(inicial, 26, 0);
      cola.push(curr);
      costos[inicial][26] = 0;

      while(!cola.empty()){
	curr = cola.top();
	lengAct = curr.lenguaje;
	letraAct = curr.letra;
	costoAct = curr.costo;
	cola.pop();

	if(costos[lengAct][letraAct] == costoAct){
	  for(i = 0; i < adj[lengAct].size(); ++i){
	    nodo = adj[lengAct][i];
	    leng2 = nodo.lenguaje;
	    palabra = nodo.palabra;
	    letraNueva = palabra[0] - 'a';

	    if(letraAct != letraNueva && (costos[leng2][letraNueva] == - 1 || costoAct + palabra.size() < costos[leng2][letraNueva])){
	      costos[leng2][letraNueva] = costoAct + palabra.size();
	      cola.push(Estado(leng2, letraNueva, costos[leng2][letraNueva]));
	    }
	  }
	}
      }

      res = -1;
      for(i = 0; i < 27; ++i)
	if(costos[fin][i] != -1 && (res == -1 || costos[fin][i] < res))
	  res = costos[fin][i];

      if(res != -1)
	cout << res << endl;
      else
	cout << "impossivel" << endl;
    }

    cin >> m;
  }

  return 0;
}