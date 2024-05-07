#include <stdio.h>

#define SUCESSO 0
#define MAX 10

int main(int argc, char**argv)
{
    int vetor[MAX], inverso[MAX], j;
    
    for(int i = 0; i < MAX; i++){
        scanf("%d", &vetor[i]);
    }
    
    j = MAX - 1;
    for(int i = 0; i < MAX; i++){
        inverso[j] = vetor[i];
        j--;
    }
    
    printf("\n");
    
    for(int i = 0; i < MAX; i++){
        printf("%d\n", inverso[i]);
    }
 
    return SUCESSO;
}

