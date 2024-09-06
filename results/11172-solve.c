#include <stdio.h>

int main(){
int casos, i = 0, numero1, numero2;
scanf("%d",&casos);
while(i < casos){
    scanf("%d %d",&numero1, &numero2);
    if(numero1 > numero2){
        printf("%s\n", ">");
    }else if(numero1 < numero2){
        printf("%s\n", "<");
    }else if(numero1 == numero2){
        printf("%s\n", "=");
    }
i++;
}
return 0;
}