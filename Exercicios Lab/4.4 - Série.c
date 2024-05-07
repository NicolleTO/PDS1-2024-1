#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void conta(int n, int x0, int x1){
  
  printf("x0: %d\n", x0);
  printf("x1: %d\n", x1);
  
  int xn;
  
  for(int i = 2; i <= n; i++){
    
    //x0 = x_(n-2) | x1 = x_(n-1)
    
    xn = (4*x1) - (2*x0);
    
    x0 = x1;
    x1 = xn;
    
    printf("x%d: %d\n", i, xn);
  }
}

int main(int argc, char**argv){

  int n, x0, x1;
  
  scanf("%d", &n);
  scanf("%d", &x0);
  scanf("%d", &x1);
  
  conta(n, x0, x1);
  
  return SUCESSO;
}