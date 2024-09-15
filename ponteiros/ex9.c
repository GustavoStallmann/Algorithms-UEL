/*
9) Crie uma função que receba como parâmetro um vetor e o imprima. Não 
utilize índices para percorrer o vetor, apenas aritmética de ponteiros.
*/

#include <stdio.h>

const int VEC_SIZE = 5; 

void print_vector(int vec[], int vec_size) {
	for (int i = 0; i < vec_size; i++)
		printf("[%d]", *(vec + i));
}

void fill_vector(int vec[], int vec_size) {
	for (int i = 0; i < vec_size; i++) {
        printf("Informe o valor para a posição [%d] do vetor:\n", i);
        scanf("%d", (vec + i));
    }
}

int main( ) {
    int vec[VEC_SIZE];

    fill_vector(vec, VEC_SIZE);
    print_vector(vec, VEC_SIZE);
    return 0;
}