#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void ler_dados(int vetor[], int n);
    
int main(int argc, char** argv)
{
    int n, *vetor;
    
    scanf("%d", &n);
    vetor = (int*)malloc(n*sizeof(int));
    
    ler_dados(vetor, n);
    
    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }
    
    free(vetor);
    return SUCESSO;
}

/*--------Funções--------*/

void ler_dados(int vetor[], int n){
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
}
