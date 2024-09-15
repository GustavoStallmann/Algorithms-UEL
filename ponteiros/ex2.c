/*
2) Escreva um programa que contenha duas variáveis inteiras. Leia essas 
variáveis  do  teclado.  Em  seguida,  compare  seus  endereços  e  exiba  o 
conteúdo do maior endereço.
*/

#include <stdio.h>

int main( ) {
    int num1, num2; 

    printf("Digite o primeiro numero: \n");
    scanf("%d", &num1);
  
    printf("Digite o primeiro numero: \n");
    scanf("%d", &num2);

    int *p1 = &num1;
    int *p2 = &num2; 

    int *biggest_value = *p1 < *p2? p2: p1; 

    printf("O maior valor corresponde a: %d", *biggest_value);
    return 0;
}
