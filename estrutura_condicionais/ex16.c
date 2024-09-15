/*
16) Escrever um algoritmo que lê um valor em reais e calcule qual o menor número possível 
de notas de 100, 50, 10, 5 e 1 em que o valor lido pode ser decomposto. Escrever o valor 
lido e a relação de notas necessárias. 
*/

#include <stdio.h>

int main() {
    int value, notes100, notes50, notes10, notes5, notes1;

    printf("Insira um valor em reais: ");
    scanf("%d", &value);

    notes100 = value / 100;
    value = value % 100;

    notes50 = value / 50;
    value = value % 50;

    notes10 = value / 10;
    value = value % 10;

    notes5 = value / 5;
    value = value % 5;

    notes1 = value;

    printf("Notas de 100: %d\n", notes100);
    printf("Notas de 50: %d\n", notes50);
    printf("Notas de 10: %d\n", notes10);
    printf("Notas de 5: %d\n", notes5);
    printf("Notas de 1: %d\n", notes1);

    return 0;
}