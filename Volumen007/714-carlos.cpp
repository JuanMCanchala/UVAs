/*
Copying Books
https://onlinejudge.org/external/7/714.pdf

Binary Search

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

int f(int v, int k, vector<int> &A){
  int total = 0, ac = 0, i = 0;
  while(i < A.size() && total < k){
    if(ac + A[i] <= v){
      ac += A[i];
      i += 1;
    }
    else{
      total += 1;
      ac = 0;
    }
  }
  return total;
}

int solve(vector<int> &A, int k){
  long long l = 0, r = 0, i, mid;
  for(i = 0; i < A.size(); ++i)
    r += A[i];
  while(r - l > 1){
    mid = (l + r) / 2;
    if(f(mid, k, A) >= k)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

void printSol(int ans, vector<int> &A, int k, int m){
  int i = m - 1, ac = 0, j;
  deque<int> curr;
  deque<string> lts;
  string aux;
  
  while(i >= 0){
    if(ac + A[i] <= ans && i + 1 >= k){
      ac += A[i];
      curr.push_front(A[i]);
      i -= 1;
    }
    else{
      aux = to_string(curr[0]);
      curr.pop_front();
      while(!curr.empty()){
	aux += " " + to_string(curr.front());
	curr.pop_front();
      }
      lts.push_front(aux);
      ac = 0;
      k -= 1;
    }
  }

  if(!curr.empty()){
    aux = to_string(curr[0]);
    curr.pop_front();
    while(!curr.empty()){
      aux += " " + to_string(curr.front());
      curr.pop_front();
    }
    lts.push_front(aux);
  }

  cout << lts[0];
  for(i = 1; i < lts.size(); ++i)
    cout << " / " << lts[i];
  cout << endl;
}

int main(){
  int cases, m, k, i, aux, ans;
  vector<int> A;
  cin >> cases;
  while(cases-- > 0){
    A.clear();
    cin >> m >> k;
    for(i = 0; i < m; ++i){
      cin >> aux;
      A.push_back(aux);
    }
    ans = solve(A, k);
    printSol(ans, A, k, m);
  }

  return 0;
}