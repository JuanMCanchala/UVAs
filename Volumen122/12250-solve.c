#include <stdio.h>
#include <string.h>

int main(){
    int Ncase = 1, j = 0;
    char palabras[100] = " ";
    
    while(strcmp(palabras, "#") != 0){
        scanf("%s", palabras);
        if(strcmp(palabras, "HELLO") == 0){
            printf("Case %d: %s", Ncase, "ENGLISH\n");
        }else if(strcmp(palabras, "HOLA") == 0){
            printf("Case %d: %s", Ncase, "SPANISH\n");
        }else if(strcmp(palabras, "HALLO") == 0){
            printf("Case %d: %s", Ncase, "GERMAN\n");
        }else if(strcmp(palabras, "BONJOUR") == 0){
            printf("Case %d: %s", Ncase, "FRENCH\n");
        }else if(strcmp(palabras, "CIAO") == 0){
            printf("Case %d: %s", Ncase, "ITALIAN\n");
        }else if(strcmp(palabras, "ZDRAVSTVUJTE") == 0){
            printf("Case %d: %s", Ncase, "RUSSIAN\n");
        }else if(strcmp(palabras, "#") != 0){
            printf("Case %d: %s",Ncase, "UNKNOWN\n");
        }
        Ncase++;
        j++;
    }
    
    return 0;
}