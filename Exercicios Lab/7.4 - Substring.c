#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char** argv) {
    
    char string1[MAX], string2[MAX];
    int substring = 0;
    
    fgets(string1, MAX, stdin);
    string1[strlen(string1) - 1] = '\0';
    
    fgets(string2, MAX, stdin);
    string2[strlen(string2) - 1] = '\0';
    
   
    
    int i = 0;
    while(i < strlen(string1) && (substring == 0)){
        if(string1[i] == string2[0]){
            printf("entrou\n");
            for(int j = 0; j < strlen(string2); j++){
                int i_t = i;
                if(string1[i] != string2[j]){
                    printf("%c - %c / diferente\n", string1[i], string2[j]);
                    substring = 0;
                    i = i_t;
                    break;
                }else{
                    printf("%c - %c / igual\n", string1[i], string2[j]);
                    i++;
                    substring = 1;
                }
            }
        }
        i++;
    };
    
    if(substring == 0){
        printf("Não é substring");
    }else{
        printf("É substring");
    }

    return SUCESSO;
}