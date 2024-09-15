/*
2) Faça um programa que receba do usuário um vetor X com 10 posições. Em 
seguida deverão ser impressos o maior e o menor elemento desse vetor.
*/

#include <stdio.h>
#define VEC_SIZE 10

int main( ) {
    int vec[10];

    for (int i = 0; i < VEC_SIZE; i++){
        printf("Insira um valor [%d/%d]\n", i+1, VEC_SIZE);
        scanf("%d", &vec[i]);
    }  

    int min = vec[0], max = vec[0];
    for (int i = 0; i < VEC_SIZE; i++) {
        if (vec[i] < min) min = vec[i];
        if (vec[i] > max) max = vec[i];
    }

    printf("O maior valor corresponde a: %d\n", max);
    printf("O menor valor corresponde a: %d\n", min);

    return 0;
}