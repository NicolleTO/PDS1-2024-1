#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define MAX_POKEMON 100
#define MAX_NOME 20

typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    char tipo[MAX_NOME];
}pokemon;

void le_poke_terminal(struct pokemon treinador1[], struct pokemon treinador2[], int n1, int n2){
    
    for(int i = 0; i < n1; i++){
        fgets(treinador1[i].nome, MAX_NOME, stdin);
        treinador1[i].nome[strlen(treinador1[i].nome) - 1] = '\0';
        
        fgets(treinador1[i].tipo, MAX_NOME, stdin);
        treinador1[i].tipo[strlen(treinador1[i].tipo) - 1] = '\0';
        
        scanf("%d", &treinador1[i].ataque);
        
        getchar();
    }
    
    for(int i = 0; i < n2; i++){
        fgets(treinador2[i].nome, MAX_NOME, stdin);
        treinador2[i].nome[strlen(treinador2[i].nome) - 1] = '\0';
        
        fgets(treinador2[i].tipo, MAX_NOME, stdin);
        treinador2[i].tipo[strlen(treinador2[i].tipo) - 1] = '\0';
        
        scanf("%d", &treinador2[i].ataque);
        
        getchar();
    }
}

int main(int argc, char** argv) {
    
    struct pokemon treinador1[MAX_POKEMON], treinador2[MAX_POKEMON];
    int n1, n2;
  
    scanf("%d %d", &n1, &n2);
    getchar();
     
    le_poke_terminal(treinador1, treinador2, n1, n2);
    
    printf("\n--------T1------\n");
    for(int i = 0; i < n1; i++){
        printf("%s - %s - %d\n", treinador1[i].nome, treinador1[i].tipo, treinador1[i].ataque);
    }
     printf("\n-------T2-------\n");
    for(int i = 0; i < n2; i++){
        printf("%s - %s - %d\n", treinador2[i].nome, treinador2[i].tipo, treinador2[i].ataque);
    }
    
    return SUCESSO;
}
