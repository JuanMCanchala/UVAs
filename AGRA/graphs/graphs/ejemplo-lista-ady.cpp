#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, m, u, v, i, j;
  //map<string, int> id;
  vector<vector<int>> adj(20);
  //vector<vector<pair<int, int>>> adj(20);
  
  cin >> n;

  for(i = 0; i < n; ++i){
    cin >> u;
    adj[i].resize(u);
    for(j = 0; j < u; ++j)
      cin >> adj[i][j];
  }

  cout << "Grafo" << endl;

  for(i = 0; i < n; ++i){
    cout << "Nodo " << i << ":";
    for(j = 0; j < adj[i].size(); ++j)
      cout << " " << adj[i][j];
    cout << endl;
  }

  return 0;
}
