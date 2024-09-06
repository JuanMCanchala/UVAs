#include <stdio.h>

void invertirSegmentos(int arr[], int n, int m){
    int i, j, aux, k;
    int bq = n/m;
    i = 0;
    while(i < bq){
        j = i * m;
        k = 0;
        while(k < m/2){
            aux = arr[j+k];
            arr[j+k] = arr[j + m - (k+1)];
            arr[j + m - (k + 1)] = aux;
            ++k;
        }
        ++i;
    }
}