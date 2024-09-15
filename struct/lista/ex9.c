/*
9) Crie uma estrutura representando um aluno de uma disciplina. Essa
estrutura deve conter o número de matrícula do aluno, seu nome e as
notas de três provas. Agora, escreva um programa que leia os dados de
cinco alunos e os armazene nessa estrutura. Em seguida, exiba o nome e as
notas do aluno que possui a maior média geral dentre os cinco.
*/

#include <stdio.h>

#define STUDENTS 5
#define TESTS 3

typedef struct {
    int grade;
} Test;

typedef struct {
    int registration;
    char name[50];
    Test tests[TESTS];
} Student;

float get_average( Student student ) {
    int grade_sum = 0;

    for ( int i = 0; i < TESTS; i++ ) {
        grade_sum += student.tests[i].grade;
    }

    return (float) grade_sum / TESTS;
}

int main( ) {
    Student students[STUDENTS];

    printf("Entre com os dados dos alunos:\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("\nAluno [%d/%d]", i+1, STUDENTS);
        printf("\nNumero da matricula: \n");
        scanf("%d", &students[i].registration);

        printf("Nome: \n");
        setbuf(stdin, NULL);
        gets(students[i].name);

        for (int j = 0; j < TESTS; j++) {
            printf("Nota da prova %d: \n", j+1);
            scanf("%d", &students[i].tests[j].grade);
        }
    }

    int highest_average = 0;
    int highest_average_index = 0;
    for (int i = 0; i < STUDENTS; i++) {
        float average = get_average(students[i]);
        if (average > highest_average) {
            highest_average = average;
            highest_average_index = i;
        }
    }

    printf("Aluno com a maior media geral: %s\n", students[highest_average_index].name);
    printf("Media: %0.2f\n", highest_average);
    
    return 0;
}