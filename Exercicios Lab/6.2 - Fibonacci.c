#include <stdio.h>
#include <stdlib.h>

#define MAX 801

int main(int argc, char**argv){
    
    int fib[MAX];
    int n;
    
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i <= MAX; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    scanf("%d", &n);
    
    do{
        printf("\n%d\n", fib[n]);
        scanf("%d", &n);
    }while((n < MAX) && (n > 0));

    return 0;
}