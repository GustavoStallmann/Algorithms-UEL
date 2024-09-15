/*
13) Faça um programa que leia uma string e a imprima de trás para a frente
*/

#include <stdio.h>
#define TEXT_SIZE 20

int get_last_string_char_index(char text[]) {
    int last_index; 
    for (int i = 0; text[i] != '\0'; i++) last_index = i;

    return last_index;
}
void print_inverted_text(char text[]) {
    int last_char = get_last_string_char_index(text);

    for (int i = last_char; i >= 0; i--) printf("%c", text[i]); 
}

int main( ) {
    char text[TEXT_SIZE];

    printf("Insira o texto: \n");
    fgets(text, TEXT_SIZE, stdin);

    print_inverted_text(text);
    
    return 0;
}