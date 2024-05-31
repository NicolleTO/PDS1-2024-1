#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void imprime (int vetor[], int n); 
void multiplica (int vetor[], int n, double v); 
 
int main(int argc, char** argv)
{
    int n, *vetor;
    double v;
    
    scanf("%d", &n);
    vetor = (int*)malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    
    scanf("%lf", &v);
    
    imprime(vetor, n);
    multiplica(vetor, n, v);
    imprime(vetor, n);
    multiplica(vetor, n, (1/v));
    imprime(vetor, n);
    
    return SUCESSO;
}

/*--------Funções--------*/

void imprime (int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void multiplica (int vetor[], int n, double v){
    
    for(int i = 0; i < n; i++){
        vetor[i] *= v;
    }
}
