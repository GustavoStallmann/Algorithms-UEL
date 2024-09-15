/*
1) Escreva um programa que calcule a área de um círculo de raio r, testando se o valor do
raio é menor que zero.
*/

#include <stdio.h>
#include <math.h>

const float PI = 3.14;

void calc_circle_area(float circle_radius, float* circle_area) {
    *circle_area = PI * pow(circle_radius, 2);
}

int main( ) 
{
    float circle_radius, circle_area;

    printf("Para comecar digite o raio do circulo:\n");
    scanf("%f", &circle_radius);

    if (circle_radius <= 0) { 
        printf("O raio do circulo deve ser maior do que 0.");
        return 1;
    };

    calc_circle_area(circle_radius, &circle_area);

    printf("\nO circulo de raio: %.2f", circle_radius);
    printf("\nPossui a seguinte area: %.2f", circle_area);
 
    return 0;
}