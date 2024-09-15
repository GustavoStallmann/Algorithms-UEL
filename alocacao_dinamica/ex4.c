/*
4) Escreva um programa que aloque dinamicamente uma matriz de inteiros. 
As  dimensões  da  matriz  deverão  ser  lidas  do  usuário.  Em  seguida,  escreva 
uma função que receba um valor e retorne 1, caso o valor esteja na matriz, 
ou retorne 0, no caso contrário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void print_matrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
}

bool search_value_in_matrix(int **matrix, int m, int n, int value) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == value) {
                return true; 
            }
        }
    }

  return false;
}

void free_matrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);       
    }

    free(matrix);
}

int main( ) {
    int m, n;
    printf("Insira a quantidade de linhas da matriz: \n");
    scanf("%d", &m);

    printf("Insira a quantidade de colunas da matriz: \n");
    scanf("%d", &n);

    int **matrix = (int**) malloc(m * sizeof(int *));
    if (matrix == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memoria insuficiente.\n");
            exit(1);
        }

        for (int j = 0; j < n; j++) {
            printf("Insira o valor para a posição [%d|%d]:\n", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int number;
    printf("Informe o valor a ser verificado: \n");
    scanf("%d", &number);

    print_matrix(matrix, m, n);
  
    bool result = search_value_in_matrix(matrix, m, n, number);
    if (result) {
      printf("A matriz contem o numero informado\n");
    } else {
      printf("A matriz nao contem o numero informado");
    } 

    free_matrix(matrix, m, n);

    return 0;
}
