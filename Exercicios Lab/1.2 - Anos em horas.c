#include <stdio.h>

#define SUCESSO 0

long int horas(int x){
    return x * 365 * 24;
}

int main(int argc, char** argv){
    
    int x;
    scanf("%d", &x);
    printf("%ld", horas(x));
    
    return SUCESSO;
}
