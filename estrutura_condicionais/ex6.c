/*
6) Faça um programa que leia o salário de um trabalhador e o valor da prestação de um
empréstimo. Se a prestação:
• For maior que 20% do salário, imprima: “Empréstimo não concedido.”
• Caso contrário, imprima: “Empréstimo concedido.”
*/

#include <stdio.h>

int main( ) {
    float salary, loan;

    printf("Digite o salario do trabalhador: ");
    scanf("%f", &salary);

    printf("Digite o valor da prestacao do emprestimo: ");
    scanf("%f", &loan);

    if (loan > 0.2*salary) {
        printf("Emprestimo nao concedido.");
    } else {
        printf("Emprestimo concedido.");
    }
    return 0;
}