#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Constantes
#define SUCESSO 0

#define MAX_POKEMON 100
#define MAX_NOME 20

#define POKEMON_EM_CAMPO 0
#define GAME_OVER 0

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

void imprime_dados(struct pokemon treinador[], int n){
     for(int i = 0; i < n; i++){
        printf("%s %d %d %d %s\n", treinador[i].nome, treinador[i].ataque, treinador[i].defesa, treinador[i].vida, treinador[i].tipo);
    }
}

void pokemon_eliminado(struct pokemon treinador[], int n){
    
    struct pokemon tmp;
    
    for(int i = 0; i < (n - 1); i++){
        tmp = treinador[i];
        treinador[i] = treinador[i + 1];
    }
    
    //comando adicionado para limpar a posição anterior do último pokemon
    memset(&treinador[n - 1], 0, sizeof(struct pokemon));
}

void ataque(struct pokemon *atacante, struct pokemon *defensor){
    
    if(atacante->ataque >= defensor->defesa){
        defensor->vida -= atacante->ataque;
    }else if(atacante->ataque < defensor->defesa){
        defensor->vida--;
    }
}

int turno(struct pokemon atacante[], struct pokemon defensor[], int n){
    
    ataque(&atacante[POKEMON_EM_CAMPO], &defensor[POKEMON_EM_CAMPO]);
    
    if(defensor[POKEMON_EM_CAMPO].vida <= GAME_OVER){
        printf("%s venceu %s\n", atacante[POKEMON_EM_CAMPO].nome, defensor[POKEMON_EM_CAMPO].nome);
        pokemon_eliminado(defensor, n);
        n--;
    }
    
    return n;    
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
    
    imprime_dados(treinador1, n1);
    imprime_dados(treinador2, n2);
    
    printf("\n\n");
    
    do{
        
        //treinador1
        n2 = turno(treinador1, treinador2, n2);
        
        //treinador2
        n1 = turno(treinador2, treinador1, n1);
        
    }while((n1 != GAME_OVER) && (n2 != GAME_OVER));
    
    if(n1 != GAME_OVER){
        printf("\nJogador 1 venceu!\n\nPokemons sobreviventes:\n");
        for(int i = 0; i < n1; i++){
            printf("%s\n", treinador1[i].nome);
        }
    }else{
        printf("\nJogador 2 venceu!\n\nPokemons sobreviventes:\n");
        for(int i = 0; i < n2; i++){
            printf("%s\n", treinador2[i].nome);
        }
    }
    
    return SUCESSO;
}
