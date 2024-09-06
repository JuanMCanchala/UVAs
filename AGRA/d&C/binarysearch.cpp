¡Nuevo! Combinaciones de teclas … Las combinaciones de teclas de Drive se han actualizado para que puedas navegar escribiendo las primeras letras
/*
Algoritmo DyC para búsqueda de un elemento en un arreglo ordenado (búsqueda binaria) y algoritmo de bisección.
Curso Árboles y Grafos 2024-2
Agosto 9 de 2024

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

// algoritmo recursivo
bool solve(int l, int r, vector<int> &A, int v){
  bool ans;
  int mid;
  if(r - l == 1)
    ans = A[l] == v;
  else{
    mid = l + ((r - l) >> 1);
    if(v < A[mid])
      ans = solve(l, mid, A, v);
    else
      ans = solve(mid, r, A, v);
  }
  return ans;
}

// algoritmo iterativo
bool solve(vector<int> &A, int v){
  bool ans;
  int mid;
  int l = 0, r = A.size();
  while(r - l != 1){
    mid = l + ((r - l) >> 1);
    if(v < A[mid])
      r = mid;
    else
      l = mid;
  }
  ans = A[l] == v;
  return ans;
}

double EPS = 1e-6;

// f(x) = x^2 + x - 3
double f(double x){
  return 2 * x * x - 10 * x - 3;
}

double biseccion(int v, int a, int b){
  double l = a, r = b;
  double ans, mid;
  while(fabs(r - l) > EPS){
    mid = (l + r) / 2;
    if(v <= f(mid))
      r = mid;
    else
      l = mid;
  }
  ans = l;
  return ans;
}

int main(){
  int aux = 56;
  vector<int> v1 = {2, 11, 15, 18, 20, 25, 29, 29, 35, 45, 48, 56, 68, 78, 90, 101};

  if(solve(0, v1.size(), v1, aux))
    printf("El número %d si está en el vector v1.\n", aux);
  else
    printf("El número %d no está en el vector v1.\n", aux);

  if(solve(v1, aux))
    printf("El número %d si está en el vector v1.\n", aux);
  else
    printf("El número %d no está en el vector v1.\n", aux);

  aux = 47;
  if(solve(0, v1.size(), v1, aux))
    printf("El número %d si está en el vector v1.\n", aux);
  else
    printf("El número %d no está en el vector v1.\n", aux);

  if(solve(v1, aux))
    printf("El número %d si está en el vector v1.\n", aux);
  else
    printf("El número %d no está en el vector v1.\n", aux);

  return 0;
}