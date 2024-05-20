#include <stdio.h>
#include <string.h>

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
    float media;
}marca;

int encontra_marcas(struct produto produtos[], struct marca marcas[]){
    
    int n = 0;
    int existe = FALHA;
    
    for(int i = 0; i < MAX_PRODUTOS; i++){
        for(int j = 0; j < n; j++){
            if(strcmp(produtos[i].marca, marcas[j].nome) == SUCESSO){
                existe = SUCESSO;
                break;
            }
        }
        
        if(existe != SUCESSO){
            strcpy(marcas[n].nome, produtos[i].marca);
            n++;
        }
        
        existe = FALHA;
    }
    return n;
}

void quant_produtos(struct produto produtos[], struct marca marcas[], int n_marcas){
    
    for(int i = 0; i < n_marcas; i++){
        
        for(int j = 0; j < MAX_PRODUTOS; j++){
            if(strcmp(marcas[i].nome, produtos[j].marca) == SUCESSO){
                marcas[i].quant_produtos++;
                marcas[i].media += produtos[j].preco;
            }
        }
        
        marcas[i].media = marcas[i].media / marcas[i].quant_produtos;
    }
}

int main(int argc, char** argv) {
    
    struct produto produtos[MAX_PRODUTOS];
    struct marca marcas[MAX_PRODUTOS];
    int n_marcas = 0;
    float media_t = 0;
    
    //Ler as informacoes dos produtos
    for(int i = 0; i < MAX_PRODUTOS; i++){
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        getchar();
        
        media_t += produtos[i].preco;
        
        marcas[i].quant_produtos = 0;
        marcas[i].media = 0.00;
    }
    
    n_marcas = encontra_marcas(produtos, marcas);
    quant_produtos(produtos, marcas, n_marcas);
    
    for(int i = 0; i < n_marcas; i++){
        printf("%s %d\n", marcas[i].nome, marcas[i].quant_produtos);
    }
    
    printf("media total %.2f\n", media_t / MAX_PRODUTOS);
    
    for(int i = 0; i < n_marcas; i++){
        printf("media %s %.2f\n", marcas[i].nome, marcas[i].media);
    }
    
    return SUCESSO;
}
