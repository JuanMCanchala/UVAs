#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, m, u, v, i, j;
  vector<pair<int, int>> adj;

  cin >> n >> m;

  for(i = 0; i < n; ++i){
    cin >> u;
    for(j = 0; j < u; ++j){
      cin >> v;
      adj.push_back(make_pair(i, v));
    }
  }

  cout << "Grafo" << endl;

  for(i = 0; i < adj.size(); ++i)
    cout << adj[i].first << " " << adj[i].second << endl;

  return 0;
}
