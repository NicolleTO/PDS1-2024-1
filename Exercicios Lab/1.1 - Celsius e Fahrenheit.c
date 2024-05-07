#include <stdio.h>

#define SUCESSO 0

float fahrenheit(float cel){
    return 1.8 * cel + 32;
}

int main(int argc, char** argv){
    
    float cel;
    
    scanf("%f", &cel);
    printf("%0.f", fahrenheit(cel));
    
    return SUCESSO;
}