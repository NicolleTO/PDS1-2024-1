#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Constantes
#define SUCESSO 0

#define MAX_POKEMON 100
#define MAX_NOME 20

#define POKEMON_EM_CAMPO 0
#define GAME_OVER 0

#define MAX_TREINADORES 2

typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    int vida;
    char tipo[MAX_NOME];
}pokemon;

typedef struct treinador{
    int quant;
    struct pokemon ativos[MAX_POKEMON];
    struct pokemon derrotados[MAX_POKEMON];
}treinador;

void le_arquivo(struct pokemon treinador[], int n, FILE*arquivo){
    for(int i = 0; i < n; i++){
        fscanf(arquivo, "%s %d %d %d %s", treinador[i].nome, &treinador[i].ataque, &treinador[i].defesa, &treinador[i].vida, treinador[i].tipo);
    }
}

void imprime_dados(struct pokemon treinador[], int n){
     for(int i = 0; i < n; i++){
        printf("%s %d %d %d %s\n", treinador[i].nome, treinador[i].ataque, treinador[i].defesa, treinador[i].vida, treinador[i].tipo);
    }
}

//O inicio...
int main(int argc, char** argv) {
    
    struct treinador em_campo[MAX_TREINADORES];
    FILE*arquivo;
    
    arquivo = fopen("arquivo.txt", "r");
    
    if(arquivo == NULL){
        printf("**Erro na abertura do arquivo**\n");
        return SUCESSO;
    }
    
    fscanf(arquivo, "%d %d", &em_campo[0].quant, &em_campo[1].quant);
    printf("%d %d\n", em_campo[0].quant, em_campo[1].quant);
    
    le_arquivo(em_campo[0].ativos, em_campo[0].quant, arquivo);
    le_arquivo(em_campo[1].ativos, em_campo[1].quant, arquivo);
    
    imprime_dados(em_campo[0].ativos, em_campo[0].quant);
    imprime_dados(em_campo[1].ativos, em_campo[1].quant);
    
    fclose(arquivo);
    
    
    return SUCESSO;
}
