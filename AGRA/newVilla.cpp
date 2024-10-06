/*
The New Villa
https://uva.onlinejudge.org/external/3/321.pdf

BFS - State Space

*/

#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct step{
  string desc; // can be on, off and move
  int hab;

  step(string d, int h){
    desc = d;
    hab = h;
  }
};

struct movimiento{
  int pos, conteo;
  vector<step> pasos;

  movimiento(){}

  movimiento(int p, int c){
    pos = p;
    conteo = c;
    pasos = vector<step>();
  }

  movimiento(int p, int c, vector<step> &pa){
    pos = p;
    conteo = c;
    pasos = pa;
  }
};

struct classcomp{
  bool operator() (const movimiento& mov1, const movimiento& mov2) const{
    bool ans = true;
    if(mov1.pos != mov2.pos)
      ans = mov1.pos < mov2.pos;
    else
      ans = mov1.conteo < mov2.conteo;
    return ans;
  }
};

int main(){
  map<movimiento, int, classcomp> dist;
  bool habAdy[11][11];
  bool lucesAdy[11][11];
  int r, d, s, i, j, ini, fin, caso = 1, obj;
  movimiento res;
  bool band;

  cin >> r >> d >> s;

  while(r != 0 || d != 0 || s != 0){
    obj = 1 << r - 1;
    for(i = 0; i < 11; i++){
      for(j = 0; j < 11; j++){
	habAdy[i][j] = lucesAdy[i][j] = false;
      }
    }
    dist.clear();
    band = false;

    for(i = 0; i < d; i++){
      cin >> ini >> fin;
      habAdy[ini][fin] = habAdy[fin][ini] = true;
    }

    for(i = 0; i < s; i++){
      cin >> ini >> fin;
      lucesAdy[ini][fin] = true;
    }

    queue<movimiento> cola;
    movimiento mov(1, 1), curr;
    dist[mov] = 0;
    cola.push(mov);

    while(!band && !cola.empty()){
      curr = cola.front();
      cola.pop();

      if(curr.pos == r && obj == curr.conteo){
	res = curr;
	band = true;
      }
      else{
	// verificar posibilidades de desplazarse a otra habitación
	for(i = 1; i <= r; i++){
	  // se verifica que haya un pasillo hacía la habitación i y que la luz en esa habitación esté
	  // encendida
	  if(habAdy[curr.pos][i] && ((curr.conteo & (1 << i - 1)) == (1 << i - 1))){
	    mov = movimiento(i, curr.conteo, curr.pasos);
	    mov.pasos.push_back(step("move", i));

	    if(dist.find(mov) == dist.end()){
	      cola.push(mov);
	      dist[mov] = dist[curr] + 1;
	    }
	  }
	}

	// verificar posibilidades de encender o apagar una luz en otra habitación
	for(i = 1; i <= r; i++){
	  // se verifica que haya un switch que permita encencer la luz de la habitación i
	  // y que no sea la misma habitación en la que se está ubicado
	  if(lucesAdy[curr.pos][i] && i != curr.pos){
	    mov = movimiento(curr.pos, (curr.conteo ^ (1 << i - 1)), curr.pasos);
	    mov.pasos.push_back(step((mov.conteo > curr.conteo) ? "on" : "off", i));

	    if(dist.find(mov) == dist.end()){
	      cola.push(mov);
	      dist[mov] = dist[curr] + 1;
	    }
	  }
	}
      }
    }

    printf("Villa #%d\n", caso++);

    if(band){
      printf("The problem can be solved in %d steps:\n", dist[res]);
      for(vector<step>::iterator itAux = res.pasos.begin(); itAux != res.pasos.end(); itAux++){
	if(itAux->desc == "on")
	  printf("- Switch on light in room %d.\n", itAux->hab);
	else if(itAux->desc == "off")
	  printf("- Switch off light in room %d.\n", itAux->hab);
	else
	  printf("- Move to room %d.\n", itAux->hab);
      }
    }
    else
      printf("The problem cannot be solved.\n");

    printf("\n");
    cin >> r >> d >> s;
  }

  return 0;
}