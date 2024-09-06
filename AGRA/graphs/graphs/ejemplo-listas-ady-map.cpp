
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

int main(){
  int i, n, u, j;
  string v, w;
  map< string, vector<string> > adj;

  cin >> n;
  
  for(i = 0; i < n; ++i){
    cin >> w >> u;
    adj[w] = vector<string>(u);
    for(j = 0; j < u; ++j){
      cin >> v;
      adj[w][j] = v;
    }
  }

  cout << "Grafo" << endl;


  for(map<string, vector<string>>::iterator it = adj.begin(); it != adj.end(); ++it){
    cout << "Nodo " << it->first << ":" << endl;
    for(i = 0; i < it->second.size(); ++i){
      cout << it->second[i] << endl;
    }
  }

  return 0;
}
