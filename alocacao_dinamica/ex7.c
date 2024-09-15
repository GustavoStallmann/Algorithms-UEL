/*7) Escreva uma função que receba um valor inteiro positivo N por parâmetro
e retorne o ponteiro para um vetor de tamanho N alocado dinamicamente.
Esse vetor deverá ter os seus elementos preenchidos com certo valor,
também passado por parâmetro. Se N for negativo ou igual a zero, um
ponteiro nulo deverá ser retornado.*/

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

void fill_vector(int *vec, int size, int value) {
    for (int i = 0; i < size; i++)
        *(vec + i) = value;
}

void print_vector(int *vec, int size) {
    for (int i = 0; i < size; i++)
        printf("[%d]", *(vec + i));
}

int main( ) {
    int N; 

    printf("Informe o tamanho do vetor a ser criado: \n");
    scanf("%d", &N);

    int value;
    int *vec = create_vector(N);

    printf("Informe o valor que preenchera o vetor: \n");
    scanf("%d", &value);

    fill_vector(vec, N, value);
    print_vector(vec, N);

    free(vec);
    return 0;
}
