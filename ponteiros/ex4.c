/*
4) Elaborar um programa que leia dois valores inteiros (A e B). Em seguida 
faça uma função que retorne a soma do dobro dos dois números lidos. A 
função devera ́armazenar o dobro de A na própria variável A e o dobro de B 
na própria variável B.
*/

#include <stdio.h>

void double_int(int *integer) {
    *integer = *integer*2;
}

int sum_int_double(int *first_value, int * sec_value) {
    double_int(first_value);
    double_int(sec_value);

    return *first_value + *sec_value;
}

int main( ) {
    int num_a, num_b; 

    printf("Digite o valor de a: \n");
    scanf("%d", &num_a);

    printf("Digite o valor de b: \n");
    scanf("%d", &num_b);
    
    int result = sum_int_double(&num_a, &num_b);
    printf("O resultado da soma do dobro A com a soma do dobro de B corresponde a: %d", result);
    
    return 0;
}