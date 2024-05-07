#include <stdio.h>
#define SUCESSO 0

int main(int argc, char** argv)
{
    //valor inicial da conta
    float valor = 500.00;
    
    //segundo mês
    valor += (valor * 0.01);
    valor += 200.00;
    
    //terceiro mês
    valor += (valor * 0.01);
    valor -= 50.00;
    
    //quarto mês
    valor += (valor * 0.01);
    
    printf("%.2f", valor);

    return SUCESSO;
}
