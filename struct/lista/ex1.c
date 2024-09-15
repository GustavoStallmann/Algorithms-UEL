/*
1) Implemente um programa que leia o nome, a idade e o endereço de uma
pessoa e armazene esses dados em uma estrutura. Em seguida, imprima na
tela os dados da estrutura lida.
*/

#include <stdio.h>

struct {
    char name[20];
    int age;
    char address[20];
} person;

int main( ) {
    printf("Digite o nome da pessoa: \n");
    setbuf(stdin, NULL);
    gets(person.name);

    printf("Digite a idade da pessoa: \n");
    scanf(" %d", &person.age);

    printf("Digite o endereco da pessoa: \n");
    setbuf(stdin, NULL);
    gets(person.address);

    printf("A pessoa %s mora na rua %s e tem %d anos", person.name, person.address, person.age);
    return 0;
}