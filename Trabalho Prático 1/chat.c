#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pokemon_battle.h"

#define SUCESSO 0
#define FALHA -1

int main(int argc, char** argv) {
    
    struct treinador trainer_um;
    struct treinador trainer_dois;
    FILE*arquivo;
    int erro = SUCESSO, j;
    
    arquivo = fopen("arquivo.txt", "r");
    
    if(arquivo == NULL){
        printf("**Erro na abertura do arquivo**\n");
        return FALHA;
    }
    
    if(fscanf(arquivo, "%d %d", &trainer_um.num_ativos, &trainer_dois.num_ativos) != 2){
        printf("**Erro na leitura do número de pokemons - Variáveis insuficientes**");
        return FALHA;
    }
    
    erro += le_arquivo(trainer_um.team, trainer_um.num_ativos, arquivo);
    erro += le_arquivo(trainer_dois.team, trainer_dois.num_ativos, arquivo);
    
    if(erro < SUCESSO){
        return FALHA;
    }
    
    fclose(arquivo);

    printf("%d %d\n", trainer_um.num_ativos, trainer_dois.num_ativos);
    imprime_dados(trainer_um.team, trainer_um.num_ativos);    
    imprime_dados(trainer_dois.team, trainer_dois.num_ativos);
   
    printf("\n");
    
    do{
        turno(&trainer_um, &trainer_dois);
        turno(&trainer_dois, &trainer_um);
        
    }while((trainer_um.num_ativos > GAME_OVER) && (trainer_dois.num_ativos > GAME_OVER));
    
    if(trainer_um.num_ativos != GAME_OVER){
       vencedor(trainer_um, 1);
    }else{
        vencedor(trainer_dois, 2);
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
