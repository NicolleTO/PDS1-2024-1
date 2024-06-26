#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA -1

#define MAX_POKEMON 100
#define MAX_NOME 20

#define GAME_OVER 0

#define ELETRICO "eletrico"
#define AGUA "agua"
#define FOGO "fogo"
#define GELO "gelo"
#define PEDRA "pedra"

#define FRACO 0.8
#define NORMAL 1
#define FORTE 1.2

typedef struct pokemon {
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    float vida;
    char tipo[MAX_NOME];
} pokemon;

typedef struct treinador {
    int num_ativos;
    pokemon team[MAX_POKEMON];
    int pos_em_campo;
} treinador;

int le_arquivo(pokemon pokemons[], int n, FILE *arquivo);
void imprime_dados(pokemon pokemons[], int n);
void vencedor(treinador *vencedor, int num);
float fraquezas(pokemon *atacante, pokemon *defensor);
void ataque(pokemon *atacante, pokemon *defensor);
void turno(treinador *atacante, treinador *defensor);

int main(int argc, char **argv) {
    treinador trainer_um = {0};
    treinador trainer_dois = {0};
    FILE *arquivo;
    int erro = SUCESSO;
    
    arquivo = fopen("arquivo.txt", "r");
    
    if (arquivo == NULL) {
        printf("**Erro na abertura do arquivo**\n");
        return FALHA;
    }
    
    if (fscanf(arquivo, "%d %d", &trainer_um.num_ativos, &trainer_dois.num_ativos) != 2) {
        printf("**Erro na leitura do número de pokemons - Variáveis insuficientes**\n");
        fclose(arquivo);
        return FALHA;
    }
    
    erro += le_arquivo(trainer_um.team, trainer_um.num_ativos, arquivo);
    erro += le_arquivo(trainer_dois.team, trainer_dois.num_ativos, arquivo);
    
    if (erro < SUCESSO) {
        fclose(arquivo);
        return FALHA;
    }
    
    fclose(arquivo);

    printf("%d %d\n", trainer_um.num_ativos, trainer_dois.num_ativos);
    imprime_dados(trainer_um.team, trainer_um.num_ativos);    
    imprime_dados(trainer_dois.team, trainer_dois.num_ativos);
   
    printf("\n");

    do {
        turno(&trainer_um, &trainer_dois);
        turno(&trainer_dois, &trainer_um);
        
    } while (trainer_um.num_ativos > GAME_OVER && trainer_dois.num_ativos > GAME_OVER);
    
    if (trainer_um.num_ativos > GAME_OVER) {
       vencedor(&trainer_um, 1);
    } else {
        vencedor(&trainer_dois, 2);
    }
    
    printf("\nPokemons derrotados:\n");
    
    for (int i = 0; i < trainer_um.pos_em_campo; i++) {
        printf("%s\n", trainer_um.team[i].nome);
    }
    
    for (int i = 0; i < trainer_dois.pos_em_campo; i++) {
        printf("%s\n", trainer_dois.team[i].nome);
    }

    return SUCESSO;
}

int le_arquivo(pokemon pokemons[], int n, FILE *arquivo) {
    for (int i = 0; i < n; i++) {
        if (fscanf(arquivo, "%s %d %d %f %s", pokemons[i].nome, &pokemons[i].ataque, &pokemons[i].defesa, &pokemons[i].vida, pokemons[i].tipo) != 5) {
            printf("**Erro na leitura - Atributos insuficientes**\n");
            return FALHA;
        }
    }
    return SUCESSO;
}

void imprime_dados(pokemon pokemons[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
    }
}

void vencedor(treinador *vencedor, int num) {
    printf("\nJogador %d venceu!\n\nPokemons sobreviventes:\n", num);
    for (int i = 0; i < vencedor->num_ativos; i++) {
        printf("%s\n", vencedor->team[i].nome);
    }
}

float fraquezas(pokemon *atacante, pokemon *defensor) {
    float fraqueza = NORMAL;
    
    if (strcmp(atacante->tipo, ELETRICO) == 0) {
        if (strcmp(defensor->tipo, AGUA) == 0) {
            fraqueza = FORTE;
        } else if (strcmp(defensor->tipo, PEDRA) == 0) {
            fraqueza = FRACO;
        }
    } else if (strcmp(atacante->tipo, AGUA) == 0) {
        if (strcmp(defensor->tipo, FOGO) == 0) {
            fraqueza = FORTE;
        } else if (strcmp(defensor->tipo, ELETRICO) == 0) {
            fraqueza = FRACO;
        }
    } else if (strcmp(atacante->tipo, FOGO) == 0) {
        if (strcmp(defensor->tipo, GELO) == 0) {
            fraqueza = FORTE;
        } else if (strcmp(defensor->tipo, AGUA) == 0) {
            fraqueza = FRACO;
        }
    } else if (strcmp(atacante->tipo, GELO) == 0) {
        if (strcmp(defensor->tipo, PEDRA) == 0) {
            fraqueza = FORTE;
        } else if (strcmp(defensor->tipo, FOGO) == 0) {
            fraqueza = FRACO;
        }
    } else if (strcmp(atacante->tipo, PEDRA) == 0) {
        if (strcmp(defensor->tipo, ELETRICO) == 0) {
            fraqueza = FORTE;
        } else if (strcmp(defensor->tipo, GELO) == 0) {
            fraqueza = FRACO;
        }
    }
    
    return fraqueza;
}

void ataque(pokemon *atacante, pokemon *defensor) {
    float dano = atacante->ataque * fraquezas(atacante, defensor);
    
    if (dano > defensor->defesa) {
        defensor->vida -= dano - defensor->defesa;
    } else {
        defensor->vida--;
    }
}

void turno(treinador *atacante, treinador *defensor) {
    ataque(&atacante->team[atacante->pos_em_campo], &defensor->team[defensor->pos_em_campo]);

    if (defensor->team[defensor->pos_em_campo].vida <= GAME_OVER) {
        printf("%s venceu %s\n", atacante->team[atacante->pos_em_campo].nome, defensor->team[defensor->pos_em_campo].nome);
        defensor->pos_em_campo++;
        defensor->num_ativos--;
    }
}
