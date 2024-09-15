/*
6) Crie uma função que receba uma string e retorne o ponteiro para essa
string invertida
*/

#include <stdio.h>
#include <stdlib.h>

int get_string_length(char string[]) {
    int count;
    for (count = 0; *(string + count) != '\0'; count++);

    return count-1;
}

char *invert_string(char string[]) {
    int str_size = get_string_length(string);
    char *inverted_string = (char *) malloc((str_size + 1) * sizeof(char));
    if (inverted_string == NULL) {
        printf("Memoria insuficiente");
        exit(1);
    }
    
    int current_char = 0;
    for(int i = str_size-1; i >= 0; i--, current_char++) {
        *(inverted_string + current_char) = *(string + i);
    }

    return inverted_string;
}

int main( ) {
    char string[20]; 

    printf("Digite um texto: \n");
    setbuf(stdin, NULL);
    fgets(string, 20, stdin);

    char *inverted_string = invert_string(string);
    printf("%s", inverted_string);

    free(inverted_string);
    return 0;
}
