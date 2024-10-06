
/*
Word Transformation
https://uva.onlinejudge.org/external/4/429.pdf
*/

#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct nodo{
	int dato;
	int valor;
};

typedef struct nodo Nodo;

vector<bool> visitados(200);
string palabras[200];
vector<vector<int> > grafo(200);

int bfs(int raiz, int obj){
	int total = 0, i;
	queue<Nodo> cola;
	Nodo nod, aux;
	nod.dato = raiz;
	nod.valor = 0;
	cola.push(nod);
	visitados[raiz] = true;

	while(!cola.empty()){
		aux = cola.front();
		cola.pop();

		if(obj == aux.dato){
			total = aux.valor;
			break;
		}

		for(i = 0; i < grafo[aux.dato].size(); i++){
			if(!visitados[grafo[aux.dato][i]]){
				Nodo nuevo;
				nuevo.dato = grafo[aux.dato][i];
				nuevo.valor = aux.valor + 1,
				cola.push(nuevo);
				visitados[nuevo.dato] = true;
			}
		}
	}

	return total;
}



int main(){
	string aux, aux2, aux3;

	int casos, i, j, k, total, temp, res;

	cin >> casos;

	while(casos--){
		i = 0;
		total = 0;
		cin >> aux;

		while(aux != "*"){
			grafo[i].clear();
			palabras[i++] = aux;
			cin >> aux;
			total++;
		}

		for(i = 0; i < total; i++){
			for(j = 0; j < total; j++){
				if(i != j && palabras[i].size() == palabras[j].size()){
					temp = 0;
					for(k = 0; k < palabras[i].size(); k++){
						if(palabras[i][k] != palabras[j][k])
							temp++;
						if(temp == 2)
							break;
					}

					if(temp < 2){
						grafo[i].push_back(j);
						grafo[j].push_back(i);
					}
				}
			}
		}

		cin.ignore();

		while(getline(cin, aux) && aux != ""){
			size_t pos = aux.find(" ");
			aux2 = aux.substr(0, pos);
			aux3 = aux.substr(pos + 1);
			fill(visitados.begin(), visitados.end(), false);

			string* it1 = find(palabras, palabras + total, aux2);
			string* it2 = find(palabras, palabras + total, aux3);
			res = bfs(it1 - palabras, it2 - palabras);
			cout << aux2 << " " << aux3 << " " << res << endl;
		}

		if(casos)
			cout << endl;
	}

	return 0;
}