#include <stdio.h>
#include <string.h>

#define SUCESSO 0
#define MAX 100

int main(int argc, char** argv) {
    
    char string1[MAX], string2[MAX];
    
    fgets(string1, MAX, stdin);
    string1[strlen(string1) - 1] = '\0';
    
    int i = strlen(string1) - 1; 
    int j = 0;
    
    while(j != strlen(string1)){
        string2[j] = string1[i];
        i--;
        j++;
    }
    
    printf("%s", string2);

    return SUCESSO;
}