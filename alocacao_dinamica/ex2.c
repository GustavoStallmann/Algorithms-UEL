/*
2) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, 
a idade e o endereço de uma pessoa. Agora, escreva uma função que receba 
um  inteiro  positivo  N  e  retorne  o  ponteiro  para  um  vetor  de  tamanho  N, 
alocado  dinamicamente,  dessa  estrutura.  Solicite  também  que  o  usuário 
digite os dados desse vetor dentro da função. 
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    char address[30];
} Register;

int main( ) {
    int N;
    printf("Informe a quantidade de cadastros: \n");
    scanf("%d", &N);

    Register *registers = (Register *) malloc(N * sizeof(Register));
    if (registers == NULL) {
        printf("Falha ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        printf("Cadastro [%d/%d]\n", i+1, N);

        printf("Insira o nome da pessoa:\n");
        setbuf(stdin, NULL);
        fgets(registers[i].name, 20, stdin);

        printf("Insira a idade: \n");
        setbuf(stdin, NULL);
        scanf("%d", &registers[i].age);

        printf("Insira o endereço: \n");
        setbuf(stdin, NULL);
        fgets(registers[i].address, 30, stdin);
    }

    printf("CADASTROS: \n");
    for (int i = 0; i < N; i++) {
        printf("\t|Nome: %s", registers[i].name);
        printf("\t|Idade: %d", registers[i].age);
        printf("\t|Endereco: %s", registers[i].address);
    }

    return 0;
}