/*
12) Desenvolva um programa que mostre um menu com as quatro operações bases (soma, 
subtração,  multiplicação  e  divisão).  O  usuário  deve  escolher  qual  operação  ele  deseja 
realizar.  Após  esta  escolha,  peça  dois  valores  numéricos  e  realize  a  operação.  Ao  final, 
mostre o resultado da operação.
*/

#include <stdio.h>

float calc(int operation, int num1, int num2) {
    switch (operation) {
        case 1:
            return num1 + num2;
        case 2: 
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            return num1 / num2;
        default:
            return -1;
    }
}

int main( ) {
    int operation, num1, num2;
    do {
        printf("Escolha a operacao desejada: \n");
        printf("[1] - Soma\n");
        printf("[2] - Subtracao\n");
        printf("[3] - Multiplicacao\n");
        printf("[4] - Divisao\n");
        scanf("%d", &operation);   
    } while (operation < 1 || operation > 4);

    printf("Digite o primeiro numero: \n");
    scanf("%d", &num1);

    printf("Digite o segundo numero: \n");
    scanf("%d", &num2);

    float result = calc(operation, num1, num2);

    printf("O resultado da operação corresponde a: %2.f", result);

    return 0;
}