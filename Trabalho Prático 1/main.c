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
