/*
12) Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui. 
Entre com um caractere (vogal ou consoante) e substitua todas as vogais da 
palavra dada por esse caractere. Ao final, imprima a nova string e o número 
de vogais que ela possui. 
*/

#include <stdio.h>

int main() {
    char string[100], c;
    int i, count = 0;

    printf("Digite uma string: ");
    gets(string);

    printf("Digite um caractere: ");
    scanf("%c", &c);

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
            string[i] = c;
            count++;
        }
    }

    printf("Nova string: %s\n", string);
    printf("Numero de vogais: %d\n", count);

    return 0;
}