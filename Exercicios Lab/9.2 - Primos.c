#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

int eh_primo(int x);
void primos(int m, int *p1, int *p2);
 
int main(int argc, char** argv)
{
    int m, p1, p2;
    
    scanf("%d", &m);
    
    primos(m, &p1, &p2);
    
    printf("%d\n%d", p1, p2);
    return SUCESSO;
}

/*--------Funções--------*/

int eh_primo(int x){
    
    int primo = 1;
    for(int i = 2; i <= (x/2); i++){
        if(x % i == 0){
            primo = 0;
            break;
        }
    }
    return primo;
}

void primos(int m, int *p1, int *p2){
    
    for(int i = m - 1; i > 0; i--){
        if(eh_primo(i) == 1){
            *p1 = i;
            break;
        }
    }
    
    m++;
    do{
        if(eh_primo(m) == 1){
            *p2 = m;
        }else{
            m++;
        }
    }while(eh_primo(*p2) != 1);
}
