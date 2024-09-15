/*
4) Escreva uma função que receba um número inteiro positivo e retorne o
maior fator primo desse número.
*/

#include <stdio.h>

int biggestPrimeFactor(int number) {
    int i = 2;
    while (number % i != 0) {
        i++;
    }
    if (number == i) {
        return i;
    }
    return biggestPrimeFactor(number / i);
}

int main ( ) {
    int number; 

    printf("Insira um numero inteiro positivo: \n");
    scanf("%d", &number);

    printf("O maior fator primo de %d é %d\n", number, biggestPrimeFactor(number));
    return 0;
}