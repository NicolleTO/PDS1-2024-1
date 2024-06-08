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

int le_arquivo(struct pokemon pokemons[], int n, FILE*arquivo);
void imprime_dados(struct pokemon pokemons[], int n);
void vencedor(struct treinador vencedor, int num);
float fraquezas(struct pokemon*atacante, struct pokemon *defensor);
void ataque(struct pokemon *atacante, struct pokemon *defensor);
void turno(struct treinador *atacante, struct treinador *defensor);
