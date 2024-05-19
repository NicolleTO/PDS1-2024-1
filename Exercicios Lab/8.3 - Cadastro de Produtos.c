#include <stdio.h>
#include <string.h>

/*
a sadia 2
b sadia 3
c bic 3
d sadia 1
e mac 7
o bic 1
p mac 1.2
u trace 1
*/

#define SUCESSO 0
#define FALHA 1
#define MAX_TAM 50
#define MAX_PRODUTOS 8

typedef struct produto{
    char nome[MAX_TAM];
    char marca[MAX_TAM];
    float preco;
}produto;

typedef struct marca{
    char nome[MAX_TAM];
    int quant_produtos;
    float media_preco;
}marca;

int encontra_marcas(struct produto produtos[], struct marca marcas[]){
    
    int n = 0;
    int existe = FALHA;
    
    for(int i = 0; i < MAX_PRODUTOS; i++){
        for(int j = 0; j < MAX_PRODUTOS; j++){
            if(strcmp(produtos[i].marca, marcas[j].nome) == SUCESSO){
                existe = SUCESSO;
                break;
            }
        }
        
        if(existe != SUCESSO){
            strcmp(marcas[n].nome, produtos[i].marca);
        }
        
        existe = FALHA;
    }
    return n;
}

int main(int argc, char** argv) {
    
    struct produto produtos[MAX_PRODUTOS];
    struct marca marcas[MAX_PRODUTOS];
    int n_marcas = 0;
    
    //Ler as informacoes dos produtos
    for(int i = 0; i < MAX_PRODUTOS; i++){
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        getchar();
    }
    
    n_marcas = encontra_marcas(produtos, marcas);
    
    printf("%d marcas\n", n_marcas);
    
    for(int i = 0; i < n_marcas; i++){
        printf("%s\n", marcas[i].nome);
    }
    
    return SUCESSO;
}
