/*
Autor: Oscar Vargas Pabon

un ejemplo sobre como leer grafos

Esto asume una entrada generica como las que muchas veces se utiliza
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

void readAdj(){
	int V, E;
	cin >> V >> E;
	vector<list<int>> graph( V );
	for ( int i = 0 ; i < E ; ++i ) {
		int u, v;
		cin >> u >> v;
		// leemos la arista (u,v)
		graph[u].push_back( v );
		// si es un no-dirigido:
		// graph[v].push_back( u );
	}
}

void readAdjWeight(){
	int V, E;
	cin >> V >> E;
	vector<list<pair<int,int>>> graph( V );
	for ( int i = 0 ; i < E ; ++i ) {
		int u, v, w;
		cin >> u >> v >> w;
		// leemos la arista (u,v) donde w(u,v) = w
		graph[u].push_back( pair<int,int>( v, w ) );
		// si es un no-dirigido:
		// graph[v].push_back( pair<int,int>( u, w ) );
	}
}

int main(){
	readAdj();
	readAdjWeight();
	return 0;
}