/*
3) Faça um programa que leia 2 valores inteiros e chame uma função que 
receba estas 2 variáveis e troque o seu conteúdo, ou seja, esta função é 
chamada passando duas variáveis A e B por exemplo e, após a execução da 
função, A conterá o valor de B e B terá o valor de A.
*/

#include <stdio.h>

void invert_values(int *first_value, int *sec_value) {
    int temp = *sec_value; 
    *sec_value = *first_value;
    *first_value = temp;
}

int main( ) {
    int num_a, num_b; 

    printf("Digite o valor de a: \n");
    scanf("%d", &num_a);

    printf("Digite o valor de b: \n");
    scanf("%d", &num_b);

    printf("O valor de A e B correspondem a %d e %d", num_a, num_b);

    invert_values(&num_a, &num_b);

    printf("O valor de A e B após a inversao correspondem a %d e %d", num_a, num_b);
    return 0; 
}