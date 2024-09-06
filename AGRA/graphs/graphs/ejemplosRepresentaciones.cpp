
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  /*
  // representación listas de adyacencia
  vector<vector<int>> G(7);
  G[0].push_back(1);
  G[0].push_back(2);
  G[1].push_back(5);
  G[1].push_back(4);
  G[1].push_back(6);
  G[2].push_back(4);
  G[2].push_back(0);
  G[3].push_back(4);
  G[4].push_back(5);
  G[5].push_back(3);
  G[6].push_back(0);

  // representación matrices de adyacencia
  int G[][] = {{0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1},
	       {1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0},
	       {0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 0},
	       {1, 0, 0, 0, 0, 0, 0}};

  vector<pair<int, int>> G;
  G.push_back(make_pair(0, 1));
  G.push_back(make_pair(0, 2));
  G.push_back(make_pair(1, 5));
  G.push_back(make_pair(0, 4));
  // ...
  */

  int n, m, i, u, v, j;
  scanf("%d %d", &n, &m);
  vector<vector<int>> G(n);

  for(i = 0; i < m; ++i){
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
  }

  for(i = 0; i < n; ++i){
    for(j = 0; j < G[i].size(); ++j)
      printf("%d ", G[i][j]);
    printf("\n");
  }

  
  return 0;
}
