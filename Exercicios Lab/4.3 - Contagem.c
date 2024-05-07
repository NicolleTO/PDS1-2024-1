#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void conta(){

  int num = 233;
  
  do{

    printf("%d\n", num);
    
    //se o numero está entre 300 e 400, pulamos de 3 em 3
    if((num >= 300) && (num <= 400)){
      num += 3;
    }else{
      //caso contrário de 5 em 5
      num += 5;
    }
    
    
  }while(num <= 457);
  
}

int main(int argc, char**argv){

    conta();
    
    return SUCESSO;
    
}