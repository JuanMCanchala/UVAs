/*
Segment Tree Implementation
Carlos Ramírez
Junio 8 de 2021

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>


//Segment tree is represented as a list
int n, MAXN = 100001;
int tree[200001];

//build the segment tree
void build(int *a, int v, int l, int r){
  if(l == r)
    tree[v] = a[l];
  else{
    int m = l + ((r - l) >> 1);
    build(a, v + 1, l, m);
    build(a, v + 2 * (m - l + 1), m + 1, r);
    tree[v] = tree[v + 1] + tree[v + 2 * (m - l + 1)];
  }
}

//sum query
int query(int v, int L, int R, int l, int r){
  int ans;

  if(l > r)
    ans = 0;
  else if(l == L && r == R)
    ans = tree[v];
  else{
    int m = L + ((R - L) >> 1);
    ans = query(v + 1, L, m, l, min(r, m)) + query(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r);
  }

  return ans;
}
     
//update query
void update(int v, int L, int R, int pos, int h){
  if(L == R)
    tree[v] = h;
  else{
    int m = L + ((R - L) >> 1);
    if(pos <= m)
      update(v + 1, L, m, pos, h);
    else
      update(v + 2 * (m - L + 1), m + 1, R, pos, h);
    tree[v] = tree[v + 1] + tree[v + 2 * (m - L + 1)];
  }
}

int main(){
  int a[] = {3, 6, 9, -5, 4, 2, 7}, i;
  build(a, 0, 0, 6);

  for(i = 0; i < 14; ++i)
    printf("%d ", tree[i]);
  printf("\n");

  printf("%d\n", query(0, 0, 6, 2, 5));
  printf("%d\n", query(0, 0, 6, 0, 4));
  update(0, 0, 6, 4, -2);

  for(i = 0; i < 14; ++i)
    printf("%d ", tree[i]);
  printf("\n");

  return 0;
}
