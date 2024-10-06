/*Bin*/
#include <stdio.h>

int main() {
    int i; 
    int b1, g1, c1, b2, g2, c2, b3, g3, c3; 

    while (scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) == 9) {
        int movements[6];

        movements[0] = b2 + b3 + c1 + c3 + g1 + g2; 
        movements[1] = b2 + b3 + g1 + g3 + c1 + c2; 
        movements[2] = c2 + c3 + b1 + b3 + g1 + g2; 
        movements[3] = c2 + c3 + g1 + g3 + b1 + b2; 
        movements[4] = g2 + g3 + b1 + b3 + c1 + c2;
        movements[5] = g2 + g3 + c1 + c3 + b1 + b2; 
        int min = movements[0];
        int caso = 0;

        for (i = 1; i < 6; i++) {
            if (movements[i] < min) {
                min = movements[i];
                caso = i;
            }
        }

        if (caso == 0) {
            printf("BCG %d\n", min);
        } else if (caso == 1) {
            printf("BGC %d\n", min);
        } else if (caso == 2) {
            printf("CBG %d\n", min);
        } else if (caso == 3) {
            printf("CGB %d\n", min);
        } else if (caso == 4) {
            printf("GBC %d\n", min);
        } else if (caso == 5) {
            printf("GCB %d\n", min);
        }
    }

    return 0;
}
