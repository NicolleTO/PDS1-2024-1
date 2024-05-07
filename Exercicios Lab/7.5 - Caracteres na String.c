#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char** argv) {
    
    char string1[MAX], c;
    int quant = 0;
    
    fgets(string1, MAX, stdin);
    string1[strlen(string1) - 1] = '\0';
    
    scanf("%c", &c);
    
    for(int i = 0; i < strlen(string1); i++){
        if(string1[i] == c){
            quant++;
        }
    }
    
    printf("%d", quant);
    return SUCESSO;
}