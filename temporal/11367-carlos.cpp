
/*
Full Tank?
https://uva.onlinejudge.org/external/113/11367.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

struct Nodo{
  int id, gas, total;
  
  Nodo(){}

  Nodo(int i, int g, int t){
    id = i;
    gas = g;
    total = t;
  }

  bool operator< (const Nodo& n) const{
    return total > n.total;
  }
};

int main(){
  int n, m, i, ini, fin, j, k, q, cap, w, aux;
  bool flag;
  vector<vector<pair<int, int > > > adj(1005);
  int costo[1005][105];
  vector<int> precio(1005);
  Nodo curr;
  
  scanf("%d %d", &n, &m);

  for(i = 0; i < n; ++i)
    scanf("%d", &precio[i]);

  for(i = 0; i < m; ++i){
    scanf("%d %d %d", &ini, &fin, &cap);
    adj[ini].push_back(make_pair(fin, cap));
    adj[fin].push_back(make_pair(ini, cap));
  }

  scanf("%d", &q);

  for(j = 0; j < q; ++j){
    scanf("%d %d %d", &cap, &ini, &fin);

    if(adj[ini].size() == 0 || adj[fin].size() == 0)
      printf("impossible\n");
    else{
      for(i = 0; i < n; ++i)
        for(k = 0; k <= cap; ++k)
	  costo[i][k] = -1;
      
      priority_queue<Nodo> cola;
      cola.push(Nodo(ini, 0, 0));
      costo[ini][0] = 0;
      flag = false;

      while(!cola.empty()){
	int gas, est, total, gasNuevo;
	curr = cola.top();
	est = curr.id;
	gas = curr.gas;
	total = curr.total;
        cola.pop();

	if(est == fin){
	  flag = true;
	  break;
	}

	//si el costo de llegar a la estacion actual con la gasolina actual es
	//mayor que el total en el nodo actual entonces tiene sentido seguir por ahi
	if(costo[est][gas] >= total){
	  // tanquear: se tanquea una unidad de gasolina
	  if(gas < cap && (costo[est][gas + 1] == -1 || total + precio[est] < costo[est][gas + 1])){
	    costo[est][gas + 1] = total + precio[est];
	    cola.push(Nodo(est, gas + 1, total + precio[est]));
	  }

	  for(i = 0; i < adj[est].size(); ++i){
	    w = adj[est][i].first;
	    aux = adj[est][i].second;
	    if(gas >= aux){
	      gasNuevo = gas - aux;
	      if(costo[w][gasNuevo] == -1 || total < costo[w][gasNuevo]){
		costo[w][gasNuevo] = total;
		cola.push(Nodo(w, gasNuevo, total));
	      }
	    }
	  }
	}
      }

      if(flag)
	printf("%d\n", curr.total);
      else
	printf("impossible\n");
    }
  }

  return 0;
}