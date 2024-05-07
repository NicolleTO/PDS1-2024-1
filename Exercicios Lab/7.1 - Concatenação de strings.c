#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define MAX 100

void MEU_strcat(char string1[], char string2[]){
    
    int i = strlen(string1);
    int j = 0;
    
    while(string2[j] != '\0'){
        string1[i] = string2[j];
        i++;
        j++;
    }
}

int main(int argc, char** argv) {
    
    char string1[MAX], string2[MAX];
    
    fgets(string1, MAX, stdin);
    string1[strlen(string1) - 1] = '\0';
    
    fgets(string2, MAX, stdin);
    string2[strlen(string2) - 1] = '\0';
    
    MEU_strcat(string1, string2);
    printf("%s", string1);

    return SUCESSO;
}