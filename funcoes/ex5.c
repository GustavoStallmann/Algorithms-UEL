/*
5) Elabore uma função que receba como parâmetro um valor inteiro n e gere
como saída um triângulo lateral formado por asteriscos conforme o exemplo
a seguir, em que usamos n = 4:
*/

#include <stdio.h>

int create_triangle(int t_length, int actual, int top_achieved) {
    printf("\n");

    if (actual == 0 && top_achieved) {
        return 0;
    }   

    for (int i = 0; i < actual; i++) printf("*");

    if (actual < t_length && !top_achieved) actual++;
    if (top_achieved) actual--;

    if (actual == t_length) {
        top_achieved = 1;
    }
    
    return create_triangle(t_length, actual, top_achieved);
} 

int main ( ) {
    int t_length;
    printf("Informe o tamanho do triangulo: \n");
    scanf("%d", &t_length);

    create_triangle(t_length, 1, 0);
    return 0;
}