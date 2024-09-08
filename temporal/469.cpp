
/*
Wetlands of Florida
https://uva.onlinejudge.org/external/4/469.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Flood fill

int n, m, total;
char tablero[105][105];
int visitados[105][105];
int cambioX[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int cambioY[] = {0, 1, 0, -1, -1, 1, -1, 1};

void dfsAux(int x, int y){
  int i, newX, newY;

  for(i = 0; i < 8; i++){
    newX = x + cambioX[i];
    newY = y + cambioY[i];
    if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visitados[newX][newY] && tablero[newX][newY] == 'W'){
      total++;
      visitados[newX][newY] = 1;
      dfsAux(newX, newY);
    }
  }
}

int main(){
  int casos, cont = 1, j, k, iniX, iniY, ini = 1;
  char linea[105];
  
  scanf("%d\n", &casos);
  
  while(casos--){
    if(ini)
      ini = 0;
    else
      printf("\n");
    
    n = 0;
    while(fgets(linea, 101, stdin) && linea[1] != '\0'){
      linea[strlen(linea) - 1] = '\0';
      
      if(linea[0] == 'W' || linea[0] == 'L')
	sscanf(linea, "%s", tablero[n++]);
      else{
	for(k = 0; k < n; k++)
	  for(j = 0; j < strlen(tablero[0]); j++)
	    visitados[k][j] = 0;
	
	sscanf(linea, "%d %d", &iniX, &iniY);
	visitados[iniX - 1][iniY - 1] = 1;
	total = 1;
	m = strlen(tablero[0]);	
	dfsAux(iniX - 1, iniY - 1);
	printf("%d\n", total);
      }
    }
  }

  return 0;
}