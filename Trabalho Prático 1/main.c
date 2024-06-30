#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**    --Defines e estruturas--    **/

#define SUCESSO 0
#define FALHA -1

#define MAX_POKEMON 100
#define MAX_NOME 20

#define GAME_OVER 0

//Defines para organizar os tipos de pokemons
#define ELETRICO "eletrico"
#define AGUA "agua"
#define FOGO "fogo"
#define GELO "gelo"
#define PEDRA "pedra"

//Relação de fraqueza
#define FRACO 0.8
#define NORMAL 1
#define FORTE 1.2

/* Estrutura "pokemon"
 * Guarda todas as informações e atributos de um pokemon
*/
typedef struct pokemon{
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    float vida;
    char tipo[MAX_NOME];
}pokemon;

/* Estrutura "treinador":
 * Guarda o time pokemon de um treinador
 * 
 * "num_ativos": quantidade de pokemons que ainda estão vivos
 * "team[]": vetor com todos os pokemons presentes no time
 * "pos_em_campo": index do pokemon no campo de batalha atualmente
*/ 
typedef struct treinador{
    int num_ativos;
    pokemon team[MAX_POKEMON];
    int pos_em_campo;
}treinador;

/**    --Cabeçalhos das Funções--    **/
//Escopo e comentários abaixo do main

int le_arquivo(pokemon pokemons[], int n, FILE*arquivo);
void imprime_dados(pokemon pokemons[], int n);
void imprime_vencedor(treinador vencedor, int num);
float fraquezas(pokemon *atacante, pokemon *defensor);
void ataque(pokemon *atacante, pokemon *defensor);
void turno(treinador *atacante, treinador *defensor);

//O início...
int main(int argc, char** argv) {
    
    //Estruturas: todas as variáveis e strings são inicializadas com '0'
    //Evita erros de segmentation fault
    treinador trainer_um = {0};
    treinador trainer_dois = {0};
    FILE*arquivo;
    //"erro": utilizada para verificar erros na leitura do arquivo
    int erro = 0;
    
    arquivo = fopen("arquivo.txt", "r");
    
    //Se não foi possível abrir o arquivo...
    if(arquivo == NULL){
        printf("**Erro na abertura do arquivo**\n");
        return FALHA;
    }
    //...ou ler a quantidade de pokemons dos treinadores, encerra o programa
    //Função "fscanf": retorna a quantidade de valores lidos no arquivo
    if(fscanf(arquivo, "%d %d", &trainer_um.num_ativos, &trainer_dois.num_ativos) != 2){
        printf("**Erro na leitura do número de pokemons - Variáveis insuficientes**");
        fclose(arquivo);
        return FALHA;
    }
    
    //Lê o conteúdo dos arquivos e recebe um valor que indica se tudo deu certo ou não
    //Se correr tudo bem "erro" incrementa 0, se houver problemas, -1
    erro += le_arquivo(trainer_um.team, trainer_um.num_ativos, arquivo);
    erro += le_arquivo(trainer_dois.team, trainer_dois.num_ativos, arquivo);
    
    fclose(arquivo);

    //Se não foi possível ler os dados corretamente ("erro" = -1 ou -2), encerra o programa
    if(erro < SUCESSO){
        return FALHA;
    }

    //Mostra todas as informações lidas para o usuário
    printf("%d %d\n", trainer_um.num_ativos, trainer_dois.num_ativos);
    imprime_dados(trainer_um.team, trainer_um.num_ativos);    
    imprime_dados(trainer_dois.team, trainer_dois.num_ativos);
   
    printf("\n");
    
    /* Batalha: dividida em turnos
     * 
     * O treinador um começa e, terminada sua vez, passa para 
     * o treinador dois que realiza o mesmo processo
     * 
     * Função "turno": recebe o endereço dos treinadores para
     * que seja possível editar as informações durante as batalhas
     * 
     * "while": finaliza somente quando um dos treinadores 
     * não possui mais nenhum pokemon para colocar em campo
     * Ou seja, quando "trainer_n.num_ativos" <= GAME_OVER (0)
    */
    do{
        turno(&trainer_um, &trainer_dois);
        turno(&trainer_dois, &trainer_um);
    }while((trainer_um.num_ativos > GAME_OVER) && (trainer_dois.num_ativos > GAME_OVER));

    /**    --Fim de Jogo--    **/

    //Verifica qual treinador venceu e imprime seu time sobrevivente
    if(trainer_um.num_ativos > GAME_OVER){
       //Se treinador um venceu...
       imprime_vencedor(trainer_um, 1);
    }else{
        //Se não...
        imprime_vencedor(trainer_dois, 2);
    }

    //Listagem de todos os poekemons derrotados de ambos os treinadores
    printf("\nPokemons derrotados:\n");
    for(int i = 0; i < trainer_um.pos_em_campo; i++){
        printf("%s\n", trainer_um.team[i].nome);
    }
    for(int i = 0; i < trainer_dois.pos_em_campo; i++){
        printf("%s\n", trainer_dois.team[i].nome);
    }
    printf("\n");

    //Se deu tudo certo
    return SUCESSO;
}

/**    --Funções--    **/

/* ->Lê as informações dos pokemons presentes em "arquivo.txt" 
 * 
 * !! A função recebe a quantidade total de pokemons de apenas UM treinador
 * Assim, para cadastrar mais treinadores é necessário chamar a função novamente 
 * para cada um deles !!
 *
 * Parâmetros
 *      "pokemons": onde o time de pokemons do treinador N será guardado
 *      "n"       : total inicial de pokemons do treinador N
 *      "arquivo" : arquivo a ser lido
 * return
 *      SUCESSO (0): se todas as informações esperadas foram lidas correntamente
 *      FALHA (-1) : caso contrário
*/
int le_arquivo(pokemon pokemons[], int n, FILE*arquivo){
    for(int i = 0; i < n; i++){
        //Função "fscanf": retorna a quantidade de valores lidos
        if(fscanf(arquivo, "%s %d %d %f %s", pokemons[i].nome, &pokemons[i].ataque, &pokemons[i].defesa, &pokemons[i].vida, pokemons[i].tipo) != 5){
            
            printf("**Erro na leitura - Atributos insuficientes**\n");
            printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
            
            //limpa o buffer - impede que o erro passe despercebido uma vez
            while (fgetc(arquivo) != '\n' && !feof(arquivo));
            return FALHA;
        }
    }
    return SUCESSO;
}

/* -> Imprime as informações dos pokemons recebidos
 * 
 * !! Essa função também recebe as informações dos pokemons de somente UM treinador !!
 * 
 * Parâmetros
 *      "pokemons": time de pokemons a ser impresso
 *      "n"       : total inicial de pokemons do treinador N
*/
void imprime_dados(pokemon pokemons[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
    }
}

/* -> Imprime o time sobrevivente do treinador vencedor
 * 
 * Parâmetros
 *      "vencedor": contém todas as informações do time do treinador
 *      "num"     : número N do treinador (no caso, 1 ou 2)
 * Varáveis:
 *      "j"  : recebe o index do último pokemon em campo para imprimir
 *             os sobreviventes a partir dele 
*/
void imprime_vencedor(treinador vencedor, int num){

    int j = vencedor.pos_em_campo;
    
    printf("\nJogador %d venceu!\n\nPokemons sobreviventes:\n", num);
    for(int i = 0; i < vencedor.num_ativos; i++){
        printf("%s\n",  vencedor.team[j].nome);
        j++;
    }
}

/* -> Determina a efetividade de um ataque baseado
 *    no tipo do atacante e do defensor
 * 
 * Parâmetros
 *      "atacante": usado para verificar o tipo do pokemon que vai atacar
 *      "defensor": usado para verificar o tipo do pokemon que recebe o ataque
 * Variável
 *      "fraqueza": guarda a relação de efetividade entre os tipos de pokemons recebidos
 *                  Inicializada com NORMAL(1)
 * return
 *      "fraqueza":
 *          NORMAL (1)  : sem mudança na efetividade, ataque não alterado
 *          FORTE (1.2) : pokemon efetivo contra o oponente, ataque será aumentado em 20%
 *          FRACO (0.8) : pokemon não efetivo contra o oponente, ataque será reduzido em 20%
*/
float fraquezas(pokemon *atacante, pokemon *defensor){

    float fraqueza = NORMAL;
    
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

/* -> Calcula o valor do ataque de um pokemon e determina a vida restante do oponente
 * 
 * Parâmetros
 *      "atacante": informações e atributos do pokemon que realizará um ataque
 *      "defensor": informações e atributos do pokemon que receberá o ataque
 * Variável
 *      "dano": recebe o produto do ataque do atacante e sua efetividade
*/
void ataque(pokemon *atacante, pokemon *defensor){
    
    float dano = atacante->ataque * fraquezas(atacante, defensor);
    
    //Caso o ataque supere a defesa do oponente...
    if(dano > defensor->defesa){
        //...subtrai o dano de sua vida, se não...
        defensor->vida -= dano - defensor->defesa;
    }else{
        //...realiza apenas 1 de dano
        defensor->vida--;
    }
}

/* -> Controla o turno de cada treinador, chamando a função "ataque" para seu
 *    pokemon e verificando a vida do pokemon oponente
 *    Caso ela tenha zerado, o pokemon em campo (do adversário) é trocado pelo próximo na
 *    lista e o turno finaliza
 * 
 * Parâmetros
 *      "atacante": informações e atributos do pokemon que realizará um ataque
 *      "defensor": informações e atributos do pokemon que receberá o ataque
*/
void turno(treinador *atacante, treinador *defensor){
    
    ataque(&atacante->team[atacante->pos_em_campo], &defensor->team[defensor->pos_em_campo]);
    
    if(defensor->team[defensor->pos_em_campo].vida <= GAME_OVER){       
        printf("%s venceu %s\n", atacante->team[atacante->pos_em_campo].nome, defensor->team[defensor->pos_em_campo].nome);
        defensor->pos_em_campo++;
        defensor->num_ativos--;
    }
}
