#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0


int main(int argc, char**argv){

  int num, i = 1;
  int mult2 = 0, mult3 = 0, mult5 = 0, mult_all = 0;
  
  scanf("%d", &num);

  //Encontra Múltiplos
  while(i <= num){
    
    if((i % 2) == 0){
      mult2++;    
    }
    
    if((i % 3) == 0){
      mult3++;    
    }
    
    if((i % 5) == 0){
      mult5++;    
    }

    //multiplos de 2, 3 e 5 -> multiplos de 30
    if((i % 30) == 0){
      mult_all++;    
    }
    
    
    i++;
  }
  printf("Múltiplos de 2: %d\nMúltiplos de 3: %d\nMúltiplos de 5: %d\nMúltiplos de todos: %d",
  mult2, mult3, mult5, mult_all);
  
  return SUCESSO;
}