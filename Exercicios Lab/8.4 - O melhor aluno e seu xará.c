/*
lucas
rezende
1
100 100 99
mario
ferreira
2
90 29 32
horacio
alano
3
89 32 43
*/

#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA 1

#define MAX_TAM 50
#define MAX_ALUNOS 2
#define QUANT_MATERIAS 3

typedef struct aluno{
    char nome[MAX_TAM];
    char sobrenome[MAX_TAM];
    int matricula;
    float notas[QUANT_MATERIAS];
}aluno;



int main(int argc, char** argv) {
    
    struct aluno turma[MAX_ALUNOS];
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        scanf("%s %s %d", turma[i].nome, turma[i].sobrenome, &turma[i].matricula);
        getchar();
        for(int j = 0; j < QUANT_MATERIAS; j++){
            scanf("%f", &turma[i].notas[j]);
        }
    }
   
    for(int i = 0; i < MAX_ALUNOS; i++){
        printf("%s %s\n", turma[i].nome, turma[i].sobrenome);
        for(int j = 0; j < QUANT_MATERIAS; j++){
            printf("%f ", turma[i].notas[j]);
        }
        printf("\n");
    }
    return SUCESSO;
}
