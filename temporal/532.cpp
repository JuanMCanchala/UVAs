
/*
Dungeon Master
https://uva.onlinejudge.org/external/5/532.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;

struct Pos{
	int level, row, column, value;

	Pos(){
	}

	Pos(int l, int r, int c, int v){
		level = l;
		row = r;
		column = c;
		value = v;
	}
};

int main(){
	int l, r, c, i, j, k, iniL, iniR, iniC, newL, newR, newC, total;
	char mundo[30][30][30];
	bool visitados[30][30][30];
	int changeL[] = {0, 0, 0, 0, 1, -1};
	int changeR[] = {0, 0, 1, -1, 0, 0};
	int changeC[] = {1, -1, 0, 0, 0, 0};
	Pos current;

	scanf("%d %d %d", &l, &r, &c);

	while(l != 0 || r != 0 || c != 0){
		for(i = 0; i < l; i++){
			for(j = 0; j < r; j++){
				scanf("%s", mundo[i][j]);

				for(k = 0; k < c; k++){
					visitados[i][j][k] = false;

					if(mundo[i][j][k] == 'S'){
						iniL = i;
						iniR = j;
						iniC = k;
					}
				}
			}
		}

		total = -1;
		queue<Pos> cola;
		cola.push(Pos(iniL, iniR, iniC, 0));
		visitados[iniL][iniR][iniC] = true;

		while(!cola.empty()){
			current = cola.front();
			iniL = current.level;
			iniR = current.row;
			iniC = current.column;
			cola.pop();

			if(mundo[iniL][iniR][iniC] == 'E'){
				total = current.value;
				break;
			}

			for(i = 0; i < 6; i++){
				newL = iniL + changeL[i];
				newR = iniR + changeR[i];
				newC = iniC + changeC[i];
				if(newL >= 0 && newR >= 0 && newC >= 0 && newL < l && newR < r && newC < c &&
				   mundo[newL][newR][newC] != '#' && !visitados[newL][newR][newC]){
					cola.push(Pos(newL, newR, newC, current.value + 1));
					visitados[newL][newR][newC] = true;
				}
			}
		}

		if(total == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", total);

		scanf("%d %d %d", &l, &r, &c);
	}

	return 0;
}