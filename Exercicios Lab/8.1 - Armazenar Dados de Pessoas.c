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

void remover_bn(char * str);

int inserir(struct pessoa person[], int n){

    scanf("%s %d %f", person[n].nome, &person[n].idade, &person[n].salario);
    printf("Registro %s %d %.2f inserido\n", person[n].nome, person[n].idade, person[n].salario);
    n++;

    return n;   
}

void mostrar(struct pessoa person[], char nome[]){

    int achou = FALHA;
    int i = 0;

    do{
        if(strcasecmp(person[i].nome, nome) == SUCESSO){
            printf("Registro %s %d %.2f\n", person[i].nome, person[i].idade, person[i].salario);
            achou = SUCESSO;
        }
        i++;
    }while((achou == FALHA) && (i < MAX_PESSOAS));

    if(achou == FALHA){
        printf("Registro ausente\n");
    }
}
int main(int argc, char** argv) {

    struct pessoa people[MAX_PESSOAS];
    int n = 0;
    char operacao[MAX_TAM], nome[MAX_TAM];

    char lixo_s[1];
    int lixo_n;

    do{
        
        fgets(operacao, MAX_TAM, stdin);
        operacao[strlen(operacao) - 1] = '\0';

        if(strcasecmp(operacao, "inserir") == SUCESSO){
            if(n >= MAX_PESSOAS){
                scanf("%s %d %d", lixo_s, &lixo_n, &lixo_n);
                printf("Espaco insuficiente\n");

            }else{
                n = inserir(people, n);
            }
        }else if(strcasecmp(operacao, "mostrar") == SUCESSO){
            scanf("%s", nome);
            mostrar(people, nome);
        }else if(strcmp(operacao, "") == 0){
            break;
        }
        printf("operacao: %s\n", operacao);
    }while(1);

    return SUCESSO;
}

void remover_bn(char * str)
{
    while(*(str++) != '\n');
    *(--str) = '\0';
}
