/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree (sum)
Range Query and Position Update

*/

#include <cstdio>
#include <cstdlib>
#include <vector>

int MAX = 1000;

int tree[1000];

void add(int, int, int);
int query(int);
int query(int, int);

//build
void build(int *a, int n){
  for(int i = 0; i < n; ++i)
    add(i, a[i], n);
}

//update the Fenwick tree
void add(int idx, int val, int n){
  while(idx < n){
    tree[idx] += val;
    idx = idx | (idx + 1); // f(x) = x | (x + 1)
  }
}

//simple query
int query(int r){
  int res = 0;
  while(r >= 0){
    res += tree[r];
    r = (r & (r + 1)) - 1; // r = g(x) - 1    g(x) = x & (x + 1)
  }
  return res;
}

//range query
int query(int l, int r){
  return query(r) - query(l - 1);
}

int main(){
  int i, n = 9;
  int a[] = {6, 1, 11, 9, 8, 7, -2, 4, 14};
  build(a, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  printf("%d\n", query(5));
  printf("%d\n", query(6));
  printf("%d\n", query(2, 6));
  add(5, 10, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  return 0;
}


