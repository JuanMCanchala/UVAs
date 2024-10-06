/*queen*/
/*
Nombre: Juan Manuel Canchala
Codigo: 8983809
Complejidad del algoritmo: Dado a que hay un unico ciclo en la solucion y el resto del mismo son if y else puedo concluir que la complejidad es de O(n) */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int X1, Y1, X2, Y2;
    int flag = 0; 

    while ( scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2) && !(X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0)) {

        int dx = abs(X2 - X1);
        int dy = abs(Y2 - Y1);
        if (X1 == X2 && Y1 == Y2) {
            printf("0\n");
        } else if (dx == dy || dx == 0 || dy == 0) {
            printf("1\n");
        } else {
            printf("2\n");
        }

    }

    return 0;
}
