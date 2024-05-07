#include <stdio.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char**argv)
{
    int matriz[MAX][MAX], oposta[MAX][MAX], quant_linhas, quant_colunas;
    
    scanf("%d", &quant_linhas);
    scanf("%d", &quant_colunas);
    
    for(int i = 0; i < quant_linhas; i++){
        for(int j = 0; j < quant_colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(int i = 0; i < quant_linhas; i++){
        for(int j = 0; j < quant_colunas; j++){
            oposta[i][j] = matriz[i][j] * -1;
        }
    }
    
    for(int i = 0; i < quant_linhas; i++){
        for(int j = 0; j < quant_colunas; j++){
            printf("%d ", oposta[i][j]);
        }
        printf("\n");
    }
 
    return SUCESSO;
}