#include <vector>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main(){
  map<string, int> id;
  vector<vector<int>> adj(6);
  id["pepito"] = 0;
  id["luisito"] = 1;
  id["martita"] = 2;
  id["juanito"] = 3;
  id["maria"] = 4;
  id["sofia"] = 5;

  int lista0[] = {2, 3};
  int lista1[] = {0, 2, 4};
  int lista2[] = {0, 4, 5};
  int lista3[] = {4, 5};
  int lista4[] = {1};
  int lista5[] = {3};

  adj[0] = vector<int>(lista0, lista0 + 2);
  adj[1] = vector<int>(lista1, lista1 + 3);
  adj[2] = vector<int>(lista2, lista2 + 3);
  adj[3] = vector<int>(lista3, lista3 + 2);
  adj[4] = vector<int>(lista4, lista4 + 1);
  adj[5] = vector<int>(lista5, lista5 + 1);

  return 0;
}
