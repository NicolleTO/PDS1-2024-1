#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

int main(int argc, char** argv)
{
    int *vet1, *vet2, *vet3;
    int n, i;
   
    scanf("%d", &n);
   
    vet1 = (int*)malloc(n*sizeof(int));
    vet2 = (int*)malloc(n*sizeof(int));
    vet3 = (int*)malloc(n*sizeof(int));
    
    for (i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
    }
    for (i = 0; i < n; i++){
        scanf("%d", &vet2[i]);
    }
    for (i = 0; i < n; i++){
        vet3[i] = vet1[i] + vet2[i];
    }
    
    for (i = 0; i < n; i++){
        printf("%d\n", vet3[i]);
        
    }
    free(vet1);
    free(vet2);
    free(vet3);
    return SUCESSO;
}
