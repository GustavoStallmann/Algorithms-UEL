/*
12) Faça um programa em C que receba uma frase do usuário e mostre a 
frase, palavra por palavra, uma em cada linha diferente. Esse programa deve 
conter ponteiros na para manusear a string. A frase deve possuir no máximo 
60 caracteres. 
*/

#include <stdio.h>

int get_string_length(char string[]) {
    int length = 0;

    for (int i = 0; string[i] != '\0'; i++, length++);
    return length;
}

void print_word(char string[], int i_start, int i_end) {
    for (int i = i_start; i < i_end; i++)
        printf("%c", string[i]);

    printf("\n");
}

void print_string_words(char string[]) {
    int str_length = get_string_length(string);

    int w_index_start = 0, w_index_end;
    for (int i = 0; i < str_length; i++) {
        char c = *(string + i);
        if (c != ' ' && i != str_length-1) continue;

        print_word(string, w_index_start, i);
        w_index_start = i+1;
    }
}

int main( ) {
    char string[60];

    printf("Digite a sua frase:\n");
    fgets(string, 60, stdin);

    print_string_words(string);
    return 0;
}