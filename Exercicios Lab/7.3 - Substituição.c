#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char** argv) {
    
    char string1[MAX];
    char c1, c2;
    int i = 0, achou = 0;
    
    fgets(string1, MAX, stdin);
    string1[strlen(string1) - 1] = '\0';
    
    scanf("%c %c", &c1, &c2);
    
    do{
        if(string1[i] == c1){
            string1[i] = c2;
            achou = 1;
        }
        i++;
    }while((achou != 1) && (i < strlen(string1)));
    
    printf("%s", string1);

    return SUCESSO;
}