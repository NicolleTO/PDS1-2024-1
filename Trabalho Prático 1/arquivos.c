#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Constantes
#define SUCESSO 0
#define MAX_POKEMON 100
#define MAX_NOME 20

typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    int vida;
    char tipo[MAX_NOME];
}pokemon;
/*
int conta_linhas(FILE*arquivo){

    int num_linhas = 0;
    char a;
    
    do{
        a = fgetc(arquivo);
        if(a == '\n'){
            num_linhas++;
        }
    }while(!feof(arquivo));
    
    return num_linhas;
}
*/
void le_arquivo(struct pokemon treinador[], int n, FILE*arquivo){
    for(int i = 0; i < n; i++){
        fscanf(arquivo, "%s %d %d %d %s", treinador[i].nome, &treinador[i].ataque, &treinador[i].defesa, &treinador[i].vida, treinador[i].tipo);
    }
}

//O inicio...
int main(int argc, char** argv) {
    
    int n1, n2;
    struct pokemon treinador1[MAX_POKEMON], treinador2[MAX_POKEMON]; 
   
    FILE*arquivo;
    arquivo = fopen("arquivo.txt", "r");
    
    if(arquivo == NULL){
        printf("**Erro na abertura do arquivo**\n");
        return SUCESSO;
    }
    
    fscanf(arquivo, "%d %d", &n1, &n2);
    
    printf("%d %d\n", n1, n2);
    
    le_arquivo(treinador1, n1, arquivo);
    le_arquivo(treinador2, n2, arquivo);
    
    fclose(arquivo);
   
    for(int i = 0; i < n1; i++){
        printf("%s - %d - %d - %d - %s\n", treinador1[i].nome, treinador1[i].ataque, treinador1[i].defesa, treinador1[i].vida, treinador1[i].tipo);
    }
    printf("--------\n");
    for(int i = 0; i < n2; i++){
        printf("%s %d %d %d %s\n", treinador2[i].nome, treinador2[i].ataque, treinador2[i].defesa, treinador2[i].vida, treinador2[i].tipo);
    }
	
	return SUCESSO;
}
