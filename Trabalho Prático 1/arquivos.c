#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX 100

typedef struct pokemon{
    char nome[MAX];
    int ataque;
    int defesa;
    int vida;
    char tipo[MAX];
}pokemon;

int main(int argc, char** argv) {
    
    struct pokemon treinador1[MAX], treinador2[MAX];
    int n1, n2;
    FILE* arquivo;
    arquivo = fopen("arquivo.txt", "a");
    
    if(arquivo != NULL){
        printf("sucesso0");
    }else{
        printf("Algo deu errado");
        return SUCESSO;
    }
    
    fclose(arquivo);
    
    
    return SUCESSO;
}
//-------------------------------------------------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX 100

typedef struct pokemon{
    char nome[MAX];
    int ataque;
    int defesa;
    int vida;
    char tipo[MAX];
}pokemon;

int main(int argc, char** argv) {
    
    struct pokemon treinador1[MAX], treinador2[MAX];
    int n1 = 0, n2 = 0;
    char esse[MAX];
    FILE* arquivo;
    arquivo = fopen("arquivo.txt", "r");
    
    if(arquivo != NULL){
        printf("sucesso0\n");
        
        fscanf(arquivo, "%d %d", &n1, &n2);
        
        fclose(arquivo);
    }else{
        printf("Algo deu errado");
        return SUCESSO;
    }
    
    for(int i = 0; i < n1; i++){
        treinador1[i].nome = "pokemon\0";
        printf("%s\n", treinador1[i].nome);
    }
    for(int i = 0; i < n2; i++){
        treinador2[i].nome = "temos\0";
        printf("%s\n", treinador2[i].nome);
        
    }
    
    return SUCESSO;
}
*/
