#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Constantes
#define SUCESSO 0

#define MAX_POKEMON 100
#define MAX_NOME 20

#define GAME_OVER 0

#define MAX_TREINADORES 2
#define TREINADOR_UM 0
#define TREINADOR_DOIS 1 

typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    int vida;
    char tipo[MAX_NOME];
}pokemon;

typedef struct treinador{
    int quant_ativos;
    struct pokemon ativos[MAX_POKEMON];
    int pos_em_campo;
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

void ataque(struct pokemon *atacante, struct pokemon *defensor){
    
    if(atacante->ataque >= defensor->defesa){
        defensor->vida -= atacante->ataque;
    }else if(atacante->ataque < defensor->defesa){
        defensor->vida--;
    }
}

void turno(struct treinador *atacante, struct treinador *defensor){
    int pos_atacante = atacante->pos_em_campo;
    int pos_defensor = defensor->pos_em_campo;
    
    printf("ta aqui\n");
    ataque(&atacante->ativos[pos_atacante], &defensor->ativos[pos_defensor]);
    
    if(defensor->ativos[pos_defensor].vida <= GAME_OVER){
        printf("game over - %s | %s \n", atacante->ativos[pos_atacante].nome, defensor->ativos[pos_defensor].nome);
        defensor->pos_em_campo++;
        defensor->quant_ativos--;
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
    
    fscanf(arquivo, "%d %d", &em_campo[TREINADOR_UM].quant_ativos, &em_campo[TREINADOR_DOIS].quant_ativos);
    printf("%d %d\n", em_campo[TREINADOR_UM].quant_ativos, em_campo[TREINADOR_DOIS].quant_ativos);
    
    le_arquivo(em_campo[TREINADOR_UM].ativos, em_campo[TREINADOR_UM].quant_ativos, arquivo);
    le_arquivo(em_campo[TREINADOR_DOIS].ativos, em_campo[TREINADOR_DOIS].quant_ativos, arquivo);
    
    imprime_dados(em_campo[TREINADOR_UM].ativos, em_campo[TREINADOR_UM].quant_ativos);
    imprime_dados(em_campo[TREINADOR_DOIS].ativos, em_campo[TREINADOR_DOIS].quant_ativos);
    
    fclose(arquivo);
    
    do{
        
        printf("turno t1\n");
        turno(&em_campo[TREINADOR_UM], &em_campo[TREINADOR_DOIS]);
        printf("turno t2\n");
        turno(&em_campo[TREINADOR_DOIS], &em_campo[TREINADOR_UM]);
        
    }while((em_campo[TREINADOR_UM].quant_ativos > GAME_OVER) && (em_campo[TREINADOR_DOIS].quant_ativos > GAME_OVER));
    
    
    return SUCESSO;
}
