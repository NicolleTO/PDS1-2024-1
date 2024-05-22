/*
lucas
rezende
1
99 100 98
mario
ferreira
2
90 29 32
horacio
alano
3
89 32 43
maria
luiza
4
99 98 100
luis
estacio
5
40 20 50
*/
#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA 1

#define MAX_TAM 50
#define MAX_ALUNOS 5
#define QUANT_MATERIAS 3

#define APROVADO (1 == 1)
#define REPROVADO (!APROVADO)
#define PONTOS_MIN 60

//importancia
#define PDS 0
#define GAAL 1
#define CALCULO 2

typedef struct aluno{
    char nome[MAX_TAM];
    char sobrenome[MAX_TAM];
    int matricula;
    float notas[QUANT_MATERIAS];
    float media;
    int passou;
}aluno;

void media(struct aluno turma[]){
    
    float valor = 0;

    for(int i = 0; i < MAX_ALUNOS; i++){
        for(int j = 0; j < QUANT_MATERIAS; j++){
            valor += turma[i].notas[j];
        }
        turma[i].media = valor/QUANT_MATERIAS;
        valor = 0;
        if(turma[i].media >= PONTOS_MIN){
            turma[i].passou = APROVADO;
        }else{
            turma[i].passou = REPROVADO;
        }
    }
}

int melhor(struct aluno turma[]){
    int esse = 0;
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        
        if(turma[esse].media == turma[i].media){
            
            if(turma[esse].notas[PDS] < turma[i].notas[PDS]){
                esse = i;
            }else if(turma[esse].notas[GAAL] < turma[i].notas[GAAL]){
                esse = i;
            }else if(turma[esse].notas[CALCULO] < turma[i].notas[CALCULO]){
                esse = i;
            }
        }else if(turma[esse].media < turma[i].media){
            esse = i;
        }
    }

    return esse;
}

int pior(struct aluno turma[]){
    int esse = 0;
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        if(turma[esse].media == turma[i].media){
            
            if(turma[esse].notas[PDS] > turma[i].notas[PDS]){
                esse = i;
            }else if(turma[esse].notas[GAAL] > turma[i].notas[GAAL]){
                esse = i;
            }else if(turma[esse].notas[CALCULO] > turma[i].notas[CALCULO]){
                esse = i;
            }
        }else if(turma[esse].media > turma[i].media){
            esse = i;
        }
    }
    return esse;
}

int situacao(struct aluno melhor_aluno, struct aluno pior_aluno){
    
}

int main(int argc, char** argv) {
    
    struct aluno turma[MAX_ALUNOS];
    int melhor_aluno, pior_aluno;
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        scanf("%s %s %d", turma[i].nome, turma[i].sobrenome, &turma[i].matricula);
        getchar();
        for(int j = 0; j < QUANT_MATERIAS; j++){
            scanf("%f", &turma[i].notas[j]);
        }
    }
   
    media(turma);
    melhor_aluno = melhor(turma);
    pior_aluno = pior(turma);
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        printf("\n%s %s\n", turma[i].nome, turma[i].sobrenome);
        for(int j = 0; j < QUANT_MATERIAS; j++){
            printf("%.2f ", turma[i].notas[j]);
        }
        printf("\nmedia - %.2f\n", turma[i].media);
    }
    
    printf("\nMelhor aluno - %s %s | Média - %.2f", turma[melhor_aluno].nome, turma[melhor_aluno].sobrenome, turma[melhor_aluno].media);
    printf("\nPior aluno - %s %s | Média - %.2f\n", turma[pior_aluno].nome, turma[pior_aluno].sobrenome, turma[pior_aluno].media);
    
    return SUCESSO;
}
