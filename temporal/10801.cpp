
/*
Lift Hopping
https://uva.onlinejudge.org/external/108/10801.pdf
*/

#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

struct Estado{
  int pos;
  int valor;
};

class Comparador{
  public:
    bool operator() (const Estado& p1, const Estado& p2) const{
      return p1.valor > p2.valor;
    }
};

int main(){
  int n, m, i, j, k, aux, val;
  string linea;
  vector<vector<int> > adj(500);
  int dist[500];
  int tiempoAsc[5];
  Estado est1, est2;
  bool flag;
  
  while(cin >> n >> m){
    set<int> pisos;
    fill(adj.begin(), adj.end(), vector<int>());
    
    for(i = 0; i < n; i++)
      cin >> tiempoAsc[i];
    cin.ignore();

    for(i = 0; i < n; i++){
      getline(cin, linea);

      vector<int> temp;
      stringstream tok(linea);

      while(tok >> aux){
	temp.push_back(aux);
	pisos.insert(aux);
      }

      //se conectan los pisos en los que para un mismo ascensor
      for(j = 0; j < temp.size(); j++)
	for(k = 0; k < temp.size(); k++)
	  if(j != k)
	    adj[(i * 100) + temp[j]].push_back((i * 100) + temp[k]);
    }

    //en todos los pisos en los que hay alguna parada se establece una
    //conexión entre los ascensores en el mismo piso
    for(set<int>::iterator it = pisos.begin(); it != pisos.end(); ++it){
      for(i = 0; i < n - 1; i++){
	for(j = i + 1; j < n; j++){
	  adj[(i * 100) + *it].push_back((j * 100) + *it);
	  adj[(j * 100) + *it].push_back((i * 100) + *it);
	}
      }

      for(i = 0; i < n; i++)
	dist[(i * 100) + *it] = 2100000000;
    }

    priority_queue<Estado, vector<Estado>, Comparador> cola;
    flag = false;

    //hay varios nodos iniciales, los nodos correspondientes al piso 0
    //para cada uno de los ascensores
    for(i = 0; i < n; i++){
      est1.pos = i * 100;
      est1.valor = dist[i * 100] = 0;
      cola.push(est1);
    }

    while(!cola.empty()){
      est1 = cola.top();
      cola.pop();

      if(est1.pos % 100 == m){
	flag = true;
	break;
      }

      if(est1.valor == dist[est1.pos]){
	for(i = 0; i < adj[est1.pos].size(); i++){
	  k = adj[est1.pos][i];

	  //conexión con pisos usando el mismo ascensor
	  if(est1.pos / 100 == k / 100){
	    aux = k / 100;
	    val = dist[est1.pos] + (fabs(est1.pos - k) * tiempoAsc[aux]);
	  }
	  // conexión con un ascensor en el mismo piso
	  else
	    val = dist[est1.pos] + 60;

	  if(val < dist[k]){
	    est2.pos = k;
	    est2.valor = val;
	    cola.push(est2);
	    dist[k] = val;
	  }
	}
      }
    }

    if(flag)
      cout << est1.valor << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}