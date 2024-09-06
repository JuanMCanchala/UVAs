#include <stdio.h>
/*T = casos, three integers, N jugadores, K Jugador inicial,
P se hacen 5 pases*/
int main()
{
    int i = 0, T, N, K, P, ans, number = 1, j = 0, temp;
    scanf("%d", &T);     
    while (j < T)        
    {                   
        scanf("%d %d %d", &N, &K, &P);
        ans = (K - 1 + P) % N + 1;

        printf("Case %d: %d\n", number, ans);
        number++;
        j++;
    }
    return 0;
}