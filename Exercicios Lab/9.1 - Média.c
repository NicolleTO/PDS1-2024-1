#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

double sinal(double x);
void media(double vet[], int n, int *i);
 
int main(int argc, char** argv)
{
    int n;
    double *vet;
    int i = 0;
    
    scanf("%d", &n);
    
    vet = (double*)malloc(n*sizeof(double));

    for(int j = 0; j < n; j++){
        scanf("%lf", &vet[j]);
    }
    
    media(vet, n, &i);
    printf("%d", i);
    
    return SUCESSO;
}

/*-------------Funções--------------*/

double sinal(double x){
    if(x > 0){
        return x;
    }else{
        return x *(-1);
    }
}

void media(double vet[], int n, int *i){
    
    double media = 0.0, aux = 0.0, aux_new;
    
    for(int j = 0; j < n; j++){
        media += vet[j];
    }
    media /= n;

    aux = sinal(media - vet[0]);
   
    for(int j = 0; j < n; j++){
        
        aux_new = sinal(media - vet[j]);
        if(aux > aux_new){
            *i = j;
            aux = aux_new;
        }
    }
}
