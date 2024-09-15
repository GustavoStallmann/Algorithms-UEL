/*9) Escreva uma função que receba como parâmetro duas matrizes, A e B, e
seus tamanhos. A função deve retornar o ponteiro para uma matriz C, em
que C é o produto da multiplicação da matriz A pela matriz B. Se a
multiplicação das matrizes não for possível, retorne um ponteiro nulo*/

#include <stdio.h>
#include <stdlib.h>

int **matrix_multiply(int m_size, int **A, int **B) {
    int **result = (int **) malloc(m_size * sizeof(int *));
    for (int i = 0; i < m_size; i++) {
        *(result + i) = (int *) malloc(m_size * sizeof(int));
    }

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m_size; k++) {
              	result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int **create_matrix(int m_size) {
  int **matrix = (int **) malloc(m_size * sizeof(int *));
  if (matrix == NULL) {
    printf("Memoria insuficiente");
    exit(1);
  }

  for (int i = 0; i < m_size; i++) {
    *(matrix + i) = (int *) malloc(m_size * sizeof(int));
	if (*(matrix + i) == NULL) { 
		printf("Memoria insuficiente");
		exit(1);
	}
  }

  return matrix;
}

void read_matrix(int **matrix, int m_size) {
    for (int row = 0; row < m_size; row++) {
        for (int col = 0; col < m_size; col++) {
          printf("Insira o valor para a posição [%d][%d]", row+1, col+1);
          scanf("%d", *(matrix + row) + col);
        }
    }
}

void print_matrix(int **matrix, int m_size) {
	for (int row = 0; row < m_size; row++) {
		for (int col = 0; col < m_size; col++) {
			printf("[%d]", *(*(matrix + row) + col));
		}

		printf("\n");
	}
}

int main( ) {
    int m_size = 3;
    
    int **m_a = create_matrix(m_size);
    int **m_b = create_matrix(m_size);
    
    read_matrix(m_a, m_size);
    read_matrix(m_b, m_size);

	printf("\nPrimeira matriz lida: \n");
    print_matrix(m_a, m_size);

	printf("\nSegunda matriz lida: \n");
    print_matrix(m_b, m_size);
	
	printf("\nResultado da multiplicação entre as matrizes: \n");
    int **m_result = matrix_multiply(m_size, m_a, m_b);
	print_matrix(m_result, m_size);

    free(m_a);
    free(m_b);
    return 0;
}
