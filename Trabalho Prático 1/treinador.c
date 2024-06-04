#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0

#define MAX_POKEMON 100
#define MAX_NOME 20

#define GAME_OVER 0

#define ELETRICO "eletrico"
#define AGUA "agua"
#define FOGO "fogo"
#define GELO "gelo"
#define PEDRA "pedra"

#define FRACO -1
#define NORMAL 0
#define FORTE 1

typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    float vida;
    char tipo[MAX_NOME];
}pokemon;

typedef struct treinador{
    int num_ativos;
    struct pokemon team[MAX_POKEMON];
    int pos_em_campo;
}treinador;

void le_arquivo(struct pokemon pokemons[], int n, FILE*arquivo);
void imprime_dados(struct pokemon pokemons[], int n);
int fraquezas(struct pokemon*atacante, struct pokemon *defensor);
void ataque(struct pokemon *atacante, struct pokemon *defensor);
void turno(struct treinador *atacante, struct treinador *defensor);

int main(int argc, char** argv) {
    
    struct treinador trainer_um;
    struct treinador trainer_dois;
    FILE*arquivo;
    
    arquivo = fopen("arquivo.txt", "r");
    
    if(arquivo == NULL){
        printf("**Erro na abertura do arquivo**\n");
        return SUCESSO;
    }
    
    fscanf(arquivo, "%d %d", &trainer_um.num_ativos, &trainer_dois.num_ativos);
    printf("%d %d\n", trainer_um.num_ativos, trainer_dois.num_ativos);
    
    le_arquivo(trainer_um.team, trainer_um.num_ativos, arquivo);
    le_arquivo(trainer_dois.team, trainer_dois.num_ativos, arquivo);
    
    fclose(arquivo);

    imprime_dados(trainer_um.team, trainer_um.num_ativos);    
    imprime_dados(trainer_dois.team, trainer_dois.num_ativos);
   
    printf("\n");
    
    do{
        //printf("turno1\n");
        turno(&trainer_um, &trainer_dois);
        //printf("turno2\n");
        turno(&trainer_dois, &trainer_um);
        
    }while((trainer_um.num_ativos > GAME_OVER) && (trainer_dois.num_ativos > GAME_OVER));
    
    if(trainer_um.num_ativos != GAME_OVER){
        printf("\nJogador 1 venceu!\n\nPokemons sobreviventes:\n");
        for(int i = trainer_um.pos_em_campo; i <= trainer_um.num_ativos; i++){
            printf("%s\n",  trainer_um.team[i].nome);
        }
    }else{
        printf("\nJogador 2 venceu!\n\nPokemons sobreviventes:\n");
        for(int i = trainer_dois.pos_em_campo; i <= trainer_dois.num_ativos; i++){
            printf("%s\n", trainer_dois.team[i].nome);
        }
    }
    
    printf("\nPokemons derrotados:\n");
    
    for(int i = 0; i < trainer_um.pos_em_campo; i++){
        printf("%s\n", trainer_um.team[i].nome);
    }
    
    for(int i = 0; i < trainer_dois.pos_em_campo; i++){
        printf("%s\n", trainer_dois.team[i].nome);
    }
    
    return SUCESSO;
}


/*---------------Funções---------------*/

void le_arquivo(struct pokemon pokemons[], int n, FILE*arquivo){
    for(int i = 0; i < n; i++){
        fscanf(arquivo, "%s %d %d %f %s", pokemons[i].nome, &pokemons[i].ataque, &pokemons[i].defesa, &pokemons[i].vida, pokemons[i].tipo);
    }
}

void imprime_dados(struct pokemon pokemons[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
    }
}

int fraquezas(struct pokemon *atacante, struct pokemon *defensor){

    int fraqueza = NORMAL;
    
    if(strcmp(atacante->tipo, ELETRICO) == SUCESSO){
        if(strcmp(defensor->tipo, AGUA) == SUCESSO){
            fraqueza = FORTE;
        }else if(strcmp(defensor->tipo, PEDRA) == SUCESSO){
            fraqueza = FRACO;
        }
    }else if(strcmp(atacante->tipo, AGUA) == SUCESSO){
        if(strcmp(defensor->tipo, FOGO) == SUCESSO){
            fraqueza = FORTE;
        }else if(strcmp(defensor->tipo, ELETRICO) == SUCESSO){
            fraqueza = FRACO;
        }
    }else if(strcmp(atacante->tipo, FOGO) == SUCESSO){
        if(strcmp(defensor->tipo, GELO) == SUCESSO){
            fraqueza = FORTE;
        }else if(strcmp(defensor->tipo, AGUA) == SUCESSO){
            fraqueza = FRACO;
        }
    }else if(strcmp(atacante->tipo, GELO) == SUCESSO){
        if(strcmp(defensor->tipo, PEDRA) == SUCESSO){
            fraqueza = FORTE;
        }else if(strcmp(defensor->tipo, FOGO) == SUCESSO){
            fraqueza = FRACO;
        }
    }else if(strcmp(atacante->tipo, PEDRA) == SUCESSO){
        if(strcmp(defensor->tipo, ELETRICO) == SUCESSO){
            fraqueza = FORTE;
        }else if(strcmp(defensor->tipo, GELO) == SUCESSO){
            fraqueza = FRACO;
        }
    }
    return fraqueza;
}

void ataque(struct pokemon *atacante, struct pokemon *defensor){
    
//    printf("%s ataca %s\n", atacante->nome, defensor->nome); 

    int situacao = fraquezas(atacante, defensor);
    
    if(atacante->ataque > defensor->defesa){
        if(situacao == FRACO){
            defensor->vida -= atacante->ataque*(0.8) - defensor->defesa;
        }else if(situacao == FORTE){
            defensor->vida -= atacante->ataque*(1.2) - defensor->defesa;
        }else{
            defensor->vida -= (atacante->ataque - defensor->defesa);    
        }
        
        //printf("ataque funciona - %s tem %.2f de vida agora\n", defensor->nome, defensor->vida);
    }else{
        defensor->vida--;
        //printf("ataque nao funciona - %s tem %.2f de vida agora\n", defensor->nome, defensor->vida);
    }
}

void turno(struct treinador *atacante, struct treinador *defensor){
    
    ataque(&atacante->team[atacante->pos_em_campo], &defensor->team[defensor->pos_em_campo]);

    if(defensor->team[defensor->pos_em_campo].vida <= GAME_OVER){
        printf("%s venceu %s\n", atacante->team[atacante->pos_em_campo].nome, defensor->team[defensor->pos_em_campo].nome);
        defensor->pos_em_campo++;
        defensor->num_ativos--;
        //printf("\n--\n defensor usa %s agora\n--\n", defensor->team[defensor->pos_em_campo].nome);
    }
    
}
