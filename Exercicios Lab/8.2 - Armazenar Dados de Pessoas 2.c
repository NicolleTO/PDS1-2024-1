#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define FALHA 1
#define MAX_PESSOAS 5
#define MAX_TAM 50

typedef struct local{
    char rua[MAX_TAM];
    int numero;
    char estado[MAX_TAM];
}local;

typedef struct pessoa{
    char nome[MAX_TAM];
    int idade;
    float salario;
    local endereco;
}pessoa;

int inserir(struct pessoa person[], int n) {
    
    if (n == MAX_PESSOAS) {
        int c;
        while ((c = getchar()) != '\n');
        printf("Espaco insuficiente\n");
        
    } else {
        scanf("%s %d %f %s %d %s", person[n].nome, &person[n].idade, &person[n].salario, person[n].endereco.rua, &person[n].endereco.numero,  person[n].endereco.estado);
        getchar();
        printf("Registro %s %d %.2f %s %d %s inserido\n", person[n].nome, person[n].idade, person[n].salario, person[n].endereco.rua, person[n].endereco.numero,  person[n].endereco.estado);
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
            printf("Registro %s %d %.2f %s %d %s\n", people[i].nome, people[i].idade, people[i].salario, people[i].endereco.rua, people[i].endereco.numero, people[i].endereco.estado);
            achou = SUCESSO;
        }
    }
    
    if(achou == FALHA){
        printf("Registro ausente\n");
    }
}

void alterar(struct pessoa people[], int n){
    
    char nome[MAX_TAM];
    int achou = FALHA;
    
    scanf("%s", nome);
    getchar();
    
    for(int i = 0; i < n; i++){
        if(strcmp(people[i].nome, nome) == SUCESSO){
            strcpy(people[i].nome, nome);
            scanf("%d %f %s %d %s", &people[i].idade, &people[i].salario, people[i].endereco.rua, &people[i].endereco.numero,  people[i].endereco.estado);
            getchar();
            printf("Registro %s %d %.2f %s %d %s alterado\n", people[i].nome, people[i].idade, people[i].salario, people[i].endereco.rua, people[i].endereco.numero, people[i].endereco.estado);
            achou = SUCESSO;
        }
    }
    
    if(achou == FALHA){
        printf("Registro ausente para alteracao\n");
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
        }else if(strcmp(operacao, "alterar") == SUCESSO){
            alterar(people, n);
        }
    }

    return SUCESSO;
}
