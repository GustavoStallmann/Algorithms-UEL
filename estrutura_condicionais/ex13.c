/*
13) Faça um Programa que peça os 3 lados de um triângulo. O programa deverá informar 
se os valores podem ser um triângulo. Indique, caso os lados formem um triângulo, se o 
mesmo é: equilátero, isósceles ou escaleno. 
 
Dicas: Três lados formam um triângulo quando a soma de quaisquer dois lados for maior 
que o terceiro; 
• Triângulo Equilátero: três lados iguais; 
• Triângulo Isósceles: quaisquer dois lados iguais; 
• Triângulo Escaleno: três lados diferentes; 
*/

#include <stdio.h>

int count_equal_sides(int triangle[3]) {
    int equal_sides = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (triangle[i] == triangle[j]) {
                equal_sides++;
            }
        }
    }

    return equal_sides;
}

int main( ) {
    int triangle[3];
    for (int i = 0; i < 3; i++) {
        printf("Informe o tamanho do lado do triangulo [%d/%d]\n", i+1, 3);
        scanf("%d", &triangle[i]);
    }

    int equal_sides = count_equal_sides(triangle);
    if (equal_sides == 3 ) {
        printf("O triangulo e equilatero");
    } else if (equal_sides == 2) {
        printf("O triangulo e isosceles");
    } else {
        printf("O triangulo e escaleno");
    }

    return 0;
}