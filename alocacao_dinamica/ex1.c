/*
1)  Crie  uma  estrutura  representando  um  aluno  de  uma  disciplina.  Essa 
estrutura deve conter o número de matrícula do aluno, seu nome e as notas 
de três provas. Escreva um programa que mostre o tamanho em byte dessa 
estrutura.
*/

#include <stdio.h>

typedef struct {
    int registration;

    char name[20];
    int grade[3];
} Student;

int main( ) {
    printf("O tamanho da estrutura de aluno corresponde a: %d", sizeof(Student));

    return 0;
}
