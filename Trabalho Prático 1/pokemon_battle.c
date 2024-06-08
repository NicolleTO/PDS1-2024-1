#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon_battle.h"

int le_arquivo(struct pokemon pokemons[], int n, FILE*arquivo){

    for(int i = 0; i < n; i++){
        if(fscanf(arquivo, "%s %d %d %f %s", pokemons[i].nome, &pokemons[i].ataque, &pokemons[i].defesa, &pokemons[i].vida, pokemons[i].tipo) != 5){
            
            printf("**Erro na leitura - Atributos insuficientes**\n");
            printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
            
            //limpa o buffer - impede que o erro apareça duas vezes quando falta o atributo "ataque"
            while (fgetc(arquivo) != '\n' && !feof(arquivo));
            
            return FALHA;
        }
    }
    return SUCESSO;
}

void imprime_dados(struct pokemon pokemons[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d %d %.2f %s\n", pokemons[i].nome, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].vida, pokemons[i].tipo);
    }
}

float fraquezas(struct pokemon *atacante, struct pokemon *defensor){

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

void ataque(struct pokemon *atacante, struct pokemon *defensor){
    
    float dano = atacante->ataque * fraquezas(atacante, defensor);
    
    if(dano > defensor->defesa){
        defensor->vida -= dano - defensor->defesa;
    }else{
        defensor->vida--;
    }
}

void turno(struct treinador *atacante, struct treinador *defensor){
    
    ataque(&atacante->team[atacante->pos_em_campo], &defensor->team[defensor->pos_em_campo]);

    if(defensor->team[defensor->pos_em_campo].vida <= GAME_OVER){
        printf("%s venceu %s\n", atacante->team[atacante->pos_em_campo].nome, defensor->team[defensor->pos_em_campo].nome);
        defensor->pos_em_campo++;
        defensor->num_ativos--;
    }
    
}