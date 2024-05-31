#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void ler_dados(int vetor[], int n);
    
int main(int argc, char** argv)
{
    int linha, coluna, **vetor;
    
    scanf("%d %d", &linha, &coluna);
    vetor = (int**)malloc(linha*sizeof(int*));
    
    for(int i = 0; i < linha; i++){
        vetor[i] = (int*)malloc(coluna*sizeof(int));
        
        for(int j = 0; j < coluna; j++){
            scanf("%d", &vetor[i][j]);
        }
    }
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < linha; i++){
       free(vetor[i]);
    }
    free(vetor);
    return SUCESSO;
}
