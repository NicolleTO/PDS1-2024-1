#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 0 

int main(int argc, char**argv) {
   
    int a, b, c, maior;
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    maior = a;
    
    if(b > a){
        maior = b;
    } 
    
    if(c > b){
        maior = c;
    }
    
    printf("%d", maior);
    
    return SUCESSO;
}