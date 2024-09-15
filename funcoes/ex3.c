/*
3) Elabore uma função que receba três notas de um aluno como parâmetros
e uma letra. Se a letra for “A”, a função deverá calcular a média aritmética
das notas do aluno; se for “P”, deverá calcular a média ponderada, com pesos
5, 3 e 2. Retorne a média calculada para o programa principal.
*/

#include <stdio.h> 

float calc_student_average(char calc_type, float grade[3]) {
    if (calc_type == 'A') {
        return (grade[0] + grade[1] + grade[2]) / 3;
    } else if (calc_type == 'P') {
        return (grade[0] * 5) + (grade[1] * 3) + (grade[2] * 2) / (5+3+2);
    }
}

int main( ) {
    char average_type;
    float grades[3];

    printf("Escolha o tipo de media: \n\t[P] = ponderada \n\t [A] = aritmetica\n");
    scanf("%c", &average_type);

    for (int i =0; i < 3; i++) {
        printf("Insira a nota do aluno [%d/%d]:\n", i+1, 3);
        scanf("%f", &grades[i]);
    }

    float average = calc_student_average(average_type, grades);
    printf("A media do aluno foi: %0.2f", average);
    return 0;
}