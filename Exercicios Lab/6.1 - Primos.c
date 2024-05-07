#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main(int argc, char ** argv){
    
    int a, b, primo;
    
    scanf("%d %d", &a, &b);
    
    if(b > MAX){
        printf("Limite inválido");
        return 0;
    }
    
    for(int i = a; i < b; i++){
        primo = 1;
        for(int j = 2; j <= (i/2); j++){
            if(i % j == 0){
                primo = 0;
                break;
            }
        }
        
        if((primo == 1) && (i != 1)){
            printf("\n%d", i);
        }
    }
    return 0;
}