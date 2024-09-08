
/*
Maze Exploration
https://uva.onlinejudge.org/external/7/784.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int n, m;
char c;
char tablero[31][85];
int visitados[31][85];
int cambioX[] = {-1, 0, 1, 0};
int cambioY[] = {0, 1, 0, -1};

void dfsAux(int x, int y){
  int i, newX, newY;
  tablero[x][y] = '#';
  visitados[x][y] = 1;
  m = strlen(tablero[x]);

  for(i = 0; i < 4; ++i){
    newX = x + cambioX[i];
    newY = y + cambioY[i];

    if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visitados[newX][newY] && tablero[newX][newY] == ' ')
      dfsAux(newX, newY);
  }
}

int main(){
  int i, j, casos, iniX, iniY;
  char linea[85];

  scanf("%d\n", &casos);
  
  while(casos--){
    i = 0;
    fgets(tablero[i++], 85, stdin);
    tablero[i - 1][strlen(tablero[i - 1]) - 1] = '\0';
    
    while(tablero[i - 1][0] != '_'){
      for(j = 0; j < strlen(tablero[i - 1]); j++){
	visitados[i - 1][j] = 0;
	if(tablero[i - 1][j] == '*'){
	  iniX = i - 1;
	  iniY = j;
	}
      }

      fgets(tablero[i++], 85, stdin);
      tablero[i - 1][strlen(tablero[i - 1]) - 1] = (tablero[i - 1][strlen(tablero[i - 1]) - 1] == '\n') ? '\0' : tablero[i - 1][strlen(tablero[i - 1]) - 1];
    }

    n = i;
    dfsAux(iniX, iniY);
    for(i = 0; i < n; i++){
      printf("%s\n", tablero[i]);
    }
  }

  return 0;
}