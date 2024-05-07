#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 0 

int main(int argc, char**argv) {
   
   int x;
    
    scanf("%d", &x);
    
    //Descola bits para a esquerda (multiplica por 2 [10]) e direita(divide por 2[10])
    printf("%d\n %d", (x << 1), (x >> 1));

    return SUCESSO;
}