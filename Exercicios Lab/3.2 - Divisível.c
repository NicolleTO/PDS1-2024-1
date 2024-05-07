#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 0 

int main(int argc, char**argv) {
   
    int x, y, z;
    
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    
    if((x % y)  == 0){
       if((x % z) == 0){
           printf("O número é divisível");
       }else{
           printf("O número não é divisível");
       }
    }else{
        printf("O número não é divisível");
    }
    
    return SUCESSO;
}