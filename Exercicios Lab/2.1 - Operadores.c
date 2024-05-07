#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 0 

//Verifica bits de entrada
int verifica(int input1, int input2){
    if ((input1 <= 1) && (input2 <= 1)){
        return 1;
    }
    return 0;
}

//Retorno porta AND
int AND(int input1, int input2){
    return input1 & input2;
}

//Retorno porta OR 
int OR(int input1, int input2){
    return input1 | input2;
}

//Retorno porta XOR 
int XOR(int input1, int input2){
    return input1 ^ input2;
}

int main(int argc, char**argv) {
    
    int input1, input2;
    
    scanf("%d %d", &input1, &input2);
    
    if(verifica(input1, input2)){
        
        printf("AND: %d OR: %d XOR: %d", 
        AND(input1, input2), 
        OR(input1, input2), 
        XOR(input1, input2));
        
    }else{
        printf("Entradas inválidas");
    }
    
    return SUCESSO;
}