#include <stdio.h>

int main()
{
    int arr[50];
    int i = 0, nCasos, suma = 0, temp, moves = 0, temp2 = 0, number = 1;
    while (scanf("%d", &nCasos) && nCasos != 0)
    {
        i = 0;
        suma = 0;
        temp = 0;
        moves = 0;
        temp2 = 0;
        while (i < nCasos)
        {
            scanf("%d", &arr[i]);
            suma += arr[i];
            i++;
        }
        temp = suma / nCasos;
        i = 0;
        while (i < nCasos)
        {
            if (temp > arr[i])
            {
                temp2 = temp - arr[i];
                moves += temp2;
            }
            i++;
        }
        printf("Set #%d\n", number);
        number++;
        printf("The minimum number of moves is %d.\n\n", moves);
    }
    return 0;
}
