/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree (sum)
Range Query and Position Update

*/

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class FenwickTree{
   private:
     vector<int> T;
  int n;

   public:
     // //build (version O(n log n)
     // FenwickTree(vector<int> &A){
     //   n = A.size();
     //   T.assign(n, 0);
     //   for(int i = 0; i < n; ++i)
     // 	 add(i, A[i]);
     // }

     //build (version O(n)
     FenwickTree(vector<int> &A){
       int i, r;
       n = A.size();
       T.assign(n, 0);
       for(i = 0; i < n; ++i){
	 T[i] += A[i];
	 r = i | (i + 1);
	 if(r < n)
	   T[r] += T[i];
       }
     }

     //update the Fenwick tree
     void add(int idx, int val){
       while(idx < n){
	 T[idx] += val;
	 idx = idx | (idx + 1); // f(x) = x | (x + 1)
       }
     }

     //simple query
     int query(int r){
       int res = 0;
       while(r >= 0){
	 res += T[r];
	 r = (r & (r + 1)) - 1; // r = g(x) - 1    g(x) = x & (x + 1)
       }
       return res;
     }

     //range query
     int query(int l, int r){
       return query(r) - query(l - 1);
     }

     void print(){
       for(int i = 0; i < n; ++i)
	 printf("%d%c", T[i], (i == n - 1) ? '\n' : ' ');
     }
};

int main(){
  int i, n = 9;
  vector<int> a = {6, 1, 11, 9, 8, 7, -2, 4, 14};
  FenwickTree tree(a);

  tree.print();
  printf("%d\n", tree.query(5));
  printf("%d\n", tree.query(6));
  printf("%d\n", tree.query(2, 6));
  tree.add(5, 10);

  tree.print();

  return 0;
}


