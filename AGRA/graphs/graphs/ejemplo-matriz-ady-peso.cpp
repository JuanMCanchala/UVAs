#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

int main(){
  int n, m, u, v, i, j, p;
  int adj[10][10]; // = {INT_MAX};

  cin >> n;

  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      adj[i][j] = INT_MAX;

  for(i = 0; i < n; ++i){
    cin >> u;
    for(j = 0; j < u; ++j){
      cin >> v >> p;
      adj[i][v] = p;
    }
  }
 
  cout << "Grafo" << endl;

  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j)
      cout << adj[i][j] << " ";
    cout << endl;
  }

  return 0;
}
