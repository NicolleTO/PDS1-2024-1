#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Constantes
#define SUCESSO 0
#define FALHA 1

#define RIGHT ')'
#define LEFT '('
#define SAIR '!'

//O inicio...
int main(int argc, char** argv) {

	Pilha_lst* left;

	char dado, lixo;
	int tam = 0;

	left = pilha_lst_cria();

	printf("\n\nDigite sua expressao (! para sair) - ");

	do {
		scanf(" %c", &dado);

		//Se temos '(', adiciona na pilha
		if (dado == LEFT) {
			pilha_lst_push(left, dado);
		}
		//Se temos ')'...
		else if (dado == RIGHT) {
			//... e uma pilha vazia, caracter perdido
			if (pilha_lst_vazia(left) == FALHA) {
				tam++;
			}
			else {
				//..e uma pilha cheia, remove seu par
				lixo = pilha_lst_pop(left);
			}
		}
		else if (dado != SAIR) {
			printf("\n\nCaracter inv�lido, tente novamente\n\n");
			return SUCESSO;
		}
	} while (dado != SAIR);

	//Se n�o temos caracteres perdidos e temos uma pilha vazia
	if (tam == 0 && pilha_lst_vazia(left) == FALHA) {
		printf("\n\nExpress�o bem formada!\n\n");
	}
	else {
		//Se n�o
		printf("\n\nExpress�o mal formada!\n\n");
	}

	//Libera a mem�ria
	pilha_lst_libera(left);

	//Se chegamos at� aqui, deu tudo certo!!
	return SUCESSO;
}