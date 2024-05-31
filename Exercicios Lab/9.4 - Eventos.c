#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAM_MAX 100

enum Mes {JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO};

typedef struct Data{
    int dia;
    enum Mes mes;
    int ano;
}Data;

typedef struct Evento{
    char nome[TAM_MAX];
    char local[TAM_MAX];
    Data data;
}Evento;

void cadastrar_eventos(Evento agenda[], int n);
void imprimir_eventos(Evento agenda[], int n, Data d);

int main(int argc, char** argv)
{
    int n;
    struct Evento *agenda;
    struct Data d;
    
    scanf("%d", &n);
    agenda = (Evento*)malloc(n*sizeof(Evento));
    cadastrar_eventos(agenda, n);
    
    scanf("%d %d %d", &d.dia, (int *)&d.mes, &d.ano);
    
    imprimir_eventos(agenda, n, d);
    
    return SUCESSO;
}

/*--------Funções--------*/

void cadastrar_eventos(Evento agenda[], int n){
    
    for(int i = 0; i < n; i++){
        scanf("%s", agenda[i].nome);
        getchar();
        scanf("%s", agenda[i].local);
        getchar();
        scanf("%d %d %d", &agenda[i].data.dia, (int *)&agenda[i].data.mes, &agenda[i].data.ano);
    }
}

void imprimir_eventos(Evento agenda[], int n, Data d){
    
    int num_eventos = 0;
    
    for(int i = 0; i < n; i++){
        if(agenda[i].data.dia == d.dia){
            if(agenda[i].data.mes == d.mes){
                if(agenda[i].data.ano == d.ano){
                    printf("%s %s\n", agenda[i].nome, agenda[i].local);
                    num_eventos++;
                }
            }
        }
    }
    
    if(num_eventos == 0){
        printf("Nenhum evento encontrado\n");
    }
}
