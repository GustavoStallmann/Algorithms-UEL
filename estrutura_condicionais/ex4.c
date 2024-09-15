/*
A escola “APRENDER” faz o pagamento de seus professores por hora/aula. Faça um
algoritmo que calcule e exiba o salário de um professor. Sabe-se que o valor da hora/aula
segue a tabela abaixo:
• Professor Nível 1 R$12,00 por hora/aula Professor
• Nível 2 R$17,00 por hora/aula
• Professor Nível 3 R$25,00 por hora/aula
*/

#include <stdio.h>

int calc_salary(int hours, int lesson_level, int* payment) {
    switch (lesson_level) {
        case 1:
            *payment = 12*hours;
            break;
        case 2:
            *payment = 17*hours;
            break;
        case 3:
            *payment = 25*hours;
            break;
        default:
            return 1;
    }
    return 0;
}

int main( ) {
    int hours, lesson_level, payment;

    printf("Digite o numero de horas trabalhadas pelo professor: ");
    scanf("%d", &hours);

    printf("Digite o nivel do professor (1, 2 ou 3): ");
    scanf("%d", &lesson_level);

    if (calc_salary(hours, lesson_level, &payment) == 1) {
        printf("Nivel de professor invalido");
        return 1;
    }

    printf("O salario do professor e: R$%d", payment);
    return 0;
}