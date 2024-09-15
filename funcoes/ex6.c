/*
6) Faça uma função que calcule e retorne o número neperiano e,
e = 2,71828183, usando a série a seguir:

A função deve ter como parâmetro o número de termos que serão somados,
n. Note que quanto maior esse número, mais próxima do valor e estará a
resposta.
*/

#include <stdio.h>

float calc_neperian(int parameters, int number) {
    if (parameters == 0) {
        return 1;
    }
    
    return 1 + (number / parameters) * calc_neperian(parameters - 1, number);
}

int main( ) {
    int parameters, number; 

    printf("Informe o numero de parametros para calcular o numero neperiano: \n");
    scanf("%d", parameters);

    printf("Informe o numero a ser calculado: \n");
    scanf("%d", number);

    float result = calc_neperian(parameters, number);
    printf("O resultado corresponde a: %d", result);

    return 0;
}