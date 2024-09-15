/*
5) Escreva uma função que receba um valor inteiro positivo N por parâmetro
e retorne o ponteiro para um vetor de tamanho N alocado dinamicamente.
Se N for negativo ou igual a zero, um ponteiro nulo deverá ser retornado.*/

#include <stdio.h>
#include <stdlib.h>

int *create_vector(int N) {
    int *vec; 
    if (N <= 0) return vec; 
        
    vec = (int *) malloc(N * sizeof(int));
    if (vec == NULL) {
        printf("Memoria insuficiente");
        exit(1);
    }

    return vec;
}

int main( ) {
    int N; 

    printf("Informe o tamanho do vetor a ser criado: \n");
    scanf("%d", &N);

    int *vec = create_vector(N);

    free(vec);
    return 0;
}
