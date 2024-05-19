#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA 1
#define MAX_PESSOAS 4
#define MAX_TAM 50

typedef struct pessoa{
    char nome[MAX_TAM];
    int idade;
    float salario;
}pessoa;


int inserir(struct pessoa person[], int n) {
    
    if (n == MAX_PESSOAS) {
        int c;
        while ((c = getchar()) != '\n');
        printf("Espaco insuficiente\n");
        
    } else {
        scanf("%s %d %f", person[n].nome, &person[n].idade, &person[n].salario);
        getchar();
        printf("Registro %s %d %.2f inserido\n", person[n].nome, person[n].idade, person[n].salario);
        n++;
    }
    
    return n;   
}

void mostrar(struct pessoa people[], int n){
    
    char nome[MAX_TAM];
    int achou = FALHA;
    
    fgets(nome, MAX_TAM, stdin);
    nome[strlen(nome) - 1] = '\0';
    
    for(int i = 0; i < n; i++){
        if(strcmp(people[i].nome, nome) == SUCESSO){
            printf("Registro %s %d %.2f\n", people[i].nome, people[i].idade, people[i].salario);
            achou = SUCESSO;
        }
    }
    
    if(achou == FALHA){
        printf("Registro ausente\n");
    }
    
}

int main() {
    
    struct pessoa people[MAX_PESSOAS];
    int n = 0;
    char operacao[MAX_TAM];

    while (1) {

        fgets(operacao, MAX_TAM, stdin);
        operacao[strlen(operacao) - 1] = '\0';

        // Verifica se a entrada é vazia
        //Se sim, finaliza
        if (strcmp(operacao, "") == SUCESSO) {
            break;
        }
        
        if(strcmp(operacao, "inserir") == SUCESSO){
            n = inserir(people, n);
        }else if(strcmp(operacao, "mostrar") == SUCESSO){
            mostrar(people, n);
        }else{
            printf("invalido\n");
        }
    }

    return SUCESSO;
}
