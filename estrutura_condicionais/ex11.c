/*
11) Escreva um programa que leia o número de matrícula, as 3 notas obtidas pelo aluno 
nas 3 avaliações e a média dos exercícios que integram a avaliação, para, então, calcular a 
média de aproveitamento, seguindo a fórmula: 
MT= (nota1 + nota2 + nota 3 + ME) / 4 
 
O algoritmo deve escrever a matrícula do aluno, suas notas, a média dos exercícios, a média 
total e o conceito correspondente e a mensagem 'Aprovado' se o conceito for A, B ou C, e 
'Reprovado' se o conceito for D ou E. 
 
Média de aproveitamento Conceito 
>= 90 A 
>= 75 e < 90 B  
>= 60 e < 75 C  
>= 40 e < 60 D  
< 40 E
*/

#include <stdio.h>
#define GRADES 3

typedef struct {
    int registration;
    int grade[GRADES];
} Student;

int main( ) {
    Student stud;

    printf("Digite o numero da matricula: \n");
    scanf("%d", &stud.registration);

    for (int i = 0; i < GRADES; i++) {
        printf("Digite a nota da avaliação [%d/%d]", i+1, GRADES);
        scanf("%d", &stud.grade[i]);
    }

    int exercises;
    printf("Digite a média dos exercícios: ");
    scanf("%d", &exercises);

    int total = 0;
    for (int i = 0; i < GRADES; i++) {
        total += stud.grade[i];
    }

    int average = (total + exercises) / 4;

    char concept;

    if (average >= 90) {
        concept = 'A';
    } else if (average >= 75) {
        concept = 'B';
    } else if (average >= 60) {
        concept = 'C';
    } else if (average >= 40) {
        concept = 'D';
    } else {
        concept = 'E';
    }

    return 0;
}