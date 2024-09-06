#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, m, u, v, i, j;
  int adj[10][10] = {0};

  cin >> n;

  for(i = 0; i < n; ++i){
    cin >> u;
    for(j = 0; j < u; ++j){
      cin >> v;
      adj[i][v] = 1;
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
