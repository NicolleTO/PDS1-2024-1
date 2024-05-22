/* Implemente um programa que faça a união de dois arrays ordenados a[n] e
b[m] em um único array ordenado c[n+m]. O programa deve aproveitar o
fato de que os arrays a[n] e b[m] já estão ordenados e fazer a intercalação
dos itens desses arrays mantendo o array c[n+m] ordenado a cada etapa.
Algoritmos de ordenação são desnecessários e não devem ser usados.
*/

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX_TAM 5

int main(int argc, char**argv) {
    
    int A[MAX_TAM], B[MAX_TAM];
    int C[MAX_TAM*2];
    
    printf("Digite os elementos de A (ordenados):\n");
    for(int i = 0; i < MAX_TAM; i++){
        scanf("%d", &A[i]);
    }
    printf("Digite os elementos de B (ordenados):\n");
    for(int i = 0; i < MAX_TAM; i++){
        scanf("%d", &B[i]);
    }
    
    int i, j = 0, k = 0;
    
    for(i = 0; i < MAX_TAM && j < MAX_TAM;){
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
        }else{
            C[k] = B[j];
            j++;
        }
        k++;
    }
    
    for(;i < MAX_TAM; i++){
        C[k] = A[i];
        k++;
    }
    
    for(;j < MAX_TAM; j++){
        C[k] = B[j];
        k++;
    }
    
    printf("Array ordenado: ");
    for(int i = 0; i < MAX_TAM*2; i++){
        printf("%d ", C[i]);
    }

    return SUCESSO;
}
