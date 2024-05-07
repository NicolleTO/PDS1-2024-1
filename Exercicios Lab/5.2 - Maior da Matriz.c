#include <stdio.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char**argv)
{
    int matriz[MAX][MAX], quant_linhas, quant_colunas, maior;
    
    scanf("%d", &quant_linhas);
    scanf("%d", &quant_colunas);
    
    for(int i = 0; i < quant_linhas; i++){
        for(int j = 0; j < quant_colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(int i = 0; i < quant_linhas; i++){
        for(int j = 0; j < quant_colunas; j++){
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }
    
    printf("\n%d", maior);
 
    return SUCESSO;
}
