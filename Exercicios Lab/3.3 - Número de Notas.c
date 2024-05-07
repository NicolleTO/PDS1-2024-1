#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 0 

int main(int argc, char**argv) {
   
    int valor;
    int cem, cinq, vint, dez, cinco, dois, um;

    scanf("%d", &valor);
    
    cem = valor/100;
    valor = valor - (cem*100);
    
    cinq = valor/50;
    valor = valor - (cinq*50);
    
    vint = valor/20;
    valor = valor - (vint*20);
    
    dez = valor/10;
    valor = valor - (dez*10);
    
    cinco = valor/5;
    valor = valor - (cinco*5);
    
    dois = valor/2;
    valor = valor - (dois*2);
    
    um = valor/1;
    
    printf("100: %d\n 50: %d\n 20: %d\n 10: %d\n 5: %d\n 2:%d\n 1:%d", cem, cinq, vint, dez, cinco, dois, um);
    
    
    return SUCESSO;
}