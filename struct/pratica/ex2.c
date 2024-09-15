#include <stdio.h>

const int QTD_ESTUDANTES = 2;
const int EXAM_AMMOUNT = 3;

struct Estudante {
    int matricula;
    char nome[20];
    float notas[3]; 
    float media;
};

typedef struct Estudante estudante;

int getHighestGrade(estudante estudantes[], int exame) {
    int highest_index = 0;

    for (int i = 0; i < QTD_ESTUDANTES; i++) {
        if (estudantes[i].notas[exame] > estudantes[highest_index].notas[exame]) {
            highest_index = i;
        }   
    }

    return highest_index;
}

void calcMedia(struct Estudante estudantes[]) {
    for (int i = 0; i < QTD_ESTUDANTES; i++) {
        float somaNotas;
        for (int j = 0; j < EXAM_AMMOUNT; j++) {
            somaNotas += estudantes[i].notas[j];
        }

        float media = somaNotas / EXAM_AMMOUNT;
        estudantes[i].media = media;
    }
}

int main( ) {
    struct Estudante estudantes[QTD_ESTUDANTES];
    for (int i = 0; i < QTD_ESTUDANTES; i++) {
        printf("Digite o numero da matricula do %do estudante\n", i+1);
        scanf(" %d", &estudantes[i].matricula); 

        printf("Digite o nome da pessoa: \n");
        setbuf(stdin, NULL);
        gets(estudantes[i].nome);

        for (int j = 0; j < 3; j++) {
            printf("Digite a nota das avaliacoes [%d/%d]: \n", j+1, EXAM_AMMOUNT);
            scanf(" %f", &estudantes[i].notas[j]);
        }
    }

    printf("A maior nota foi do aluno: %s", estudantes[getHighestGrade(estudantes, 2)].nome);
    return 0;
}