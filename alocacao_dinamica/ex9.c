/*9) Escreva uma função que receba como parâmetro duas matrizes, A e B, e
seus tamanhos. A função deve retornar o ponteiro para uma matriz C, em
que C é o produto da multiplicação da matriz A pela matriz B. Se a
multiplicação das matrizes não for possível, retorne um ponteiro nulo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int m, n; 
    int **matrix;
} Matrix; 

void alloc_error( ) {
    printf("Espaço da memória insuficiente!\n");
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

Matrix create_matrix_from_input( ) {
    int m, n; 

    printf("Digite o numero de linhas da matriz: \n");
    scanf("%d", &m);

    printf("Digite o numero de colunas da matriz: \n");
    scanf("%d", &n);

    return create_matrix(m, n);
}

void free_matrix(Matrix mx) {
    for (int i = 0; i < mx.m; i++) {
            free(mx.matrix[i]);
    }

    free(mx.matrix);
}

void read_matrix(Matrix mx) {
    for (int i = 0; i < mx.m; i++) {
        for (int j = 0; j < mx.n; j++) {
            printf("Informe o valor da posição [%d/%d]: \n", i+1, j+1);
            scanf("%d", &mx.matrix[i][j]);
        }
    }
}

void print_matrix(Matrix mx) {
    for (int i = 0; i < mx.m; i++) {
        for (int j = 0; j < mx.n; j++) {
            printf("[%d]", mx.matrix[i][j]);
        }
        printf("\n");
    }
}

Matrix matrix_multiply(Matrix A, Matrix B) {
    if (A.n != B.m) {
        Matrix empty_matrix = {.matrix = NULL, .m = 0, .n = 0};
        return empty_matrix;
    }

    Matrix result = create_matrix(A.m, B.n);
    
    for (int i = 0; i < A.m; i++) {
        for (int j = 0; j < B.n; j++) {
            for (int k = 0; k < A.n; k++) {
                result.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
            }
        }
    }

    return result;
}

int main( ) {   
    Matrix A = create_matrix_from_input();
    read_matrix(A);
    print_matrix(A);

    Matrix B = create_matrix_from_input();
    read_matrix(B);
    print_matrix(B);

    Matrix result = matrix_multiply(A, B);
    if (!result.m || !result.n) printf("Não é possível multiplicar as matrizes.\n");
    print_matrix(result);

    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    return 0;
}
