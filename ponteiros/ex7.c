/*
7) Elabore uma função que receba duas strings como parâmetros e verifique 
se a segunda string ocorre dentro da primeira. Use aritmética de ponteiros 
para acessar os caracteres das strings
*/

#include <stdio.h>

int get_string_size(char *str) {
    int size = 0;
    for (char *c = str; *(c + size + 1 ) != '\0'; size++);

    return size;
}

int check_string_inclusion(char *str1, char *str2) {
    int check_string_size = get_string_size(str2);
    int equals = 0;

    for (char *c = str1; *(c + equals) != '\0'; c++) {
        char current_char = *(str2 + equals);
        if (*c == current_char) {
            equals++;
            continue;
        }

        equals = 0; 
    }

    return equals != 0;
}

int main( ) {
    char str1[20], str2[20];

    printf("Digite a primeira string:\n");
    fgets(str1, 20, stdin);

    printf("Digite a segunda string:\n");
    fgets(str2, 20, stdin);

    int result = check_string_inclusion(str1, str2);
    printf(
        result? 
        "A primeira string contém a segunda": 
        "A primeira string não contém a segunda"
    );

    return 0;
}
