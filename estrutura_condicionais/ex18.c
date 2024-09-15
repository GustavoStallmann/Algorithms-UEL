/*
18) Dados três valores A, B e C, construa um algoritmo que imprima os valores de forma 
descendente (do maior para o menor). 
*/

#include <stdio.h>

int main( ) {
    int vec[3], aux;

    for (int i = 0; i < 3; i++) {
        printf("Digite o valor %d: \n", i+1);
        scanf("%d", &vec[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            if (vec[i] < vec[j]) {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d\n", vec[i]);
    }

    return 0;
}