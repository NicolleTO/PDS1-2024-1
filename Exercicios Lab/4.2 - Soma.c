#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

int soma(int num){

    int result = 0;

    for(int i = 0; i <= num; i++){
        result = result + i;
    }
    
    return result;
}

int main(int argc, char**argv){

    int num;

    scanf("%d", &num);
    
    printf("%d", soma(num));

    return SUCESSO;
    
}