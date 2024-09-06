/*reverse and add*/
#include <stdio.h>

int main() {
    int i;
    int numCasos;
    scanf("%d", &numCasos);

    for (i = 0; i < numCasos; i++) {
        unsigned long caso;
        scanf("%lu", &caso);

        unsigned long ciclos = 0;
        unsigned long inverso = 0;
        unsigned long temp;

        int esPalindromo = 0;

        do { 
            temp = caso;
            inverso = 0;

            while (temp != 0) {
                inverso = inverso * 10 + temp % 10;
                temp /= 10;
            }

            if (caso == inverso) {
                esPalindromo = 1;
            } else {
                caso += inverso;
                ciclos++;
            }
        } while (!esPalindromo);

        printf("%lu %lu\n", ciclos, caso);
    }

    return 0;
}
