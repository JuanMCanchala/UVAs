#include <stdio.h>

int main(){
    int time, velocity, temp, ans;
    while(scanf("%d %d", &time, &velocity)==2){
        temp = time * 2;
        ans = temp * velocity;
        printf("%d\n", ans);
    }
    return 0;
}