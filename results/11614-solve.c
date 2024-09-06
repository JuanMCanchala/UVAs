#include <stdio.h>
#include <math.h>
int main(){
    int numCasos,  i;
    long long int temp, caso, raiz;

    scanf("%d", &numCasos);

    for(i=0; i < numCasos; i++){
        scanf("%lld", &caso);
        raiz = floor(sqrt(caso * 2));
        temp = (raiz * (raiz + 1)) / 2;
        if(temp > caso)
        raiz = raiz - 1;
        printf("%lld\n", raiz);
    }
    return 0;
}