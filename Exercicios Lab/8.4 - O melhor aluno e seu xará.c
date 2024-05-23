/*
David
Silva
1
99 98 100
Eduardo
Ferreira
2
99 100 98
Daniel
Silva
3
50 50 50
Paulo
Madeira
4
60 60 60
Paulo
Silveira
5
70 70 70
Daniel
Silveira
6
90 90 90
Paula
Madeira
7
45 45 45
Rafael
Ferreira
8
75 75 75
Rafael
Oliveira
9
80 80 80
Eduardo
Rocha
10
99 80 56
*/
#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA -1

#define MAX_TAM 50
#define MAX_ALUNOS 10
#define QUANT_MATERIAS 3
#define APROVADO 60

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
}aluno;

void media(struct aluno turma[]){
    
    float valor = 0;
    for(int i = 0; i < MAX_ALUNOS; i++){
        for(int j = 0; j < QUANT_MATERIAS; j++){
            valor += turma[i].notas[j];
        }
        turma[i].media = valor/QUANT_MATERIAS;
        valor = 0;
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
int encontra_xara(struct aluno turma[], int melhor){
    
    int xara = FALHA;
    for(int i = 0; i < MAX_ALUNOS; i++){
        if((i != melhor) && ((strcmp(turma[melhor].nome, turma[i].nome)) == SUCESSO)){
            xara = i;
            break;
        }
    }
    return xara;
}

void situacao(struct aluno turma[], int melhor, int xara){
    
    if(xara == -1){
        printf("O melhor aluno nao tem xará\n");
    }else if((turma[xara].notas[PDS] >= APROVADO) && (turma[xara].notas[GAAL] >= APROVADO) && (turma[xara].notas[CALCULO] >= APROVADO)){
        printf("O melhor aluno é amigo do seu xara\n");
    }else if((turma[xara].notas[PDS] <= APROVADO) && (turma[xara].notas[GAAL] <= APROVADO) && (turma[xara].notas[CALCULO] <= APROVADO)){
        printf("O melhor aluno quer mudar de nome\n");
    }else{
        printf("O melhor aluno evita seu xara\n");
    }
    
}
    
int main(int argc, char** argv) {
    
    struct aluno turma[MAX_ALUNOS];
    int melhor_aluno, xara;
    
    for(int i = 0; i < MAX_ALUNOS; i++){
        scanf("%s %s %d", turma[i].nome, turma[i].sobrenome, &turma[i].matricula);
        getchar();
        for(int j = 0; j < QUANT_MATERIAS; j++){
            scanf("%f", &turma[i].notas[j]);
        }
    }
   
    media(turma);
    melhor_aluno = melhor(turma);
    xara = encontra_xara(turma, melhor_aluno);
    
    printf("Melhor aluno: %s %s\n", turma[melhor_aluno].nome, turma[melhor_aluno].sobrenome);
    printf("Matrícula: %d\nMédia: %.2f\n", turma[melhor_aluno].matricula, turma[melhor_aluno].media);
    printf("Situação: ");
    situacao(turma, melhor_aluno, xara);
  
    return SUCESSO;
}
  
    return SUCESSO;
}
