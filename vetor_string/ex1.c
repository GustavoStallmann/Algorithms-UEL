/*
1) Crie um programa que leia do teclado seis valores inteiros e em seguida
mostre na tela os valores lidos na ordem inversa.
*/

#include <stdio.h>
const int VECTOR_SIZE = 6;

int main( ) {
    int i, vec[VECTOR_SIZE];
    for (i = 0; i < VECTOR_SIZE; i++) {
        printf("Informe um valor inteiro [%d/%d]: \n", i, VECTOR_SIZE);
        scanf("%d", &vec[i]);
    }
    
    printf("Vetor lido: \n");
    for (i = 0; i < VECTOR_SIZE; i++) {
        printf("[%d]", vec[i]);
    };

    return 0;
}