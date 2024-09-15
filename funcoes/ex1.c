/*
1) Escreva uma função que receba por parâmetro a altura e o raio de um
cilindro circular e retorne o volume desse cilindro. O volume de um cilindro
circular é calculado por meio da seguinte fórmula:
*/
#include <stdio.h>
#include <math.h>

const float PI = 3.1414592;

float calc_cilinder_area(float base_radius, float height) {
    float base_area = PI * sqrt(base_radius);
    
    return base_area * height;
}

int main( ) {
    float base_radius, height;
    printf("Informe a area da base do cilindro: \n");
    scanf("%f", &base_radius);

    printf("Informe a altura do circulo: \n");
    scanf("%f", &height);

    float cilinder_area = calc_cilinder_area(base_radius, height);
    printf("A area do cilindro corresponde a: %0.2f", cilinder_area);
    return 0;
}