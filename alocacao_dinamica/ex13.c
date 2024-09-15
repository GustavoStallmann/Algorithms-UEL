/*
13) Faça um programa que leia dois números N e M e: 
• Aloque espaço e leia uma matriz de inteiros N x M; 
• Aloque espaço e construa uma matriz transposta M x N de inteiros. 
• Mostre as duas matrizes. 
• Localize os três maiores números na primeira matriz e mostre a linha 
e a coluna onde estão.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int **matrix;
    int m, n;
} Matrix; 

void alloc_error( ) {
    printf("Erro: espaço da memória insuficiente!\n");
    exit(1);
}

Matrix create_matrix(int m, int n) {
    Matrix mx = {
        .m = m, 
        .n = n
    };

    mx.matrix = (int **) malloc(mx.m * sizeof(int *));
    if (mx.matrix == NULL) alloc_error();

    for (int line = 0; line < mx.m; line++) {
        mx.matrix[line] = (int *) calloc(sizeof(int), mx.n);
        if (mx.matrix[line] == NULL) alloc_error();
    }

    return mx;
}

Matrix transpose_matrix(Matrix *mx) {
    Matrix mx_t = create_matrix(mx->n, mx->m);

    for (int i = 0; i < mx->m; i++){
        for (int j = 0; j < mx->n; j++) {
            mx_t.matrix[j][i] = mx->matrix[i][j];
        }
    }

    return mx_t;
}

void read_matrix(Matrix *mx) {
    for (int i = 0; i < mx->m; i++) {
        for (int j = 0; j < mx->n; j++) {
            printf("Informe o valor da posição [%d/%d]: \n", i+1, j+1);
            scanf("%d", &mx->matrix[i][j]);
        }
    }
}

void print_matrix(Matrix *mx) {
    for (int i = 0; i < mx->m; i++) {
        for (int j = 0; j < mx->n; j++) {
            printf("[%d]", mx->matrix[i][j]);
        }
        printf("\n");
    }
}

int vec_include_value(int vec[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (vec[i] == value) return 1; 
    }

    return 0; 
}

int *get_three_biggest_numbers(Matrix *mx) {
    int *vec = (int *) malloc(3 * sizeof(int));

    for (int found = 0; found < 3; found++) {
        vec[found] = 0; 

        for (int i = 0; i < mx->m; i++) {
            for (int j = 0; j < mx->n; j++) {
                if (vec_include_value(vec, 3, mx->matrix[i][j])) continue;

                if (vec[found] < mx->matrix[i][j]) {
                    vec[found] = mx->matrix[i][j];
                }
            }
        }
    }

    return vec;
}

int main( ) {
    int m, n;
    printf("Insira a ordem da matriz (mxn): \n");
    scanf("%dx%d", &m, &n);
    
    Matrix mx = create_matrix(m, n);
    read_matrix(&mx);

    printf("Matriz lida: \n");
    print_matrix(&mx);

    Matrix mx_t = transpose_matrix(&mx);
    printf("Matriz lida transposta: \n");
    print_matrix(&mx_t);

    int *result = get_three_biggest_numbers(&mx);
    for (int i = 0; i < 3; i++) {
        printf("[%d]", result[i]);
    }

    return 0;
}