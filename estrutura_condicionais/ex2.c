/*
2) Faça um programa para verificar se determinado número inteiro lido é divisível por 3 ou
5, mas não simultaneamente pelos dois.
*/

#include <stdio.h>

int test_divisibility(int number, int test_number) {
    return (number % test_number) == 0;
}

int main( ) {
    int number;

    printf("Digite um numero para testar sua divisibilidade pelo numero 5 e 3:");
    scanf("%d", &number);

    int divided_by_five = test_divisibility(number, 5);
    int divided_by_three = test_divisibility(number, 3);
 
    if ((divided_by_five || divided_by_three) && !(divided_by_five && divided_by_three)) {
        printf("O numero: %d pode ser dividido por %d, mas nao por 5 e 3 simultaneamente",
            number,
            (divided_by_five == 1? 5: 3)
        );
    } else { 
        printf("O numero: %d pode ser dividido por 5 e 3 simultaneamente", number);
    }

    return 0;
}