/*
3) Usando o comando switch, escreva um programa que leia um inteiro entre 1 e 7 e
imprima o dia da semana correspondente a esse número. Isto é, domingo, se 1, segunda-feira, se 2, e assim por diante.
*/
#include <stdio.h>

int main() {
    int day;
    char days[7][20] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};

    printf("Digite um numero entre 1 e 7: ");
    scanf("%d", &day);

    if (day < 1 || day > 7) {
        printf("Número inválido\n");
        return 1;
    }

    printf("O dia é %s\n", days[day-1]);

    return 0;
}
