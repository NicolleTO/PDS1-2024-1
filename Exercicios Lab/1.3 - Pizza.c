#include <stdio.h>
#include <math.h>

#define SUCESSO 0
#define PI 3.14
#define PEDACOS 8

void calcula(float diam){
    
    float area, pedaco, raio;
    
    raio = diam/2;
    
    area = PI * (raio*raio);
    pedaco = area/PEDACOS;
    
    area = area * 100;
    area = truncf(area) / 100;
    
    pedaco = pedaco * 100;
    pedaco = truncf(pedaco) / 100;
    
    printf("%.2f\n%.2f\n", area, pedaco);
    
}

int main(int argc, char** argv){
    
    int diam;
    
    scanf("%d", &diam);
    calcula(diam);

    return SUCESSO;
}
