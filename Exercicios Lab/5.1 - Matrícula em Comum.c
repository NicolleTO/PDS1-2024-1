#include <stdio.h>

#define SUCESSO 0
#define MAX 1000

int main(int argc, char**argv)
{
    int alunos_calc[MAX], quant_calc, alunos_aeds[MAX], quant_aeds, i;
    
    scanf("%d", &quant_calc);
    
    for(i = 0; i < quant_calc; i++){
        scanf("%d", &alunos_calc[i]);
    }  
    
    printf("\n");
    
    scanf("%d", &quant_aeds);
    
    for(i = 0; i < quant_aeds; i++){
        scanf("%d", &alunos_aeds[i]);
    }   
    
    printf("\n");

    for(i = 0; i < quant_calc; i++){
        for(int j = 0; j < quant_aeds; j++){
            if(alunos_calc[i] == alunos_aeds[j]){
                printf("%d\n", alunos_aeds[j]);
                break;
            }
        }
        
    }
    
    
    return SUCESSO;
}
