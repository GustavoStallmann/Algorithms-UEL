/*
13) Faça um programa em C que receba uma frase qualquer fornecida pelo 
usuário,  que  calcule  e  mostre  quantos  caracteres  essa  frase  possui.  Esse 
programa deve conter ponteiros para manusear a string. A frase deve possuir 
no máximo 50 caracteres. 
*/

#include <stdio.h>

int print_string_length(char string[]) {
    int length = -1;

    for (int i = 0; string[i] != '\0'; i++, length++);
    printf("A string possui %d caracteres\n", length);
}

int main( ) {
    char string[50];

    printf("Insira um texto: \n");
    fgets(string, 50, stdin);

    print_string_length(string);
    return 0;
}